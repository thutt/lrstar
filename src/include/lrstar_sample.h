/* Copyright (c) 2023 Logic Magicians Software
 *
 * BSD 3 Clause license.
 */
#if !defined(__LRSTAR_SAMPLE_H__)
#define __LRSTAR_SAMPLE_H__

extern char *input_start;
extern FILE *output_fp;


char *number(long x);
void cleanup(void);
void fatal(int rc);
void read_input(const char *pathname);
#endif
