// string_builder.c
// Implement a string_builder

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string_builder.h"

static const size_t string_builder_start_size = 4;

struct string_builder {
    char *text;
    size_t size;
    size_t len;
};

// Allocate a string builder struct
string_builder_t *string_builder_alloc( void ) {
    string_builder_t *sb;
    sb = calloc( 1, sizeof( string_builder_t ));
    sb->text = malloc( string_builder_start_size * sizeof( char ));
    sb->size = string_builder_start_size;
    sb->len = 0;
    return sb;
}

// Free a string builder struct
void string_builder_free( string_builder_t *sb ) {
    if ( sb == NULL ) {
        return;
    }
    free( sb->text );
    free( sb );
}

// Grow the string's size by 2 if needed
void string_builder_grow( string_builder_t *sb, size_t grow_by ) {
    if ( sb == NULL || grow_by == 0 ) {
        return;
    }
    if ( sb->size >= sb->len + grow_by + 1 ) {
        return;
    }
    while ( sb->size < sb->len + grow_by + 1 ) {
        sb->size *= 2;
    }
    sb->text = realloc( sb->text, sb->size * sizeof( char ));
}

// Add a c-string to the string
void string_builder_add_string( string_builder_t *sb, const char *s, size_t s_len ) {
    if ( sb == NULL || s == NULL || *s == '\0' ) {
        return;
    }
    if ( s_len == 0 ) {
        s_len = strlen( sb->text );
    }
    string_builder_grow( sb, s_len );
    memmove( sb->text + sb->len, s, s_len );
    sb->len += s_len;
    sb->text[sb->len] = '\0';
}

// Add a character to the string
void string_builder_add_char( string_builder_t *sb, char c ) {
    if ( sb == NULL ) {
        return;
    }
    string_builder_grow( sb, 1 );
    sb->text[sb->len] = c;
    sb->len++;
    sb->text[sb->len] = '\0';

}
// Clear the string builder
void string_builder_clear( string_builder_t *sb ) {
    if ( sb == NULL ) {
        return;
    }
    string_builder_clear_end( sb, 0 );
}

// Clear from pos to the beginning of the string
void string_builder_clear_start( string_builder_t *sb, size_t pos ) {
    if ( sb == NULL || pos == 0 ) {
        return;
    }
    if ( pos >= sb->len ) {
        string_builder_clear( sb );
        return;
    }
    sb->len -= pos;
    memmove( sb->text, sb->text + sb->len, sb->len + 1 );
}

// Clear from pos to the end of the string
void string_builder_clear_end( string_builder_t *sb, size_t pos ) {
    if ( sb == NULL || pos >= sb->len ) {
        return;
    }
    sb->len = pos;
    sb->text[sb->len] = '\0';
}

// The length of string
size_t string_builder_len( const string_builder_t *sb ) {
    if ( sb == NULL ) {
        return 0;
    }
    return sb->len;
}

// Peek at the c-string in the builder, ok for readonly access.
const char *string_builder_peek( const string_builder_t *sb ) {
    if ( sb == NULL ) {
        return NULL;
    }
    return sb->text;
}

// Return a copy of the string
char *string_builder_copy( const string_builder_t *sb, size_t *len ) {
    if ( sb == NULL ) {
        return NULL;
    }
    if ( len != NULL ) {
        *len = sb->len;
    }
    char *retval = malloc( sb->len + 1 );
    memcpy( retval, sb->text, sb->len + 1 );
    return retval;
}
