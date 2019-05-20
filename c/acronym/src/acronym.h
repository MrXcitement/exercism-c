#ifndef ACRONYM_H
#define ACRONYM_H

// abbreviate
// Given a phrase, return an abbreviation, the returned abbreviation must be freed.
//
// Parameters:
//  - const char *phrase - the phrase as a null terminated string
//
// Returns:
//  - char * - the abreviation as a null terminated string dynamicly allocated on the heep.
char *abbreviate(const char *phrase);

#endif
