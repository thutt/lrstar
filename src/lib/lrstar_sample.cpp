#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lrstar_basic_defs.h"
#if defined(LRSTAR_LINUX)
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#elif defined(LRSTAR_WINDOWS)
#include <io.h>
#include <conio.h>
#endif

#define EOL_CHAR 10 // End Of Line character.
#define EOF_CHAR 26 // End Of File character.

char *input_start;
FILE *output_fp;


void
cleanup(void)
{
   delete [] input_start;
//   delete generated_parser;     ------ XXX delete this in generated main().
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


void
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


