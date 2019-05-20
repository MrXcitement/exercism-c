// acronym.c -- given a phrase, convert to an ancronym.
// Mike Barker
// May 20th 2019

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "string_builder.h"
#include "acronym.h"

// abbreviate
// Given a phrase, return an abbreviation, the returned abbreviation must be freed.
char *abbreviate(const char *phrase) {
    if ( phrase == NULL || *phrase == '\0' ) {
        return NULL;
    }

    string_builder_t *sb = string_builder_alloc();

    bool in_word = false;
    char c = 0;
    size_t pos = 0;
    while (( c = phrase[pos] ) != '\0' ) {
        if ( c == ' ' || c == '-' ) {
            if ( in_word ) {
                in_word = false;
            }
        } else {
            if ( ! in_word ) {
                string_builder_add_char( sb, toupper( c ));
                in_word = true;
            }
        }
        pos++;
    }

    char *retval = NULL;
    if ( string_builder_len( sb ) > 0 ) {
        retval = string_builder_copy( sb, NULL );
    }
    string_builder_free( sb );
    return retval;
}
