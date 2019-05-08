/* isogram.c --- Determine if a word or phrase is an isogram.
 *  Mike Barker <mike@thebarkers.com>
 *  May 4th, 2019
 */

#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool is_isogram(const char *s) {

	if ( s == NULL ) return false;

	bool seen_letter[26] = { false };
	int letter_idx = 0;	

	for ( int i = 0; i < (int)strlen( s ); i++ ) {
		if ( ! isalpha( s[i] )) {
			continue;
		}
		letter_idx = (int)tolower( s[i] ) - (int)'a';
		if ( seen_letter[letter_idx] ) {
			return false;
		}
		seen_letter[letter_idx] = true;
	}
	return true;
}

