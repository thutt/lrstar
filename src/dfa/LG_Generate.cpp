
/* Copyright 2018, 2023 Paul B Mann.  BSD License. */

#include "CM_Global.h"
#include "LG_Global.h"
#include "LG_CreateTables.h"

enum {
   ts_TermNumb,
   ts_Tm,
   ts_Tr,
   ts_Tc,
   ts_N_ELEMENTS
} type_sizes;

struct data_types_t {           /* Tm, Tr, Tc, term_numb */
   const char *type;            /* C type, string form. */
   int         n_elem;          /* Number of elements in array. */
};
static data_types_t data_types[ts_N_ELEMENTS];


static const char *
get_typestr(int *x, int n)
{
   int i, max = 0, min = 0;
   for (i = 0; i < n; i++)
   {
      if (x[i] > max) max = x[i];
      else if (x[i] < min) min = x[i];
   }
   if (min >= 0)
   {
      if      (max <=        127) return ("uchar"  ); // 1 byte
      else if (max <=        255) return ("uchar"  ); // 1 byte
      else if (max <=      32767) return ("ushort" ); // 2 bytes
      else if (max <=      65535) return ("ushort" ); // 2 bytes
      else if (max <= 2147483647) return ("uint"   ); // 4 bytes
      else                        return ("uint"   ); // 4 bytes
   }
   else if (max > -min)
   {
      if      (max <=        127) return ("char"   ); // 1 byte
      else if (max <=      32767) return ("short"  ); // 2 bytes
      else                        return ("int"    ); // 4 bytes
   }
   else
   {
      if      (min >=       -127) return ("char"   ); // 1 byte
      else if (min >=     -32767) return ("short"  ); // 2 bytes
      else                        return ("int"    ); // 4 bytes
   }
   return (""); // never gets here, avoid compiler error.
}



static void
declare_lexer(FILE *fp)
{
   static const char *template_decl = ("template<typename T_term_numb, "
                                       "typename T_Tm, "
                                       "typename T_Tr, "
                                       "typename T_Tc>");
   static const char *template_inst = ("templ_lrstar_lexer<T_term_numb, "
                                       "T_Tm, T_Tr, T_Tc>");

   fprintf(fp, ("%s\n"
                "const int %s::n_term_numb = %d;\n\n"
                ""), template_decl, template_inst, data_types[ts_TermNumb].n_elem);
   fprintf(fp, ("%s\n"
                "const int %s::n_Tm = %d;\n\n"
                ""), template_decl, template_inst, data_types[ts_Tm].n_elem);
   fprintf(fp, ("%s\n"
                "const int %s::n_Tr = %d;\n\n"
                ""), template_decl, template_inst, data_types[ts_Tr].n_elem);
   fprintf(fp, ("%s\n"
                "const int %s::n_Tc = %d;\n\n"
                ""), template_decl, template_inst, data_types[ts_Tc].n_elem);

   fprintf(fp, ("%s\n"
                "const T_term_numb *%s::term_numb = &term_numb[0];\n\n"
                ""), template_decl, template_inst);
   fprintf(fp, ("%s\n"
                "const T_Tm *%s::Tm = &Tm[0];\n\n"
                ""), template_decl, template_inst);
   fprintf(fp, ("%s\n"
                "const T_Tr *%s::Tr = &Tr[0];\n\n"
                ""), template_decl, template_inst);
   fprintf(fp, ("%s\n"
                "const T_Tc *%s::Tc = &Tc[0];\n\n"
                ""), template_decl, template_inst);

   fprintf(fp, ("%s\n"
                "Token %s::token;\n\n"), template_decl, template_inst);

   fprintf(fp, ("%s\n"
                "Token %s::lookahead;\n\n"), template_decl, template_inst);

   fprintf(fp, ("%s\n"
                "int %s::tab;\n\n"), template_decl, template_inst);

   fprintf(fp, ("%s\n"
                "int %s::linenumb;\n\n"), template_decl, template_inst);

   fprintf(fp, ("%s\n"
                "int %s::linenumb_printed;\n\n"), template_decl, template_inst);

   fprintf(fp, ("%s\n"
                "int %s::lookahead_linenumb;\n\n"), template_decl, template_inst);

   fprintf(fp, "template class templ_lrstar_lexer<%s, %s, %s, %s>;\n",
           data_types[ts_TermNumb].type,
           data_types[ts_Tr].type,
           data_types[ts_Tm].type,
           data_types[ts_Tc].type);
   fprintf(fp, "typedef templ_lrstar_lexer<%s, %s, %s, %s> lexer_t;\n",
           data_types[ts_TermNumb].type,
           data_types[ts_Tr].type,
           data_types[ts_Tm].type,
           data_types[ts_Tc].type);
}


