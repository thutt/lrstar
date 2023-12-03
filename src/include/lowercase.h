/* Copyright (c) 2023 Logic Magicians Software
 *
 * BSD 3 Clause license.
 *
 * This file facilitates a fast lowercase conversion for ASCII characters.
 *
 * The 'lowercase' array identity maps all elements, except 'A'..'Z'.
 * The 'A'..'Z' range is mapped to the lowercase equivalent.
 */
#if !defined(__LOWERCASE_H__)
#define __LOWERCASE_H__

extern const char lowercase[256];

#endif
