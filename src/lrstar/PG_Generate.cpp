/* Copyright 2018, 2023 Paul B Mann.  BSD License. */

#include <assert.h>

#include "lrstar_basic_defs.h"
#include "CM_Global.h"
#include "PG_Main.h"
#include "PG_CreateTables.h"

typedef void (*file_writer_fn_t)(FILE       *fp,
                                 const char *pathname,
                                 const char *grammar,
                                 const char *fname);


static const char *get_typestr(int *x, int n)
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
print_defines(FILE *fp)
{
   int nl = 1;

   fprintf (fp, "      #undef  GRAMMAR\n");          // In case of multiple parsers.
   fprintf (fp, "      #undef  PARSER\n");           // In case of multiple parsers.
   fprintf (fp, "      #undef  PARSER_TABLES\n");    // In case of multiple parsers.
   fprintf (fp, "      #undef  LEXER\n");            // In case of multiple parsers.
   fprintf (fp, "      #undef  ACTIONS\n");          // In case of multiple parsers.
   fprintf (fp, "      #undef  TERM_ACTIONS\n");     // In case of multiple parsers.
   fprintf (fp, "      #undef  NODE_ACTIONS\n");     // In case of multiple parsers.
   fprintf (fp, "      #undef  INSENSITIVE\n");      // In case of multiple parsers.
   fprintf (fp, "      #undef  LOOKAHEADS\n");       // In case of multiple parsers.
   fprintf (fp, "      #undef  DEBUG_PARSER\n");     // In case of multiple parsers.
   fprintf (fp, "      #undef  DEBUG_TRACE\n");      // In case of multiple parsers.
   fprintf (fp, "      #undef  MAKE_AST\n");         // In case of multiple parsers.
   fprintf (fp, "      #undef  EXPECTING\n");        // In case of multiple parsers.
//    fprintf (fp, "      #undef  ERRORUSED\n");        // In case of multiple parsers.
   fprintf (fp, "      #undef  REVERSABLE\n");       // In case of multiple parsers.
   fprintf (fp, "      #undef  SEMANTICS\n");        // In case of multiple parsers.
   fprintf (fp, "      #undef  ND_PARSING\n");       // In case of multiple parsers.
   fprintf (fp, "      #undef  ND_THREADS\n");       // In case of multiple parsers.

   if (PG_Main::n_ndstates > 0) nl = optn[PG_LOOKAHEADS];

   fprintf (fp, "\n      #define GRAMMAR      \"%s\"\n",           gfn);
   fprintf (fp, "      #define PARSER        %s_Parser\n",       gfn);
   fprintf (fp, "      #define PARSER_TABLES %s_ParserTables\n", gfn);
   fprintf (fp, "      #define LEXER         %s_Lexer\n",        gfn);
   if (PG_Main::N_tacts > 0 || PG_Main::N_nacts > 0) {
      fprintf (fp, "      #define ACTIONS       %s_Actions\n",      gfn);
   }
   if (PG_Main::N_tacts > 0) {
      fprintf (fp, "      #define TERM_ACTIONS  %s_TermActions\n",  gfn);
   }
   if (PG_Main::N_nacts > 0) {
      fprintf (fp, "      #define NODE_ACTIONS  %s_NodeActions\n",  gfn);
   }
   if (optn[PG_INSENSITIVE])                 fprintf (fp, "      #define INSENSITIVE\n");
   fprintf (fp, "      #define LOOKAHEADS  %3d\n", nl);
   if (optn[PG_DEBUG])                       fprintf (fp, "      #define DEBUG_PARSER\n");
   if (optn[PG_DEBUGTRACE])                  fprintf (fp, "      #define DEBUG_TRACE\n");
   if (optn[PG_ASTCONST] && PG_Main::N_nodes > 0) {
      fprintf (fp, "      #define MAKE_AST\n");
   }
   if (optn[PG_EXPECTING] || PG_Main::error_used > 0) {
      fprintf (fp, "      #define EXPECTING\n");
   }
//    if (error_used > 0)                       fprintf (fp, "      #define ERRORUSED\n");
   if (PG_Main::N_reverses > 0) {
      fprintf (fp, "      #define REVERSABLE\n");
   }
   if (PG_Main::N_semantics > 0) {
      fprintf (fp, "      #define SEMANTICS\n");
   }
   if (PG_Main::n_ndstates > 0)
   {
      fprintf (fp, "      #define ND_PARSING\n");
      fprintf (fp, "      #define ND_THREADS  %3d\n", PG_Main::nd_maxcount);
   }
}


