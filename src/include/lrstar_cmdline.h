/* Copyright (c) 2023 Logic Magicians Software
 *
 * BSD 3 Clause license.
 *
 */
#if !defined(__LRSTAR_CMDLINE_H__)
#define __LRSTAR_CMDLINE_H__
#include <stdbool.h>

extern "C" {

    typedef struct lrstar_options_t {
        char *output;           /* Pathname of lrstar output file. */
    } lrstar_options_t;

    int lrstar_get_options(int argc, char *argv[], lrstar_options_t *options);
}
#endif
