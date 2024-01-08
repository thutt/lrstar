#include <assert.h>
#include <fcntl.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "lrstar_basic_defs.h"
#include "lrstar_sample.h"
#include "Hello_LexerTables_typedef.h"
#include "Hello_Parser.h"
#include "Goodbye_LexerTables_typedef.h"
#include "Goodbye_Parser.h"


extern "C" {
    typedef struct options_t {
        char     *output;       /* Pathname of lrstar output file. */
        unsigned  iterations;   /* Number of times to parse file. */
        char     *hello;        /* Pathname of Hello grammar file.  */
        char     *goodbye;      /* Pathname of Goodbye grammar file.  */
    } options_t;


    options_t options;

    static struct option long_options[] = {
        { "help",        no_argument,       NULL,  256 },
        { "output",      required_argument, NULL,  257 },
        { "iterations",  required_argument, NULL,  258 },
        { "hello",       required_argument, NULL,  259 },
        { "goodbye",     required_argument, NULL,  260 },
        { NULL,      no_argument,       NULL,    0 }
    };


    static void
    help(const char *exec)
    {
        printf("\n\n"
               "%s [--help | --output <pathname>]... <file>\n\n", exec);
        printf("  --help  :   Print this help message and exit.\n"
               "  --output:   Provides path of file to which lrstar will write.\n"
               "\n");
    }


    static void
    init_options(options_t *opts)
    {
        opts->output = 0;
        opts->iterations = 1;
    }


    static int                  // Returns optind
    get_options(int argc, char *argv[], options_t *opts)
    {
        int c;

        init_options(opts);

        while (1) {
            int option_index = 0;

            c = getopt_long(argc, argv, "", long_options, &option_index);
            if (c == -1) {
                break;
            }

            switch (c) {
            case 256:
                help(argv[0]);
                exit(0);
                break;

            case 257:
                opts->output = strdup(optarg);
                break;

            case 258:
                opts->iterations = static_cast<unsigned>(abs(atoi(optarg)));
                break;

            case 259:
                opts->hello = strdup(optarg);
                break;

            case 260:
                opts->goodbye = strdup(optarg);
                break;

            default:
                printf("?? getopt returned character code 0%o ??\n", c);
            }
        }

        return optind;          /* Remaining non-options arguments are
                                 * in [optind, argc).
                                 */
    }
}



Hello_parser_t *Hello_new_parser(const char *input_path,
                                 char       *input_text,
                                 unsigned    max_symbols);
Goodbye_parser_t *Goodbye_new_parser(const char *input_path,
                                     char       *input_text,
                                     unsigned    max_symbols);


static void
run_hello(const char *pathname, FILE *output_fp)
{
    int             nl;
    clock_t         start;
    clock_t         end;
    clock_t         thou;
    clock_t         sec;
    clock_t         nlps;
    clock_t         t;
    char           *input_start;
    Hello_parser_t *parser;

    input_start = read_input(pathname);
    parser      = Hello_new_parser(pathname, input_start, 100000);
    printf("%s parser.\n", parser->grammar);

    start = clock();
    nl    = parser->parse(output_fp);
    end   = clock();
    parser->term_parser();
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
    printf("%10s symbols in symbol table.\n",  number(parser->n_symbols));
    printf("%10s nodes in AST.\n",             number(parser->n_nodes));
    printf("%10s lines read in input file.\n", number(nl));
    printf("%10s lines per second.\n",         number(nlps));
    printf("%6ld.%03ld seconds.\n",            sec, thou);
    delete parser;
    delete [] input_start;
}    


static void
run_goodbye(const char *pathname, FILE *output_fp)
{
    int               nl;
    clock_t           start;
    clock_t           end;
    clock_t           thou;
    clock_t           sec;
    clock_t           nlps;
    clock_t           t;
    char             *input_start;
    Goodbye_parser_t *parser;

    input_start = read_input(pathname);
    parser      = Goodbye_new_parser(pathname, input_start, 100000);
    printf("%s parser.\n", parser->grammar);

    start = clock();
    nl    = parser->parse(output_fp);
    end   = clock();
    parser->term_parser();
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
    printf("%10s symbols in symbol table.\n",  number(parser->n_symbols));
    printf("%10s nodes in AST.\n",             number(parser->n_nodes));
    printf("%10s lines read in input file.\n", number(nl));
    printf("%10s lines per second.\n",         number(nlps));
    printf("%6ld.%03ld seconds.\n",            sec, thou);
    delete parser;
    delete [] input_start;
}    


int
main(int argc, char **argv)
{
    unsigned  iteration;
    FILE     *output_fp;

    get_options(argc, argv, &options);

    if (options.output == 0) {
       printf("--output option must be specified.\n");
       fatal(4);
    }

    if (options.hello == 0) {
       printf("--hello option must be specified.\n");
       fatal(5);
    }        

    if (options.goodbye == 0) {
       printf("--goodbye option must be specified.\n");
       fatal(6);
    }        

    output_fp = fopen(options.output, "w");
    if (output_fp == NULL) {
        printf("Output file '%s' cannot be opened for writing.\n",
               options.output);
        fatal(7);
    }

    iteration = 0;
    while (iteration < options.iterations) {
        ++iteration;
        run_hello(options.hello, output_fp);
        run_goodbye(options.goodbye, output_fp);
    }

    fclose(output_fp);
    return 0;
}

