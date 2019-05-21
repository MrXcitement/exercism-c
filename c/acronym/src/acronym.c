// acronym.c -- given a phrase, convert to an ancronym.
// Mike Barker
// May 20th 2019

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string_builder.h"
#include "acronym.h"

const size_t MAX_ABBREVIATION_SIZE = 4;

// abbreviate
// Given a phrase, return an abbreviation, the returned abbreviation must be freed.
char *abbreviate(const char *phrase) {
    if ( phrase == NULL || *phrase == '\0' ) {
        return NULL;
    }

    size_t retlen = 0;
    size_t retsize = MAX_ABBREVIATION_SIZE;
    char *retval = calloc( retsize, sizeof( char ));
    bool in_delim = true;

    while ( *phrase != '\0' ) {
        if ( *phrase == ' ' || *phrase == '-' ) {
            if ( ! in_delim ) {
                in_delim = true;
            }
        } else {
            if ( in_delim ) {
                in_delim = false;
                sprintf( retval, "%s%c", retval, toupper( *phrase ));
                retlen++;
                if ( retlen <= MAX_ABBREVIATION_SIZE ) {
                    retsize *= 2;
                    retval = realloc( retval, retsize );
                    *(retval + retlen) = '\0';
                }
            }
        }
        phrase++;
    }
    return retval;
}
