#include <ctype.h>
#include <stdbool.h>
#include <string.h>

// is_panagram
// Determine if a sentence is a pangram
bool is_pangram(const char *sentence) {
    // The sentence is empty, just exit
    if ( sentence == NULL || *sentence == '\0' ) {
        return NULL;
    }

    // Use a bitmap to track the letters seen
    const unsigned int PANGRAM_BITMAP = 0x03FFFFFF;
    unsigned int alpha_bitmap = 0U;
    while ( *sentence != '\0' ) {
        if ( isalpha( *sentence )) {
            unsigned char letter_value = tolower(*sentence) - 'a';
            alpha_bitmap |= 1UL << letter_value;
        }
        sentence++;
    }

    // Check the bitmap to see if we saw all the letters
    if ( alpha_bitmap == PANGRAM_BITMAP ) {
        return true;
    } else {
        return false;
    }
}
