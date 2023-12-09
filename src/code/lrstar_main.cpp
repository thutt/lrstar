//    LRSTAR Main Code

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "lrstar_basic_defs.h"
#include "lrstar_cmdline.h"
#include "lrstar_sample.h"


lrstar_options_t  options;


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