void  PG_Main::GenerateParserTables ()
{
   int   i;
   int   count;
   const char* vartype;
   FILE* header;
   FILE* tables;
   const char* name  = "_ParserTables";
   char  filename_h  [PATH_MAX];
   char  filename_hpp[PATH_MAX];

   strcpy (filename_h, gdn);
   strcat (filename_h, gfn);
   strcat (filename_h, name);
   strcat (filename_h, ".h");
   if (chmod (filename_h, S_IWRITE) == 0) // File can be written ?
   {
      if (unlink (filename_h) != 0) // Delete it?
      {
         if (++n_errors == 1) prt_log ("\n");
         prt_log ("Output file '%s' cannot be written!\n\n", filename_h);
         Quit();
      }
   }
   header = fopen (filename_h, "w");
   if (header == NULL)
   {
      if (++n_errors == 1) prt_log("\n");
      prt_log("Output file '%s' cannot be written!\n\n", filename_h);
      Quit();
   }
   prt_logonly ("Generating: %s\n", filename_h);

   strcpy (filename_hpp, gdn);
   strcat (filename_hpp, gfn);
   strcat (filename_hpp, name);
   strcat (filename_hpp, ".hpp");
   if (chmod (filename_hpp, S_IWRITE) == 0) // File can be written ?
   {
      if (unlink (filename_hpp) != 0) // Delete it?
      {
         if (++n_errors == 1) prt_log ("\n");
         prt_log ("Output file '%s' cannot be written!\n\n", filename_hpp);
         Quit ();
      }
   }
   tables = fopen (filename_hpp, "w");
   if (tables == NULL)
   {
      if (++n_errors == 1) prt_log ("\n");
      prt_log ("Output file '%s' cannot be written!\n\n", filename_hpp);
      Quit ();
   }
   prt_logonly ("Generating: %s\n\n", filename_hpp);

   if (optn[PG_TERMACTIONS ] == 0) N_tacts = 0;
   if (optn[PG_NODEACTIONS ] == 0) N_nacts = 0;

   fprintf (header, "\n");
   fprintf (header, "////////////////////////////////////////////////////////////////////////////////\n");
   fprintf (header, "//\n");
   fprintf (header, "//    %s (generated by %s %s)\n", filename_h, program, version);
   fprintf (header, "\n");

   fprintf (header, "      #pragma once\n\n");

   fprintf (header, "\n");
   if (n_constants > 0)
   {
      int n = 0;
      fprintf (header,
               "      enum termcon\n"
               "      {\n");
      for (i = 0; i < n_constants; i++)
      {
         if (n++ > 0)
            fprintf (header, ",\n");
         fprintf (header, "         %s = %d", Defcon_name[i], Defcon_value[i]);
      }
      fprintf (header, "\n      };\n\n");
   }

   if (N_nodes > 0 && optn[PG_ASTCONST] > 0)
   {
      int n = 0;
      fprintf (header,
               "      enum nodecon\n"
               "      {\n");
      for (int i = 0; i < N_nodes; i++)
      {
         if (n++ > 0)
            fprintf (header, ",\n");
         fprintf (header, "         N_%s = %d", Node_start[i], i);
      }
      fprintf (header, "\n      };\n\n");
   }

   if (lrstar_windows) {
      assert(lrstar_windows);
      fprintf (header, "      #define uint   unsigned int\n");
      fprintf (header, "      #define uchar  unsigned char\n");
      fprintf (header, "      #define ushort unsigned short\n");
   }

   fprintf (header, "\n");
   fprintf (header, "      #define TOP_DOWN  0\n");
   fprintf (header, "      #define PASS_OVER 1\n");
   fprintf (header, "      #define BOTTOM_UP 2\n\n");

   fprintf (header, "      class %s%s\n", gfn, name);
   fprintf (header, "      {\n");
   fprintf (header, "         friend class %s_Parser;\n", gfn);

   fprintf (header, "         public:\n");
   fprintf (header, "         static const char *term_symb[%6d]; // Terminal symbols of the grammar.\n", N_terms);
   fprintf (header, "         static const char *head_symb[%6d]; // Nonterminal symbols of the grammar.\n", N_heads);
   if (N_tacts > 0)
      fprintf (header, "         static const char *tact_name[%6d]; // Terminal action names found in the grammar.\n", N_tacts);
   if (N_nodes > 0)
      fprintf (header, "         static const char *node_name[%6d]; // Node names found in the grammar.\n", N_nodes);
   if (N_strings > 0)
      fprintf (header, "         static const char *text_str [%6d]; // Text strings found in the grammar.\n", N_strings);

   nd_optimize ();

   fprintf (tables, "\n");
   fprintf (tables, "////////////////////////////////////////////////////////////////////////////////////////////////////\n");
   fprintf (tables, "//\n");
   fprintf (tables, "//    %s (generated by %s %s)\n\n", filename_hpp, program, version);

   fprintf (tables, "      #include \"lrstar_basic_defs.h\"\n");
   fprintf (tables, "      #include \"%s_ParserTables.h\"\n", gfn);
   fprintf (tables, "      #include \"%s_Actions.h\"\n", gfn);

   fprintf (tables, "\n");
   fprintf (tables, "      static int n_terms      =%5d; // Number of terminals.\n",          N_terms);
   fprintf (tables, "      static int n_heads      =%5d; // Number of nonterminals.\n",     N_heads);
   fprintf (tables, "      static int n_prods      =%5d; // Number of productions.\n",     N_prods);
   fprintf (tables, "      static int n_states     =%5d; // Number of states.\n",             N_states);
   fprintf (tables, "      static int accept_state =%5d; // Accept state.\n",              Accept_state);
   fprintf (tables, "      static int n_termactns  =%5d; // Number of terminal actions.\n", N_tacts);
   fprintf (tables, "      static int n_nodenames  =%5d; // Number of node names.\n",      N_nodes);
   fprintf (tables, "      static int n_nodeactns  =%5d; // Number of node actions.\n",     N_nacts);
   fprintf (tables, "      static int eof_symb     =%5d; // <eof> symbol number.\n",          eof_term);
   fprintf (tables, "      static int err_used     =%5d; // <error> used in grammar?\n\n",  error_used);

   // Terminal symbols ...
   fprintf (tables, "   // Terminal symbols of the grammar ...\n");
   fprintf (tables, "      const char* %s%s::term_symb[%d] = \n", gfn, name, N_terms);
   fprintf (tables, "      {\n");
   for (int i = 0; i < N_terms; i++)
   {
      fprintf (tables, "         \"%s\"", make_term (term_name[i]));
      if (i < N_terms-1) fprintf (tables, ",\n");
   }
   fprintf (tables, "\n      };\n\n");

   // Head symbols ...
   fprintf (tables, "   // Nonterminal symbols of the grammar ...\n");
   fprintf (tables, "      const char *%s%s::head_symb[%d] = \n", gfn, name, N_heads);
   fprintf (tables, "      {\n");
   for (int i = 0; i < N_heads; i++)
   {
      fprintf (tables, "         \"%s\"", head_name[i]);
      if (i < N_heads-1) fprintf (tables, ",\n");
   }
   fprintf (tables, "\n      };\n\n");

   if (N_tacts > 0)
   {
      // Terminal action names ...
      fprintf (tables, "   // Terninal action names found in the grammar ...\n");
      fprintf (tables, "      const char *%s%s::tact_name[%d] = \n", gfn, name, N_tacts);
      fprintf (tables, "      {\n");
      for (int i = 0; i < N_tacts; i++)
      {
         fprintf (tables, "         \"%s\"", Tact_start[i]);
         if (i < N_tacts -1) fprintf (tables, ",\n");
      }
      fprintf (tables, "\n      };\n\n");
   }

   if (N_nodes > 0)
   {
      // Node names ...
      fprintf (tables, "   // Node names found in the grammar ...\n");
      fprintf (tables, "      const char * %s%s::node_name[%d] = \n", gfn, name, N_nodes);
      fprintf (tables, "      {\n");
      for (int i = 0; i < N_nodes; i++)
      {
         fprintf (tables, "         \"%s\"", Node_start[i]);
         if (i < N_nodes-1) fprintf (tables, ",\n");
      }
      fprintf (tables, "\n      };\n\n");
   }

   if (N_strings > 0)
   {
      // Argument text strings ...
      fprintf (tables, "   // Text strings for any arguments ...\n");
      fprintf (tables, "      const char *%s%s::text_str[%d] = \n", gfn, name, N_strings);
      fprintf (tables, "      {\n");
      for (int i = 0; i < N_strings; i++)
      {
         fprintf (tables, "         %s", Str_start[i]);
         if (i < N_strings-1) fprintf (tables, ",\n");
      }
      fprintf (tables, "\n      };\n\n");
   }

   // Head numbers for the productions ...
   vartype = get_typestr (head_sym, N_prods);
   fprintf (header, "         static const %-6s head_numb[%6d]; // Head symbol number for a production.\n", vartype, N_prods);
   fprintf (tables, "   // Head symbol numbers for the productions ...\n");
   fprintf (tables, "      const %s %s%s::head_numb[%d] = \n", vartype, gfn, name, N_prods);
   fprintf (tables, "      {");
   for (int i = 0; i < N_prods; i++)
   {
      if (i % 20 == 0)
      {
         if (i > 0) fprintf (tables, ",");
         fprintf (tables, "\n      %5d", head_sym[i]);
      }
      else fprintf (tables, ",%5d", head_sym[i]);
   }
   fprintf (tables, "\n      };\n\n");

   // Index to first tail symbol for a production ...
   vartype = get_typestr (F_tail, N_prods+1);
   fprintf (header, "         static const %-6s f_tail   [%6d]; // First tail in a production.\n", vartype, N_prods + 1);
   fprintf (tables, "   // First tail symbol index into the tail list ...\n");
   fprintf (tables, "      const %s %s%s::f_tail[%d] = \n", vartype, gfn, name, N_prods+1);
   fprintf (tables, "      {");
   for (int i = 0; i < N_prods+1; i++)
   {
      if (i % 20 == 0)
      {
         if (i > 0) fprintf (tables, ",");
         fprintf (tables, "\n      %5d", F_tail[i]);
      }
      else fprintf (tables, ",%5d", F_tail[i]);
   }
   fprintf (tables, "\n      };\n\n");

   // Tail symbol numbers ...
   vartype = get_typestr (Tail, N_tails);
   fprintf (header, "         static const %-6s tail     [%6d]; // Tail symbol number.\n", vartype, N_tails);
   fprintf (tables, "   // Tail symbol numbers ...\n");
   fprintf (tables, "      const %s %s%s::tail[%d] = \n", vartype, gfn, name, N_tails);
   fprintf (tables, "      {");
   for (int i = 0; i < N_tails; i++)
   {
      if (i % 20 == 0)
      {
         if (i > 0) fprintf (tables, ",");
         fprintf (tables, "\n      %5d", Tail[i]);
      }
      else fprintf (tables, ",%5d", Tail[i]);
   }
   fprintf (tables, "\n      };\n\n");

   // Arguments for terminal actions ...
   if (N_tacts > 0)
   {
      int* Arga = new int[N_terms];
      for (int i = 0; i < N_terms; i++)
      {
         if (N_targ[i] > 0)
            Arga[i] = Arg_numb[F_targ[i]];
         else
            Arga[i] = -1;
      }
      vartype = get_typestr (Arga, N_terms);
      fprintf (header, "         static const %-6s arga     [%6d]; // Arguments for terminal actions.\n", vartype, N_terms);
      fprintf (tables, "   // Arguments for token actions ...\n");
      fprintf (tables, "      const %s %s%s::arga[%d] = \n", vartype, gfn, name, N_terms);
      fprintf (tables, "      {");
      for (int i = 0; i < N_terms; i++)
      {
         if (i % 20 == 0)
         {
            if (i > 0) fprintf (tables, ",");
            fprintf (tables, "\n      %5d", Arga[i]);
         }
         else fprintf (tables, ",%5d", Arga[i]);
      }
      fprintf (tables, "\n      };\n\n");
   }

   // First arguments for productions ...
   if (N_nodes > 0 || N_semantics > 0)
   {
      int* Argx = new int[N_prods];
      for (int i = 0; i < N_prods; i++)
      {
         if (N_parg[i] > 0)
            Argx[i] = Arg_numb[F_parg[i]] - 1;
         else
            Argx[i] = -1;
      }
      vartype = get_typestr (Argx, N_prods);
      fprintf (header, "         static %-6s argx     [%6d]; // First arguments for productions.\n", vartype, N_prods);
      fprintf (tables, "   // First arguments for productions ...\n");
      fprintf (tables, "      %s %s%s::argx[%d] = \n", vartype, gfn, name, N_prods);
      fprintf (tables, "      {");
      for (int i = 0; i < N_prods; i++)
      {
         if (i % 20 == 0)
         {
            if (i > 0) fprintf (tables, ",");
            fprintf (tables, "\n      %5d", Argx[i]);
         }
         else fprintf (tables, ",%5d", Argx[i]);
      }
      fprintf (tables, "\n      };\n\n");
   }

   // Second arguments for productions ...
   if (N_semantics > 0)
   {
      int* Argy = new int[N_prods];
      for (int i = 0; i < N_prods; i++)
      {
         if (N_parg[i] > 1)
            Argy[i] = Arg_numb[F_parg[i]+1];
         else
            Argy[i] = -1;
      }
      vartype = get_typestr (Argy, N_prods);
      fprintf (header, "         static %-6s argy     [%6d]; // Second arguments for productions.\n", vartype, N_prods);
      fprintf (tables, "   // Second arguments for productions ...\n");
      fprintf (tables, "      %s %s%s::argy[%d] = \n", vartype, gfn, name, N_prods);
      fprintf (tables, "      {");
      for (int i = 0; i < N_prods; i++)
      {
         if (i % 20 == 0)
         {
            if (i > 0) fprintf (tables, ",");
            fprintf (tables, "\n      %5d", Argy[i]);
         }
         else fprintf (tables, ",%5d", Argy[i]);
      }
      fprintf (tables, "\n      };\n\n");
   }


   fprintf(header, "\n");
   if (optn[PG_BOOLMATRIX] > 0)
   {
      // B_matrix ...
      fprintf (header, "         private:\n");
      fprintf (header, "         static const uchar  Bm[%6d]       ; // Boolean matrix.\n", B_size);
      fprintf (tables, "   // Boolean matrix ...\n");
      fprintf (tables, "      const uchar %s%s::Bm[%d] = \n", gfn, name, B_size);
      fprintf (tables, "      {");
      if (optn[PG_BOOLMATRIX] == 1) // char
      {
         for (int i = 0; i < B_size; i++)
         {
            int x = (uchar)B_matrix[i];
            if (i % 40 == 0)
            {
               if (i > 0) fprintf (tables, ",");
               fprintf (tables, "\n       %d", x);
            }
            else fprintf (tables, ", %d", x);
         }
      }
      if (optn[PG_BOOLMATRIX] == 2) // bits
      {
         for (int i = 0; i < B_size; i++)
         {
            int x = (uchar)B_matrix[i];
            if (i % 20 == 0)
            {
               if (i > 0) fprintf (tables, ",");
               fprintf(tables, "\n      %5d", x);
            }
            else fprintf(tables, ",%5d", x);
         }
      }
      fprintf (tables, "\n      };\n\n");

      // B_matrix row ...
      vartype = get_typestr (B_row, N_states);
      fprintf (header, "         static const %-6s Br[%6d]       ; // Boolean matrix row.\n", vartype, N_states);
      fprintf (tables, "   // Boolean matrix row (for state)...\n");
      fprintf (tables, "      const %s %s%s::Br[%d] = \n", vartype, gfn, name, N_states);
      fprintf (tables, "      {");
      for (int i = 0; i < N_states; i++)
      {
         if (i % 20 == 0)
         {
            if (i > 0) fprintf(tables, ",");
            fprintf(tables, "\n      %5d", B_row[i]);
         }
         else fprintf(tables, ",%5d", B_row[i]);
      }
      fprintf(tables, "\n      };\n\n");

      // B_matrix column ...
      vartype = get_typestr (B_col, N_terms);
      fprintf (header, "         static const %-6s Bc[%6d]       ; // Boolean matrix column.\n", vartype, N_terms);
      fprintf (tables, "   // Boolean matrix column (displacement) ...\n");
      fprintf (tables, "      const %s %s%s::Bc[%d] = \n", vartype, gfn, name, N_terms);
      fprintf (tables, "      {");
      for (int i = 0; i < N_terms; i++)
      {
         if (i % 20 == 0)
         {
            if (i > 0) fprintf(tables, ",");
            fprintf(tables, "\n      %5d", B_col[i]);
         }
         else fprintf(tables, ",%5d", B_col[i]);
      }
      fprintf(tables, "\n      };\n\n");

      if (optn[PG_BOOLMATRIX] > 1)
      {
         // B_matrix mask ...
         fprintf (header, "         static const uchar Bf[%6d]       ; // Boolean matrix filter/mask.\n", N_terms);
         fprintf (tables, "   // Boolean matrix filter/mask value ...\n");
         fprintf (tables, "      const uchar %s%s::Bf[%d] = \n", gfn, name, N_terms);
         fprintf (tables, "      {");
         for (int i = 0; i < N_terms; i++)
         {
            if (i % 20 == 0)
            {
               if (i > 0) fprintf(tables, ",");
               fprintf(tables, "\n      %5d", B_mask[i]);
            }
            else fprintf(tables, ",%5d", B_mask[i]);
         }
         fprintf(tables, "\n      };\n\n");
      }
   }

   // T_matrix ...
   vartype = get_typestr (T_matrix, T_size);
   fprintf (header, "         static const %-6s Tm[%6d]       ; // Terminal transition matrix.\n", vartype, T_size);
   fprintf (tables, "   // Terminal transition matrix ...\n");
   fprintf (tables, "      const %s %s%s::Tm[%d] = \n", vartype, gfn, name, T_size);
   fprintf (tables, "      {");
   for (int i = 0; i < T_size; i++)
   {
      if (i % 20 == 0)
      {
         if (i > 0) fprintf (tables, ",");
         fprintf (tables, "\n      %5d", T_matrix[i]);
      }
      else fprintf (tables, ",%5d", T_matrix[i]);
   }
   fprintf (tables, "\n      };\n\n");

   // T_matrix row ...
   vartype = get_typestr (T_row, tt_states);
   fprintf (header, "         static const %-6s Tr[%6d]       ; // Terminal transition matrix row.\n", vartype, tt_states);
   fprintf (tables, "   // Terminal transition matrix row ...\n");
   fprintf (tables, "      const %s %s%s::Tr[%d] = \n", vartype, gfn, name, tt_states);
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

   // T_matrix column ...
   vartype = get_typestr (T_col, N_terms);
   fprintf (header, "         static const %-6s Tc[%6d]       ; // Terminal transition matrix column.\n", vartype, N_terms);
   fprintf (tables, "   // Terminal transition matrix column ...\n");
   fprintf (tables, "      const %s %s%s::Tc[%d] = \n", vartype, gfn, name, N_terms);
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

   // N_matrix ...
   vartype = get_typestr (N_matrix, N_size);
   fprintf (header, "         static const %-6s Nm[%6d]       ; // Nonterminal transition matrix.\n", vartype, N_size);
   fprintf (tables, "   // Nonterminal transition matrix ...\n");
   fprintf (tables, "      const %s %s%s::Nm[%d] = \n", vartype, gfn, name, N_size);
   fprintf (tables, "      {");
   for (int i = 0; i < N_size; i++)
   {
      if (i % 20 == 0)
      {
         if (i > 0) fprintf (tables, ",");
         fprintf (tables, "\n      %5d", N_matrix[i]);
      }
      else fprintf (tables, ",%5d", N_matrix[i]);
   }
   fprintf (tables, "\n      };\n\n");

   // N_matrix row ...
   vartype = get_typestr (N_row, ntt_states);
   fprintf (header, "         static const %-6s Nr[%6d]       ; // Nonterminal transition matrix row.\n", vartype, ntt_states);
   fprintf (tables, "   // Nonterminal transition matrix row ...\n");
   fprintf (tables, "      const %s %s%s::Nr[%d] = \n", vartype, gfn, name, ntt_states);
   fprintf (tables, "      {");
   for (int i = 0; i < ntt_states; i++)
   {
      if (i % 20 == 0)
      {
         if (i > 0) fprintf (tables, ",");
         fprintf (tables, "\n      %5d", N_row[i]);
      }
      else fprintf (tables, ",%5d", N_row[i]);
   }
   fprintf (tables, "\n      };\n\n");

   // N_matrix column ...
   vartype = get_typestr (N_col, N_prods);
   fprintf (header, "         static const %-6s Nc[%6d]       ; // Nonterminal transition matrix column.\n", vartype, N_prods);
   fprintf (tables, "   // Nonterminal transition matrix column ...\n");
   fprintf (tables, "      const %s %s%s::Nc[%d] = \n", vartype, gfn, name, N_prods);
   fprintf (tables, "      {");
   for (int i = 0; i < N_prods; i++)
   {
      if (i % 20 == 0)
      {
         if (i > 0) fprintf (tables, ",");
         fprintf (tables, "\n      %5d", N_col[i]);
      }
      else fprintf (tables, ",%5d", N_col[i]);
   }
   fprintf (tables, "\n      };\n\n");

   // R_matrix ...
   vartype = get_typestr (R_matrix, R_size);
   fprintf (header, "         static const %-6s Rm[%6d]       ; // Reduction matrix.\n", vartype, R_size);
   fprintf (tables, "   // Reduction matrix ...\n");
   fprintf (tables, "      const %s %s%s::Rm[%d] = \n", vartype, gfn, name, R_size);
   fprintf (tables, "      {");
   for (int i = 0; i < R_size; i++)
   {
      if (i % 20 == 0)
      {
         if (i > 0) fprintf (tables, ",");
         fprintf (tables, "\n      %5d", R_matrix[i]);
      }
      else fprintf (tables, ",%5d", R_matrix[i]);
   }
   fprintf (tables, "\n      };\n\n");

   // R_matrix row ...
   vartype = get_typestr (R_row, N_states);
   fprintf (header, "         static const %-6s Rr[%6d]       ; // Reduction matrix row.\n", vartype, N_states);
   fprintf (tables, "   // Reduction matrix row ...\n");
   fprintf (tables, "      const %s %s%s::Rr[%d] = \n", vartype, gfn, name, N_states);
   fprintf (tables, "      {");
   for (int i = 0; i < N_states; i++)
   {
      if (i % 20 == 0)
      {
         if (i > 0) fprintf (tables, ",");
         fprintf (tables, "\n      %5d", R_row[i]);
      }
      else fprintf (tables, ",%5d", R_row[i]);
   }
   fprintf (tables, "\n      };\n\n");

   // R_matrix column ...
   vartype = get_typestr (R_col, N_terms);
   fprintf (header, "         static const %-6s Rc[%6d]       ; // Reduction matrix column.\n", vartype, N_terms);
   fprintf (tables, "   // Reduction matrix column ...\n");
   fprintf (tables, "      const %s %s%s::Rc[%d] = \n", vartype, gfn, name, N_terms);
   fprintf (tables, "      {");
   for (int i = 0; i < N_terms; i++)
   {
      if (i % 20 == 0)
      {
         if (i > 0) fprintf (tables, ",");
         fprintf (tables, "\n      %5d", R_col[i]);
      }
      else fprintf (tables, ",%5d", R_col[i]);
   }
   fprintf (tables, "\n      };\n\n");

   // Production length - 1 ...
   vartype = get_typestr (prod_len, N_prods);
   fprintf (header, "         static const %-6s PL[%6d]       ; // Production length minus one.\n", vartype, N_prods);
   fprintf (tables, "   // Production lengths (minus one) ...\n");
   fprintf (tables, "      const %s %s%s::PL[%d] = \n", vartype, gfn, name, N_prods);
   fprintf (tables, "      {");
   for (int i = 0; i < N_prods; i++)
   {
      if (i % 20 == 0)
      {
         if (i > 0) fprintf (tables, ",");
         fprintf (tables, "\n      %5d", prod_len[i]);
      }
      else fprintf (tables, ",%5d", prod_len[i]);
   }
   fprintf (tables, "\n      };\n\n");

   int newline = 0;
   if (n_ndstates > 0)
   {
      newline = 1;
      fprintf (header, "\n");
      // Nondeterministic Items (terminals) in a state ...
      count = N_states + 1;
      vartype = get_typestr (nd_item, count);
      fprintf (header, "         static const %-6s nd_fterm  [%5d]; // ND: first terminal in the list.\n", vartype, count);
      fprintf (tables, "   // Nondeterministic first terminal in the list ...\n");
      fprintf (tables, "      const %s %s%s::nd_fterm[%d] = \n", vartype, gfn, name, count);
      fprintf (tables, "      {");
      for (int i = 0; i < count; i++)
      {
         if (i % 20 == 0)
         {
            if (i > 0) fprintf (tables, ",");
            fprintf (tables, "\n      %5d", nd_item[i]);
         }
         else fprintf (tables, ",%5d", nd_item[i]);
      }
      fprintf (tables, "\n      };\n\n");

      // Nondeterministic Terminal List ...
      count = n_ndterms;
      vartype = get_typestr (nd_term, count);
      fprintf (header, "         static const %-6s nd_term   [%5d]; // ND: terminal list. \n", vartype, count);
      fprintf (tables, "   // Nondeterministic terminal list ...\n");
      fprintf (tables, "      const %s %s%s::nd_term[%d] = \n", vartype, gfn, name, count);
      fprintf (tables, "      {");
      for (int i = 0; i < count; i++)
      {
         if (i % 20 == 0)
         {
            if (i > 0) fprintf (tables, ",");
            fprintf (tables, "\n      %5d", nd_term[i]);
         }
         else fprintf (tables, ",%5d", nd_term[i]);
      }
      fprintf (tables, "\n      };\n\n");

      // Nondeterministic Start of a terminal's actions for state ...
      count = n_ndterms + 1;
      vartype = get_typestr (nd_start, count);
      fprintf (header, "         static const %-6s nd_faction[%5d]; // ND: first action in the list.\n", vartype, count);
      fprintf (tables, "   // Nondeterministic first action in the list ...\n");
      count = n_ndterms+1;
      vartype = get_typestr (nd_start, count);
      fprintf (tables, "      const %s %s%s::nd_faction[%d] = \n", vartype, gfn, name, count);
      fprintf (tables, "      {");
      for (int i = 0; i < count; i++)
      {
         if (i % 20 == 0)
         {
            if (i > 0) fprintf (tables, ",");
            fprintf (tables, "\n      %5d", nd_start[i]);
         }
         else fprintf (tables, ",%5d", nd_start[i]);
      }
      fprintf (tables, "\n      };\n\n");

      // Nondeterministic Action ...
      count = n_nditems;
      vartype = get_typestr (nd_action, count);
      fprintf (header, "         static const %-6s nd_action [%5d]; // ND: action list.\n", vartype, count);
      fprintf (tables, "   // Nondeterministic actions list ...\n");
      fprintf (tables, "      const %s %s%s::nd_action[%d] = \n", vartype, gfn, name, count);
      fprintf (tables, "      {");
      for (int i = 0; i < count; i++)
      {
         if (i % 20 == 0)
         {
            if (i > 0) fprintf (tables, ",");
            fprintf (tables, "\n      %5d", nd_action[i]);
         }
         else fprintf (tables, ",%5d", nd_action[i]);
      }
      fprintf (tables, "\n      };\n");
   }

   newline = 0;
   if (N_tacts > 0) // Number of terminal actions.
   {
      newline = 1;
      fprintf (header, "\n");
      // Token Action numbers ...
      vartype = get_typestr (Tact_numb, N_terms);
      fprintf (header, "         static const %-6s tact_numb[%6d]; // Terminal action numbers.\n", vartype, N_terms);
      fprintf (tables, "   // Terminal action number ...\n");
      fprintf (tables, "      const %s %s%s::tact_numb[%d] = \n", vartype, gfn, name, N_terms);
      fprintf (tables, "      {");
      for (int i = 0; i < N_terms; i++)
      {
         if (i % 20 == 0)
         {
            if (i > 0) fprintf (tables, ",");
            fprintf (tables, "\n      %5d", Tact_numb[i]);
         }
         else fprintf (tables, ",%5d", Tact_numb[i]);
      }
      fprintf (tables, "\n      };\n\n");
   }

   if (optn[PG_ASTCONST] > 0 && N_nodes > 0)
   {
      if (newline == 0) { fprintf (header, "\n"); newline = 1; }
      // Node Number for each production ...
      vartype = get_typestr (Node_numb, N_prods);
      fprintf (header, "         static const %-6s node_numb[%6d]; // Node numbers for the productions.\n", vartype, N_prods);
      fprintf (tables, "   // Node number for each production ...\n");
      fprintf (tables, "      const %s %s%s::node_numb[%d] = \n", vartype, gfn, name, N_prods);
      fprintf (tables, "      {");
      for (int i = 0; i < N_prods; i++)
      {
         if (i % 20 == 0)
         {
            if (i > 0) fprintf (tables, ",");
            fprintf (tables, "\n      %5d", Node_numb[i]);
         }
         else fprintf (tables, ",%5d", Node_numb[i]);
      }
      fprintf (tables, "\n      };\n\n");

      if (N_nacts > 0) // Number of node actions
      {
         // Node Action numbers ...
         vartype = get_typestr (Nact_numb, N_prods);
         fprintf (header, "         static const %-6s nact_numb[%6d]; // Node action numbers for the productions.\n", vartype, N_prods);
         fprintf (tables, "   // Node action numbers ...\n");
         fprintf (tables, "      const %s %s%s::nact_numb[%d] = \n", vartype, gfn, name, N_prods);
         fprintf (tables, "      {");
         for (int i = 0; i < N_prods; i++)
         {
            if (i % 20 == 0)
            {
               if (i > 0) fprintf (tables, ",");
               fprintf (tables, "\n      %5d", Nact_numb[i]);
            }
            else fprintf (tables, ",%5d", Nact_numb[i]);
         }
         fprintf (tables, "\n      };\n\n");
      }

      if (N_reverses > 0)
      {
         // Reverse the order of nodes (for a production/rule) ...
         fprintf (header, "         static const uchar  reverse  [%6d]; // Reverse the child nodes.\n", N_prods);
         fprintf (tables, "   // Reverse the order of nodes ...\n");
         fprintf (tables, "      const uchar %s%s::reverse[%d] = \n", gfn, name, N_prods);
         fprintf (tables, "      {");
         for (int i = 0; i < N_prods; i++)
         {
            if (i % 20 == 0)
            {
               if (i > 0) fprintf (tables, ",");
               fprintf (tables, "\n      %5d", Reverse[i]);
            }
            else fprintf (tables, ",%5d", Reverse[i]);
         }
         fprintf (tables, "\n      };\n\n");
      }
   }

   newline = 0;
   if (N_tacts > 0 || N_nacts > 0) // Number of terminal actions.
   {
      if (newline <= 0) { fprintf (header, "\n"); newline = 1; }
      // Init Actions ...
      fprintf (header, "         static void   (*init_func[%5d]) ()       ; // Init action function pointers.\n", 2);
      fprintf (tables, "   // Init action function pointers ...\n");
      fprintf (tables, "      void (*%s%s::init_func[%d]) () =\n", gfn, name, 2);
      fprintf (tables, "      {\n");
      fprintf (tables, "         %s_Actions::init_actions,\n", gfn);
      fprintf (tables, "         %s_Actions::term_actions", gfn);
      fprintf (tables, "\n      };\n\n");
   }

   if (N_tacts > 0) // Number of terminal actions.
   {
      if (newline <= 0) { fprintf (header, "\n"); newline = 1; }
      // Token Actions ...
      fprintf (header, "         static int    (*tact_func[%5d]) (int& t) ; // Terminal action function pointers.\n", N_tacts);
      fprintf (tables, "   // Terminal action function pointers ...\n");
      fprintf (tables, "      int (*%s%s::tact_func[%d]) (int& t) =\n", gfn, name, N_tacts);
      fprintf (tables, "      {\n");
      for (int t = 0; t < N_tacts; t++)
      {
         if (t > 0) fprintf (tables, ",\n");
         fprintf (tables, "         %s_TermActions::%s", gfn, Tact_start[t]);
      }
      fprintf (tables, "\n      };\n\n");
   }

   if (N_nacts > 0) // Number of node actions
   {
      if (newline <= 0) { fprintf (header, "\n"); newline = 1; }
      // Node Actions ...
      fprintf (header, "         static int    (*nact_func[%5d]) (void* v); // Node action function pointers.\n", N_nacts);
      fprintf (tables, "   // Node action function pointers ...\n");
      fprintf (tables, "      int (*%s%s::nact_func[%d]) (void* v) = \n", gfn, name, N_nacts);
      fprintf (tables, "      {\n");
      for (int n = 0; n < N_nacts; n++)
      {
         if (n > 0) fprintf (tables, ",\n");
         if (strcmp (Nact_start[n], "NULL") == 0)
            fprintf (tables, "         0");
         else
            fprintf (tables, "         %s_NodeActions::%s",  gfn, Nact_start[n]);
      }
      fprintf (tables, "\n      };\n\n");
   }

   fprintf (tables, "//\n");
   fprintf (tables, "////////////////////////////////////////////////////////////////////////////////////////////////////\n");
   fprintf (tables, "\n");
   fclose  (tables);
   chmod   (filename_hpp, S_IREAD); // Make output file read-only.

   fprintf (header, "      };\n\n");

   fprintf (header, "//\n");
   fprintf (header, "////////////////////////////////////////////////////////////////////////////////\n");
   fprintf (header, "\n");
   fclose  (header);
   chmod   (filename_h, S_IREAD); // Make output file read-only.
};


