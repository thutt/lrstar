/* Copyright (c) 2023 Logic Magicians Software
 *
 * BSD 3 Clause license.
 *
 */

#include <assert.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lrstar_cmdline.h"

extern "C" {
    static struct option long_options[] = {
        { "help",    no_argument,       NULL,  256 },
        { "output",  required_argument, NULL,  257 },
        { NULL,      no_argument,       NULL,    0 }
    };


    static void
    help(const char *exec)
    {
        printf("%s [--help] <file>\n\n", exec);
        printf("  --help:   Print this help message and exit.\n");
    }


    static void
    init_options(lrstar_options_t *options)
    {
        options->output = 0;
    }


    int                         // Returns optind
    lrstar_get_options(int argc, char *argv[], lrstar_options_t *options)
    {
        int c;
        int digit_optind = 0;

        init_options(options);

        while (1) {
            int this_option_optind = optind ? optind : 1;
            int option_index       = 0;

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
                options->output = strdup(optarg);
                break;

            default:
                printf("?? getopt returned character code 0%o ??\n", c);
            }
        }

        return optind;          /* Remaining non-options arguments are
                                 * in [optind, argc).
                                 */
    }
};
