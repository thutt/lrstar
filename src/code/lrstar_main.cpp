
/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//    LRSTAR Main Code

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "lrstar_basic_defs.h"
#if defined(LRSTAR_LINUX)
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

#include "lrstar_main.h"

#if defined(LRSTAR_LINUX)
#include <unistd.h>
off_t _filelength(int fd)
{
   struct stat st;
   fstat(fd, &st);
   return st.st_size;
}
#else
#include <io.h>
#include <conio.h>
#endif

#define EOL_CHAR 10 // End Of Line character.
#define EOF_CHAR 26 // End Of File character.

class cOption
{
public:
   static int debug;    // Debug info output to ".txt" file.
   static int echo;     // Echo source code to screen.
   static int init  (int na, char* arg[]);
};

class cInput
{
public:
   static char*  input_start;    // First byte of input area.
   static char*  input_end;      // Byte after input.
   static char   path[256];      // Path to file (dir/fn.ft).
   static char   dir[256];       // Directory (folder) of file.
   static char   filename[256];  // Filename of input file.
   static char   filetype[64];   // Filetype of input file.
   static size_t filesize;
   static int    filedesc;
   static int    init (char* dir, char* fn, char* ft);
   static void   term ();
};

class cOutput
{
public:
   static char   path[256];      // Path to file (dir/fn.ft).
   static char   dir[256];       // Directory.
   static char   filename[256];  // File name.
   static char   filetype[64];   // File type.
   static FILE*  filedesc;       // File descriptor.
   static int    init (char* dir, char* fn, char* ft);
   static void   term ();
};

FILE *output;
void  quit(int rc);
char *number(long x);
int   split(char* arg, char* dir, char* fn, char* ft, const char* def);

cOption Option;
cInput  Input;
cOutput Output;

char*  cInput::input_start;      // First byte of include area.
char*  cInput::input_end;        // Byte after input.
char   cInput::dir[256];         // Directory of include file.
char   cInput::path[256];        // Path of include file.
char   cInput::filename[256];    // Filename of include file.
char   cInput::filetype[64];     // Filetype of include file.
int    cInput::filedesc;
size_t cInput::filesize;

char   cOutput::path[256];       // Path of output file.
char   cOutput::dir[];           // Directory.
char   cOutput::filename[];      // Filename of output file.
char   cOutput::filetype[];      // Filetype of output file.
FILE*  cOutput::filedesc;        // File descriptor.

int    cOption::debug;
int    cOption::echo;

/////////////////////////////////////////////////////////////////////////////////////////////////////

int
main(int argc, char **argv)
{
   const char* copyright = "\n%s parser, copyright ?.\n";
   int   i, nl;
   clock_t time1;
   clock_t time2;
   clock_t thou;
   clock_t sec;
   clock_t nlps;
   clock_t t;

   time1 = clock();  // Get start time.
   nl = 0;

   printf (copyright, generated_parser.grammar);
   printf ("Args:   ");
   for (i = 1; i < argc; i++) printf (" %s", argv[i]);
   printf ("\n");

   Option.init (argc, argv);
   Input.init  (Input.dir,  Input.filename,  Input.filetype);
   Output.init (Output.dir, Output.filename, Output.filetype);

   output = Output.filedesc;

   // Parse the input file ...
   if (!generated_parser.init_parser(Input.path, Input.input_start,
                                     100000, 1000000)) {
      fprintf(stderr, "Failed to initialize parser.\n");
      quit(1);
   }

   time1 = clock();  // Get start time.
   nl = generated_parser.parse(output);
   time2 = clock (); // Get end time.
   generated_parser.term_parser ();
   if (nl <= 0) {
      nl = -nl;
      printf ("\nError in parse().\n");
      quit (1);
   }

   // Compute the time and speed ...
   t = time2 - time1;
   if (t == 0) t = 1;
   nlps = CLOCKS_PER_SEC * nl / t;
   thou = t * 1000 / CLOCKS_PER_SEC;
   sec  = thou / 1000;
   thou -= sec * 1000;

   printf ("\nSuccess ...\n");
   printf ("%10s symbols in symbol table.\n",  number(generated_parser.n_symbols));
   printf ("%10s nodes in AST.\n",             number(generated_parser.n_nodes));
   printf ("%10s lines read in input file.\n", number(nl));
   printf ("%10s lines per second.\n",         number(nlps));
   printf ("%6ld.%03ld seconds.\n",            sec, thou);

   quit (0);
   return 0;
}

///////////////////////////////////////////////////////////////////////////////

