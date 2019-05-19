// word_count - routine to classify the unique words and their frequency in a test input string

// Mike Barker
// May 15th, 2019

#include "word_count.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// strdup - create a duplicate string
// parameters:
// - const char *src - the string to duplicate
// returns:
// - a pointer to the duplicate string or NULL if duplication failed
char *strdup( const char *src ) {
    char *dst = malloc(strlen(src));
    if ( dst != NULL ) {
        strcpy( dst, src );
    }
    return dst;
}

// sanitize_word - given a word, return a new sanitized one.
// - remove non alpha numeric characters from the start of the src
// - remove non alpha numeric characters from the end of the src
// - remove single quotes around src
// - convert each character to lowercase
// parameters:
// - char *dest_word        - the destination buffer, should be src_len long
// - const char *src_word   - the string to be sanitized
// - size_t src_len         - the length of the src string
// returns:
// - the length of the dst_word
int sanitize_word( char *dst_word, const char* src_word, size_t src_word_len ) {
    int start_pos = 0;
    int end_pos = src_word_len - 1;

    while( ! isalnum( src_word[start_pos] )) {
        if (( src_word[start_pos] == '\'' ) && ( src_word[start_pos] == src_word[end_pos] )) {
            break;
        }
        start_pos++;
    }

    while( ! isalnum( src_word[end_pos] )) {
        if (( src_word[end_pos] == '\'' ) && ( src_word[end_pos] == src_word[start_pos] )) {
            break;
        }
        end_pos--;
    }

    while(( src_word[start_pos] == '\'' ) && ( src_word[start_pos] == src_word[end_pos] )) {
        start_pos++;
        end_pos--;
    }

    int j = 0;
    for ( int i = start_pos; i <= end_pos; i++ ) {
        dst_word[j] = tolower( src_word[i] );
        j++;
    }
    dst_word[j] = '\0';
    return j;
}

// add_word - if the word has been added already, update it's count, otherwise add it with a count of 1.
// parameters:
// - const char *word         - the word to add
// - int unique_words         - the number of unique words seen so far
// - word_count_word_t *words - a pointer to an array of word_count_word_t types.
// returns:
// - the number of unique words, or the error EXCESSIVE_NUMBER_OF_WORDS
int add_word( const char *word, int unique_words, word_count_word_t *words ) {

    for ( int i = 0; i < unique_words; i++ ) {
        if ( strcmp( word, words[i].text ) == 0 ) {
            words[i].count += 1;
            return unique_words;
        }
    }

    if ( unique_words < MAX_WORDS ) {
        strcpy( words[unique_words].text, word );
        words[unique_words].count = 1;
        unique_words++;
        return unique_words;

    } else {
        return EXCESSIVE_NUMBER_OF_WORDS;
    }
}

int word_count( const char *input_text, word_count_word_t *words ) {

    size_t word_length = 0;
    char *input = NULL;
    char *token = NULL;
    const char delim[] = " ,";
    char word[MAX_WORD_LENGTH + 1];
    int unique_words = 0;

    input = strdup( input_text );

    token = strtok(input, delim );
    while( token != NULL ) {
        word_length = strlen( token );
        if ( word_length > MAX_WORD_LENGTH ) {
            unique_words = EXCESSIVE_LENGTH_WORD;
            break;
        }
        sanitize_word( word, token, word_length );
        unique_words = add_word( word, unique_words, words );
        if ( unique_words == EXCESSIVE_NUMBER_OF_WORDS ) {
            break;
        }
        token = strtok( NULL, delim );
    }
    free( input );
    return unique_words;
}
