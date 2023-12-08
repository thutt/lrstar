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
#elif defined(LRSTAR_WINDOWS)
#include <io.h>
#include <conio.h>
#endif

#include "lrstar_main.h"
#include "lrstar_cmdline.h"


#define EOL_CHAR 10 // End Of Line character.
#define EOF_CHAR 26 // End Of File character.


static lrstar_options_t  options;
static char             *input_start;
static FILE             *output_fp;


static void
cleanup(void)
{
   delete [] input_start;
   delete generated_parser;
   if (output_fp != NULL) {
      fclose(output_fp);
   }
}

void
fatal(int rc)
{
   cleanup();
#if defined(LRSTAR_WINDOWS)
   printf("\nPress any key to close ...\n");
   while (!_kbhit()) {
   }
#endif
   exit(rc);
}


static void
read_input(const char *pathname)
{
   size_t       nb;
   size_t       filesize;
   struct stat  statbuf;
   FILE        *input_fp;
   char        *input_end;

   input_fp = fopen(pathname, "r");
   if (input_fp == NULL) {
      printf("Unable to open '%s' for reading.\n", pathname);
      fatal(1);
   }

   /* A file length cannot be negative, so the cast is safe. */
   if (stat(pathname, &statbuf) != 0) {
      printf("Unable to determine size of '%s'.\n", pathname);
      fatal(2);
   }
   filesize     = static_cast<size_t>(statbuf.st_size);
   input_start  = new char [filesize + 10]; // Get some RAM space.
   *input_start = '\n';                    // Put <eol> at beginning.

   nb = fread(&input_start[1], sizeof(char), filesize, input_fp);
   if (nb != filesize) {
      printf("Unable to read '%zd' bytes from '%s'.\n", filesize, pathname);
      fatal(3);
   }

   input_end = input_start + nb + 1;
   *input_end++ = EOL_CHAR;
   *input_end++ = EOF_CHAR;
   *input_end++ = EOF_CHAR;
   *input_end++ = '\0';
   fclose(input_fp);
}


char *
number(long x)
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


int
main(int argc, char **argv)
{
   int         nl;
   clock_t     start;
   clock_t     end;
   clock_t     thou;
   clock_t     sec;
   clock_t     nlps;
   clock_t     t;

   lrstar_get_options(argc, argv, &options);

   if (options.output == 0) {
      printf("--output option must be specified.\n");
      fatal(4);
  }

   if (optind >= argc) {
      printf("No input file supplied.\n");
      fatal(5);
   }

   read_input(argv[optind]);

   output_fp = fopen(options.output, "w");
   if (output_fp == NULL) {
      printf("Output file '%s' cannot be opened for writing.\n",
             options.output);
      fatal(6);
   }

   printf("%s parser.\n", generated_parser->grammar);
   if (!generated_parser->init_parser(argv[optind], input_start,
                                      100000, 1000000)) {
      fprintf(stderr, "Failed to initialize parser.\n");
      fatal(7);
   }

   start = clock();
   nl    = generated_parser->parse(output_fp);
   end   = clock();
   generated_parser->term_parser();
   if (nl <= 0) {
      printf("\nError in parse().\n");
      fatal(8);
   }

   t = end - start;
   if (t == 0) {
      t = 1;
   }

   nlps = CLOCKS_PER_SEC * nl / t;
   thou = t * 1000 / CLOCKS_PER_SEC;
   sec  = thou / 1000;
   thou -= sec * 1000;

   printf("\nSuccess ...\n");
   printf("%10s symbols in symbol table.\n",  number(generated_parser->n_symbols));
   printf("%10s nodes in AST.\n",             number(generated_parser->n_nodes));
   printf("%10s lines read in input file.\n", number(nl));
   printf("%10s lines per second.\n",         number(nlps));
   printf("%6ld.%03ld seconds.\n",            sec, thou);
   cleanup();
   return 0;
}

/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