void actions_header_fn(FILE       *fp,
                       const char *pathname,
                       const char *grammar,
                       const char *fname)
{
   fprintf (fp, "\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "\n");
   fprintf (fp, "#pragma once\n");
   fprintf (fp, "\n");
   fprintf (fp, "#include \"%s_Parser.h\"\n", grammar);
   fprintf (fp, "\n");
   fprintf (fp, "#ifdef ACTIONS\n");
   fprintf (fp, "\n");
   fprintf (fp, "      class ACTIONS : public PARSER\n");
   fprintf (fp, "      {\n");
   fprintf (fp, "         public:\n");
   fprintf (fp, "         static void init_actions ();\n");
   fprintf (fp, "         static void term_actions ();\n");
   fprintf (fp, "      };\n");
   fprintf (fp, "\n");
   fprintf (fp, "#endif\n");
   fprintf (fp, "#ifdef TERM_ACTIONS\n");
   fprintf (fp, "\n");
   fprintf (fp, "      class TERM_ACTIONS : public ACTIONS\n");
   fprintf (fp, "      {\n");
   fprintf (fp, "         public:\n");
   fprintf (fp, "         static int  error     (int& t);\n");
   fprintf (fp, "         static int  lookup (int& t);\n");
   fprintf (fp, "      };\n");
   fprintf (fp, "\n");
   fprintf (fp, "#endif\n");
   fprintf (fp, "#ifdef NODE_ACTIONS\n");
   fprintf (fp, "\n");
   fprintf (fp, "      class NODE_ACTIONS : public ACTIONS\n");
   fprintf (fp, "      {\n");
   fprintf (fp, "         public:\n");
   fprintf (fp, "      };\n");
   fprintf (fp, "\n");
   fprintf (fp, "#endif\n");
   fprintf (fp, "\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n\n");
}


static void parsertables_header_fn(FILE       *fp,
                                   const char *pathname,
                                   const char *grammar,
                                   const char *fname)
{
   fprintf (fp, "\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "\n");
   fprintf (fp, "#include \"lrstar_basic_defs.h\"\n");
   print_defines(fp);
   fprintf (fp, "#include \"%s_ParserTables.h\"\n", grammar);
   if (lrstar_linux) {
      fprintf (fp, ("#include \"lrstar_lexer.h\"\n"
                    "#include \"lrstar_parser.h\"\n"));
   } else {
      assert(lrstar_windows);
      fprintf (fp, "#include \"../../code/lexer.h\"\n");
      fprintf (fp, "#include \"../../code/parser.h\"\n");
   }
   fprintf (fp, "\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n\n");
}


static void actions_cpp_fn(FILE       *fp,
                           const char *pathname,
                           const char *grammar,
                           const char *fname)
{
   fprintf (fp, "\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "\n");
   fprintf (fp, ("#include \"lrstar_basic_defs.h\"\n"
                 "#include \"%s_Actions.h\"\n"), grammar);
   if (lrstar_linux) {
      fprintf (fp, "#include \"lrstar_main.h\"\n");
   } else {
      assert(lrstar_windows);
      fprintf (fp, "#include \"../../code/main.h\"\n");
   }
   fprintf (fp, "\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n");
   fprintf (fp, "\n");
   fprintf (fp, "#ifdef ACTIONS\n");
   fprintf (fp, "\n");
   fprintf (fp, "void  ACTIONS::init_actions ()\n");
   fprintf (fp, "{\n");
   fprintf (fp, "      /* Initialization code goes here */\n");
   fprintf (fp, "}\n");
   fprintf (fp, "\n");
   fprintf (fp, "void  ACTIONS::term_actions ()\n");
   fprintf (fp, "{\n");
   fprintf (fp, "      /* Termination code goes here */\n");
   fprintf (fp, "}\n");
   fprintf (fp, "\n");
   fprintf (fp, "#endif\n");
   fprintf (fp, "\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n");
   fprintf (fp, "\n");
   fprintf (fp, "#ifdef TERM_ACTIONS\n");
   fprintf (fp, "\n");
   fprintf (fp, "int   TERM_ACTIONS::error (int& t)\n");
   fprintf (fp, "{\n");
   fprintf (fp, "      if (token.end == token.start)        // Illegal character?\n");
   fprintf (fp, "      {\n");
   fprintf (fp, "         token.end++;\n");
   fprintf (fp, "      }\n");
   fprintf (fp, "      return 0;\n");
   fprintf (fp, "}\n");
   fprintf (fp, "\n");
   fprintf (fp, "int   TERM_ACTIONS::lookup (int& t)             // Lookup in symbol table.\n");
   fprintf (fp, "{\n");
   fprintf (fp, "      int sti;\n");
   fprintf (fp, "      #ifdef ND_PARSING\n");
   fprintf (fp, "      if (lookahead.start > 0)             // In lookahead mode?\n");
   fprintf (fp, "      {\n");
   fprintf (fp, "         sti = add_symbol (t, lookahead.start, lookahead.end);\n");
   fprintf (fp, "      }\n");
   fprintf (fp, "      else                                 // Regular mode of parsing.\n");
   fprintf (fp, "      #endif\n");
   fprintf (fp, "      {\n");
   fprintf (fp, "         sti = add_symbol (t, token.start, token.end);\n");
   fprintf (fp, "      }\n");
   fprintf (fp, "      #ifdef SEMANTICS\n");
   fprintf (fp, "      t = symbol[sti].term;                // Redefine terminal number?\n");
   fprintf (fp, "      #endif\n");
   fprintf (fp, "    return sti;\n");                       // Return symbol-table index.\n");
   fprintf (fp, "}\n");
   fprintf (fp, "\n");
   fprintf (fp, "#endif\n");
   fprintf (fp, "\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n");
   fprintf (fp, "\n");
   fprintf (fp, "#ifdef NODE_ACTIONS\n");
   fprintf (fp, "\n");
   fprintf (fp, "\n");
   fprintf (fp, "\n");
   fprintf (fp, "#endif\n");
   fprintf (fp, "\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n");
   fprintf (fp, "\n");
}


static void lexer_cpp_fn(FILE       *fp,
                         const char *pathname,
                         const char *grammar,
                         const char *fname)
{
   fprintf (fp, "\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "\n");

   fprintf (fp, ("#include \"lrstar_basic_defs.h\"\n"
                 "#include \"%s_LexerTables.h\"\n"
                 "#include \"%s_LexerTables.hpp\"\n"), grammar, grammar);
   if (lrstar_linux) {
      fprintf (fp, ("#include \"lrstar_lexer.h\"\n"
                    "#include \"lrstar_lexer.cpp\"\n"));
   } else {
      assert(lrstar_windows);
      fprintf (fp, "#include \"../../code/lexer.h\"\n");
      fprintf (fp, "#include \"../../code/lexer.cpp\"\n");
   }
   fprintf (fp, "\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n\n");
}


static void main_cpp_fn(FILE       *fp,
                        const char *pathname,
                        const char *grammar,
                        const char *fname)
{
   fprintf (fp, "\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "\n");
   fprintf (fp, ("#include \"lrstar_basic_defs.h\"\n"
                 "#include \"%s_Parser.h\"\n"), grammar);
   if (lrstar_linux) {
      fprintf (fp, "#include \"lrstar_main.cpp\"\n");
   } else {
      assert(lrstar_windows);
      fprintf (fp, "#include \"../../code/main.cpp\"\n");
   }
   fprintf (fp, "\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n\n");
}


static void parser_cpp_fn(FILE       *fp,
                          const char *pathname,
                          const char *grammar,
                          const char *fname)
{
   fprintf (fp, "\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "\n");
   fprintf (fp, ("#include \"lrstar_basic_defs.h\"\n"
                 "#include \"%s_Parser.h\"\n"
                 "#include \"%s_ParserTables.hpp\"\n"), grammar, grammar);
   if (lrstar_linux) {
      fprintf (fp, "#include \"lrstar_parser.cpp\"\n");
   } else {
      assert(lrstar_windows);
      fprintf (fp, "#include \"../../code/parser.cpp\"\n");
   }
   fprintf (fp, "\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n\n");
}


static void make_bat_fn(FILE       *fp,
                        const char *pathname,
                        const char *grammar,
                        const char *fname)
{
   // TODO: need grammar name to be passed, too
   fprintf (fp, "rem  This make.bat must be in the same directory as the Visual Studio project files,\n");
   fprintf (fp, "rem  or else the error messages will not have the correct directory name preceeding\n");
   fprintf (fp, "rem  the file name, and clicking on the error messages will not work.\n");
   fprintf (fp, "\n");
   fprintf (fp, "@echo off\n");
   fprintf (fp, "prompt $g$s\n");
   fprintf (fp, "\n");
   fprintf (fp, "..\\..\\bin\\lrstar %s d dt\n", grammar);
   fprintf (fp, "..\\..\\bin\\dfa    %s d\n\n", grammar);
}


static void makefile_fn(FILE       *fp,
                        const char *pathname,
                        const char *grammar,
                        const char *fname)
{
   static const char *make = ("# Build '%s' parser.\n" /* grammar */
                              "\n\n"
                              "CC	:=\t\t\t\\\n"
                              "\tg++\n"
                              "\n\n"
                              "INCLUDES\t:=\t\t\t\\\n"
                              "\t$(LRSTAR_INSTALL_ROOT)/include\n"
                              "\n\n"
                              "DEFINES\t:=\t\t\t\\\n"
                              "\tLRSTAR_LINUX\n"
                              "\n\n"
                              "ERROR_FORMAT\t:=\t\t\t\\\n"
                              "\t-fdiagnostics-color=never\t\t\t\\\n"
                              "\t-fno-diagnostics-show-caret\t\t\t\\\n"
                              "\n\n"
                              "BUILD_TYPE\t:=\t\\\n"
                              "\t$(if $(LRSTAR_BUILD_TYPE),"
                              "$(if $(filter debug,$(LRSTAR_BUILD_TYPE)),"
                              "DEBUG,RELEASE),RELEASE)\n"
                              "\n\n"
                              "CXXFLAGS\t:=\t\t\t\\\n"
                              "\t$(ERROR_FORMAT)\t\t\t\\\n"
                              "\t$(addprefix -I,$(INCLUDES))\t\t\t\\\n"
                              "\t$(addprefix -D,LRSTAR_$(BUILD_TYPE) $(DEFINES))\t\t\t\\\n"
                              "\n\n"
                              "SOURCE\t:=\t\t\t\\\n"
                              "\t%s_Actions.cpp\t\t\t\\\n" /* grammar */
                              "\t%s_Lexer.cpp\t\t\t\\\n"   /* grammar */
                              "\t%s_Main.cpp\t\t\t\\\n"    /* grammar */
                              "\t%s_Parser.cpp\n"          /* grammar */
                              "\n\n"
                              "OBJS\t:= $\t$(SOURCE:.cpp=.o)\n"
                              "\n\n"
                              "%s:\t$(OBJS)\n"          /* grammar */
                              "\t$(CC) -o $@ $(OBJS);\n"
                              "\n\n"
                              "clean:\n"
                              "\trm $(SOURCE) $(OBJS) %s;"); /* grammar */
   fprintf(fp, make, grammar, grammar, grammar,
           grammar, grammar, grammar, grammar);
}


static void write_file(const char       *gdn,
                       const char       *grammar,
                       const char       *fname,
                       const char       *suffix,
                       bool              overwrite,
                       file_writer_fn_t  fn)
{
   char         pathname[PATH_MAX];
   FILE        *fp;
   int          stat_res;
   struct stat  statbuf;
   bool         exists;

   strcpy(pathname, gdn);

   /* If a filename is provided, it overrides the gammar + suffix in
    * the filename.
    */
   if (fname != NULL) {
      strcat(pathname, fname);
   } else {
      strcat(pathname, grammar);
      strcat(pathname, suffix);
   }

   stat_res = stat(pathname, &statbuf);
   exists   = stat_res != -1;

   if (!exists || overwrite) {
      fp = fopen(pathname, "w");

      if (fp != NULL) {
         prt_logonly ("Generating: %s\n", pathname);

         fn(fp, pathname, grammar, fname);
         fclose(fp);
      } else {
         if (++n_errors == 1) {
            prt_log("\n");
         }
         prt_log("Output file '%s' cannot be written!\n\n", pathname);
         Quit();
      }
   }
}


void  PG_Main::GenerateOtherFiles ()
{
   write_file(gdn, gfn, NULL, "_Actions.h", false, actions_header_fn);
   write_file(gdn, gfn, NULL, "_Parser.h", true, parsertables_header_fn);
   write_file(gdn, gfn, NULL, "_Actions.cpp", false, actions_cpp_fn);
   write_file(gdn, gfn, NULL, "_Lexer.cpp", true, lexer_cpp_fn);
   write_file(gdn, gfn, NULL, "_Main.cpp", true, main_cpp_fn);
   write_file(gdn, gfn, NULL, "_Parser.cpp", true, parser_cpp_fn);
   if (lrstar_linux) {
      write_file(gdn, gfn,  "Makefile", "", true, makefile_fn);
   } else {
      assert(lrstar_windows);
      write_file(gdn, gfn, "make.bat", "", true, make_bat_fn);
   }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_Main::nd_optimize()
{
   int i, j, k, n, sum, lastterm;
   // COUNT NUMBER OF TERMINALS FOR NEW LIST ...
   n = 0;
   for (i = 0; i < N_states; i++)
   {
      lastterm = -1;
      if (nd_state[i] > 1) nd_state[i] = 1;
      for (j = nd_item[i]; j < nd_item[i + 1]; j++)
      {
         if (nd_term[j] != lastterm)
         {
            n++;
            lastterm = nd_term[j];
         }
      }
   }
   nd_start = new int[n + 1];
   n_ndterms = n;

   // CREATE NEW TERMINAL LIST AND START VECTOR ...
   n = 0;
   sum = 0;
   for (i = 0; i < N_states; i++)                  // For all states.
   {
      k = 0;                                       // Reset counter.
      lastterm = -1;                               // Reset to unknown.
      for (j = nd_item[i]; j < nd_item[i + 1]; j++)   // For all items in this state.
      {
         if (nd_term[j] != lastterm)   // Another terminal?
         {
            k++;                       // Count of terminals for this state.
            nd_start[n] = j;           // Start of actions for this terminal.
            lastterm = nd_term[j];  // Last terminal seen.
            nd_term[n++] = nd_term[j]; // Move terminal to new position.
         }
      }
      nd_item[i] = sum; // Change to new terminal start for this state.
      sum += k;
   }
   nd_start[n] = j;     // End of actions for last terminal.
   nd_item[i] = sum;   // End of new terminal list for last state.
}

///////////////////////////////////////////////////////////////////////////////

void  PG_Main::prt_prod (FILE* tables, int p, char* before, char* after)
{
   int t, s;
   fprintf (tables, "%s %s -> ", before, head_name[head_sym[p]]);
   for (t = F_tail[p]; t < F_tail[p+1]; t++)
   {
      s = Tail[t];
      if (s >= 0) fprintf (tables, "%s ", term_name[s]);
      else        fprintf (tables, "%s ", head_name[-s]);
   }
   fprintf (tables, "%s", after);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

char* PG_Main::make_term (const char* s)
{
   static char string[256];
   if (*s == '\'' || *s == '\"')
   {
      int i =  0;
      char ch = *s;
      string[i++] = '\\';
      string[i++] = ch;
      for (const char* p = s+1; *(p+1) != 0; p++)
      {
         string[i++] = *p;
      }
      string[i++] = '\\';
      string[i++] = ch;
      string[i++] = 0;
   }
   else
   {
      int i =  0;
      for (const char* p = s; *p != 0; p++)
      {
         string[i++] = *p;
      }
      string[i++] = 0;
   }
   return (string);
}

//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////



/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