void LG::GenerateLexerDefines ()
{
   FILE       *tables;
   FILE       *header;
   char        filename_hpp[PATH_MAX];
   char        filename_h[PATH_MAX];
   const char *lexer_class = "_LexerTables";


   strcpy (filename_h, gdn);
   strcat (filename_h, gfn);
   strcat (filename_h, lexer_class);
   strcat (filename_h, ".h");

   if (chmod (filename_h, S_IWRITE) == 0) // File can be written ?
   {
      if (unlink (filename_h) != 0) // Delete it?
      {
         if (++n_errors == 1) prt_log ("\n");
         prt_log ("Output file '%s' cannot be written!\n", filename_h);
         Quit();
      }
   }

   header = fopen (filename_h, "w");
   if (header == NULL)
   {
      if (++n_errors == 1) prt_log ("\n");
      prt_log ("Output file '%s' cannot be written!\n", filename_h);
      Quit();
   }
   prt_logonly ("Generating: %s\n", filename_h);

   fprintf (header, "\n");
   fprintf (header, "////////////////////////////////////////////////////////////////////////////////\n");
   fprintf (header, "//\n");
   fprintf (header, "//    %s (generated by %s %s)\n", filename_h, program, version);
   fprintf (header, "\n");

   fprintf (header, "      #pragma once\n\n");

   fprintf (header, "      #undef  DEBUG_LEXER\n\n");    // In case of multiple lexers.

   if (optn [LG_DEBUG]) fprintf (header, "      #define DEBUG_LEXER\n");

   fprintf (header, "\n/*\n");

   strcpy (filename_hpp, gdn);
   strcat (filename_hpp, gfn);
   strcat (filename_hpp, lexer_class);
   strcat (filename_hpp, ".hpp");

   if (chmod (filename_hpp, S_IWRITE) == 0) // File can be written ?
   {
      if (unlink (filename_hpp) != 0) // Delete it?
      {
         if (++n_errors == 1) prt_log ("\n");
         prt_log ("Output file '%s' cannot be written!\n", filename_hpp);
         Quit();
      }
   }

   tables = fopen (filename_hpp, "w");
   if (tables == NULL)
   {
      if (++n_errors == 1) prt_log ("\n");
      prt_log ("Output file '%s' cannot be written!\n", filename_hpp);
      Quit();
   }
   prt_logonly ("Generating: %s\n\n", filename_hpp);

   fprintf (tables, "\n");
   fprintf (tables, "////////////////////////////////////////////////////////////////////////////////////////////////////\n");
   fprintf (tables, "//\n");
   fprintf (tables, "//    %s (generated by %s %s)\n\n", filename_hpp, program, version);

   if (lrstar_windows) {
      fprintf (tables, "      #define uint   unsigned int\n");
      fprintf (tables, "      #define uchar  unsigned char\n");
      fprintf (tables, "      #define ushort unsigned short\n");
   }
   fprintf (tables, "      #define MAX    0x80000000\n\n");

   // T_matrix ...

   data_types[ts_Tm].type   = get_typestr (T_matrix, T_size);
   data_types[ts_Tm].n_elem = T_size;
   fprintf (header, "      static const %-6s Tm[%6d]        ; "
            "// Terminal transition matrix.\n",
            data_types[ts_Tm].type, T_size);
   fprintf (tables, "   // Terminal transition matrix ...\n");
   fprintf (tables, "      static const %s Tm[%d] = \n",
            data_types[ts_Tm].type, T_size);
   fprintf (tables, "      {");
   for (int i = 0; i < T_size; i++)
   {
      if (i % 20 == 0)
      {
         if (i > 0) fprintf (tables, ",");
         if (T_matrix[i] == INT_MAX)
            fprintf (tables, "\n      %5s", "  MAX");
         else fprintf (tables, "\n      %5d", T_matrix[i]);
      }
      else
      {
         if (T_matrix[i] == INT_MAX)
            fprintf (tables, ",%5s", "  MAX");
         else fprintf (tables, ",%5d", T_matrix[i]);
      }
   }
   fprintf (tables, "\n      };\n\n");

   // T_matrix row ...
   if (optn[LG_TABL_MEDIUM])
   {
      data_types[ts_Tr].type = get_typestr (T_row, tt_states);
      data_types[ts_Tr].n_elem = tt_states;
      fprintf (header, "      static const %-6s Tr[%6d]        ; "
               "// Terminal transition matrix row.\n",
               data_types[ts_Tr].type, tt_states);
      fprintf (tables, "   // Terminal transition matrix row ...\n");
      fprintf (tables, "      static const %s Tr[%d] = \n",
               data_types[ts_Tr].type, tt_states);
      fprintf (tables, "      {");
      for (int i = 0; i < tt_states; i++)
      {
         if (i % 20 == 0)
         {
            if (i > 0) fprintf (tables, ",");
            fprintf (tables, "\n      %5d", T_row[i]);
         }
         else fprintf (tables, ",%5d", T_row[i]);
      }
      fprintf (tables, "\n      };\n\n");
   }

   // T_matrix column ...
   if (optn[LG_TABL_MEDIUM])
   {
      data_types[ts_Tc].type = get_typestr (T_col, N_terms);
      data_types[ts_Tc].n_elem = N_terms;
      fprintf (header, "      static const %-6s Tc[%6d]        ; "
               "// Terminal transition matrix column.\n",
               data_types[ts_Tc].type, N_terms);
      fprintf (tables, "   // Terminal transition matrix column ...\n");
      fprintf (tables, "      static const %s Tc[%d] = \n",
               data_types[ts_Tc].type, N_terms);
      fprintf (tables, "      {");
      for (int i = 0; i < N_terms; i++)
      {
         if (i % 20 == 0)
         {
            if (i > 0) fprintf (tables, ",");
            fprintf (tables, "\n      %5d", T_col[i]);
         }
         else fprintf (tables, ",%5d", T_col[i]);
      }
      fprintf (tables, "\n      };\n\n");
   }

   // Terminal Numbers (one for for each state) ...
   if (optn[LG_TABL_MEDIUM])
   {
      data_types[ts_TermNumb].type = get_typestr (D_red, N_states);
      data_types[ts_TermNumb].n_elem = N_states;
      fprintf (header, "      static const %-6s term_numb[%6d] ; "
               "// Terminal number.\n",
               data_types[ts_TermNumb].type, N_states);
      fprintf (tables, "   // Terminal number ...\n");
      fprintf (tables, "      static const %s term_numb[%d] = \n",
               data_types[ts_TermNumb].type, N_states);
      fprintf (tables, "      {");
      for (int i = 0; i < N_states; i++)
      {
         if (i % 20 == 0)
         {
            if (i > 0) fprintf (tables, ",");
            fprintf (tables, "\n      %5d", D_red[i]);
         }
         else fprintf (tables, ",%5d", D_red[i]);
      }
      fprintf (tables, "\n      };\n\n");
   }

   fprintf (tables, "//\n");
   fprintf (tables, "////////////////////////////////////////////////////////////////////////////////////////////////////\n");
   fprintf (tables, "\n");

   declare_lexer(tables);

   fclose (tables);
   chmod (filename_hpp, S_IREAD); // Make output file read-only.

   fprintf (header, "*/\n\n");
   if (n_constants > 0)
   {
      int i;
      fprintf (header,
               "      enum terminal\n"
               "      {\n");
      for (i = 0; i < n_constants-1; i++)
      {
         fprintf (header, "         %s = %d,\n", Defcon_name[i], Defcon_value[i]);
      }
      fprintf (header, "         %s = %d\n", Defcon_name[i], Defcon_value[i]);
      fprintf (header,
               "      };\n\n");
   }

   fprintf (header, "//\n");
   fprintf (header, "////////////////////////////////////////////////////////////////////////////////\n");

   fclose (header);
   chmod (filename_h, S_IREAD); // Make output file read-only.
}

//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////
/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
