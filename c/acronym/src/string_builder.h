// string_builder.h
// A general purpose string builder library.
// Inspired by:
// https://nachtimwald.com/2017/02/26/efficient-c-string-builder/
// http://www.drdobbs.com/an-idea-for-dynamic-c-strings/184401650

#ifndef STRING_BUILDER_H
#define STRING_BUILDER_H

#include "stddef.h"

struct string_builder;
typedef struct string_builder string_builder_t;

// Allocate a string builder struct
string_builder_t *string_builder_alloc( void );
// Free a string builder struct
void string_builder_free( string_builder_t *sb );
// Add a c-string to the string
void string_builder_add_string( string_builder_t *sb, const char *s, size_t s_len );
// Add a character to the string
void string_builder_add_char( string_builder_t *sb, char c );
// Clear the string builder
void string_builder_clear( string_builder_t *sb );
// Clear from pos to the beginning of the string
void string_builder_clear_start( string_builder_t *sb, size_t pos );
// Clear from pos to the end of the string
void string_builder_clear_end( string_builder_t *sb, size_t pos );
// The length of string
size_t string_builder_len( const string_builder_t *sb );
// The c-string in the builder
const char *string_builder_peek( const string_builder_t *sb );
// Return a copy of the string
char *string_builder_copy( const string_builder_t *sb, size_t *len );

#endif