void  quit (int rc)
{
   Input.term();
   Output.term();
#if defined(LRSTAR_WINDOWS)
   printf ("\nPress any key to close ...\n");
   while (!_kbhit());
#endif
   exit (rc);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   cInput::init (char* dir, char* fn, char* ft)
{
   long  nb;                                  // Number of bytes read.

   strcpy(path, dir);
   strcat(path, fn);
   strcat(path, ft);

   filedesc = _open (path, 0);               // Open the file.
   if (filedesc < 0) {                       // If open error.
      printf ("File %s not found.\n", path);
      quit (1);
   }

   /* A file length cannot be negative, so the cast is safe. */
   filesize     = static_cast<size_t>(_filelength(filedesc));
   input_start  = new char [filesize + 6]; // Get some RAM space.
   *input_start = '\n';                    // Put <eol> at beginning.

   nb = _read(filedesc, input_start + 1, filesize); // Read size bytes into buffer.
   if (nb <= 0) {                                 // If read error.
      printf ("Read error on file %s.\n", path);
      quit(1);
   }

   input_end = input_start + nb + 1;      // Set end-of-buffer pointer.
   *input_end++ = EOL_CHAR;               // Put end-of-line here.
   *input_end++ = EOF_CHAR;               // Put first <eof> here.
   *input_end++ = EOF_CHAR;               // Put second <eof> here.
   _close (filedesc);                     // Close file.
   return 1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  cInput::term ()
{
   delete [] input_start;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   cOutput::init (char* dir, char* fn, char* ft)
{
   strcpy (path, dir);
   strcat (path, fn);
   strcat (path, ft);
   filedesc = fopen (path, "w");

   if (filedesc == NULL)
   {
      printf ("\n\nOutput file %s cannot be created.\n\n", path);
      quit (1);
   }
   return 1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  cOutput::term ()
{
   if (filedesc != 0) fclose (filedesc);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

char *number(long x)
{
   int i, j, k;
   char buff[25];
   static char string[25];

   sprintf(buff, "%ld", x);

   k           = (int)strlen(buff);
   i           = k + (k - 1) / 3;
   string[i--] = '\0';
   j = 0;
   while (1) {
      string[i--] = buff[--k];
      if (i < 0) {
         break;
      }
      if (++j % 3 == 0) {
         string[i--] = ',';
      }
   }
   return string;
}

///////////////////////////////////////////////////////////////////////////////

int   cOption::init (int argc, char* argv[])
{
   int i, ne, no, nf, help;
   if (argc < 2)
   {
   Help:    printf ("Usage:\n");
      printf ("\n");
      printf ("   parse <input_file>\n");
      printf ("\n");
      quit (1);
   }

   ne = 0;  // Number of errors.
   no = 0;  // Number of options.
   nf = 0;  // Number of files.

   if (argc > 1)
   {
      cInput::dir[0]      = 0;
      cInput::filename[0] = 0;
      cInput::filetype[0] = 0;
      if (argv[1][0] == '/') goto Optn;
      nf++;
      split (argv[1], cInput::dir, cInput::filename, cInput::filetype, "input.txt");
      if (cInput::filename[0] == 0)
      {
         ne++;
         printf ("Invalid filespec: \"%s\"\n", argv[1]);
         quit (1);
      }
      else
      {
         strcpy ((char*)Output.dir, (char*)Input.dir);
         char* p = Input.filename;
         while (*p != '.' && *p != 0) p++;
         if (*p == '.')
         {
            *p = 0;
            strcat ((char*)Output.filename, (char*)Input.filename);
            strcat ((char*)Output.filename, ".output");
            *p = '.';
         }
         else
         {
            strcat ((char*)Output.filename, "output");
         }
         strcat ((char*)Output.filetype,  ".txt");
      }
   }

   // Default values ...
Optn: debug      = 0;
   echo       = 0;
   help       = 0;

   // Process options ...
   for (i = nf+1; i < argc; i++)
   {
      no++;
      char* f = 0; // filename
      char* p = argv[i];
      while (*p != 0 && *p != '=') p++;
      int val = 1;
      if (*p == '=')
      {
         f = p+1;
         val = atoi(f);
         if (*f == 0) goto Err;
         if (*f < '0' || *f > '1') val = -1; // error.
         if (*(f+1) != 0) val = -1;
         *p = 0;
      }
      switch (argv[i][1])
      {
      case 'd':
      {
         if (argv[i][2] == 0)
         {
            if (f) *p = '=';
            if (val < 0) goto Err;
            debug = val;
         }
         else goto Err;
         break;
      }
      case 'e':
      {
         if (argv[i][2] == 0)
         {
            if (f) *p = '=';
            if (val < 0) goto Err;
            echo = val;
         }
         else goto Err;
         break;
      }
      case '?':
      {
         if (argv[i][2] == 0)
         {
            if (f) *p = '=';
            if (val < 0) goto Err;
            help = val;
         }
         else goto Err;
         break;
      }
      default:
      {
      Err:           ne++;
         printf ("Invalid option: \"%s\"\n", argv[i]);
         quit (1);
      }
      }
   }
   if (ne || help)
   {
      if (ne) printf ("\n");
      goto Help;
   }
   if (nf == 0)
   {
      printf ("No input file was specified.\n");
      quit (1);
   }
   return 1;
}

///////////////////////////////////////////////////////////////////////////////

int   split (char* arg, char* dir, char* fn, char* ft, const char* def)
{
   // Define directory and move to path ...
   char* f;
   char* p;
   char* x = 0;
   if (arg == 0) return 0;
   for (p = arg; *p != 0; p++) // Scan filename specified.
   {
      if (*p == '\\') x = p;  // Get last \.
   }
   if (x == 0)                // Directory not specified?
   {
      dir[0] = 0;             // Empty directory.
   }
   else                       // Directory specified!
   {
      if (arg[0] != '*')      // Not '*'?
      {
         strcpy (dir, arg);   // Override directory.
         dir[x-arg+1] = 0;
      }
   }

   // Define filename and filetype, move to path ...
   if (x == 0) f = arg;       // Start of filename.
   else        f = x+1;       // Start of filename.
   x = 0;
   for (p = f; *p != 0; p++)  // Scan filename specified.
   {
      if (*p == '.') x = p;   // Get last dot.
   }
   if (x == 0)                // Filetype not specified?
   {
      if (f[0] != '*' && f[0] != 0)
      {
         strcpy (fn, f);      // Override filename.
      }
      strcpy (ft, def);       // Use default filetype.
   }
   else
   {
      if (f[0] != '*' && f[0] != 0)
      {
         *x = 0;
         strcpy (fn, f);      // Override filename.
         *x = '.';
      }
      strcpy (ft, x);         // Use specified filetype.
   }
   return 1;
}

//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////
/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
