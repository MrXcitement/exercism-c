#ifndef PANGRAM_H
#define PANGRAM_H

#include <stdbool.h>

// is_panagram
// Determine if a sentence is a pangram.
// Paramters:
//  - const char *sentence - the sentence to check if it has all ASCII characters
// Return:
//  - bool - true if sentence is a pangram, otherwise false.
bool is_pangram(const char *sentence);

#endif
