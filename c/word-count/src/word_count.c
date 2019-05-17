// word_count - routine to classify the unique words and their frequency in a test input string

// Mike Barker
// May 15th, 2019

#include "word_count.h"

#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int sanitize_word(char *new_word, const char* word, int word_len) {
    int start_pos = 0;
    int end_pos = word_len - 1;

    while( ! isalnum( word[start_pos] )) {
        if (( word[start_pos] == '\'' ) && ( word[start_pos] == word[end_pos])) {
            break;
        }
        start_pos++;
    }

    while( ! isalnum( word[end_pos] )) {
        if (( word[end_pos] == '\'' ) && ( word[end_pos] == word[start_pos] )) {
            break;
        }
        end_pos--;
    }

    while (( word[start_pos] == '\'' ) && ( word[start_pos] == word[end_pos] )) {
        start_pos++;
        end_pos--;
    }

    int j = 0;
    for ( int i = start_pos; i <= end_pos; i++ ) {
        new_word[j] = tolower( word[i] );
        j++;
    }
    new_word[j] = '\0';
    return j;
}

int add_word(const char *word, int unique_words, word_count_word_t * words) {

    for (int i = 0; i < unique_words; i++) {
        if (strcmp(word, words[i].text) == 0) {
            words[i].count += 1;
            return unique_words;
        }
    }

    if ( unique_words < MAX_WORDS ) {
        strncpy(words[unique_words].text, word, strlen(word));
        words[unique_words].count = 1;
        unique_words++;
        return unique_words;

    } else {
        return EXCESSIVE_NUMBER_OF_WORDS;
    }
}

bool is_delim(char c) {
    return (( c == ' ') || ( c == ',' ) || ( c == '\0' ));
}

int word_count(const char *input_text, word_count_word_t * words) {

    int unique_words = 0;
    int length_word = 0;
    int length_input_text = (int)strlen(input_text);
    // bool in_word = true;

    char word_raw[MAX_WORD_LENGTH + 1];
    char word_sanitized[MAX_WORD_LENGTH + 1];

    for (int i = 0; i <= length_input_text; i++) {
        if ( is_delim( input_text[i] )) {
            if (( i > 0 ) && ( ! is_delim(input_text[i - 1]))) {
                sanitize_word(word_sanitized, word_raw, length_word);
                unique_words = add_word(word_sanitized, unique_words, words);
                if ( unique_words == EXCESSIVE_NUMBER_OF_WORDS ) {
                    break;
                }
                // in_word = false;
                length_word = 0;
            }
        } else {
            // in_word = true;
            if ( length_word > MAX_WORD_LENGTH ) {
                unique_words = EXCESSIVE_LENGTH_WORD;
                break;
            }
            word_raw[length_word] = input_text[i];
            length_word += 1;
        }
    }
    return unique_words;
}
