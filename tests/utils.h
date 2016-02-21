#include <cstdio>
#include <cstring>

/**
 * This function can be used to redirect stdout to files
 *
 * The first call to swapOutput redirects a to b
 * The second call redirects b to a
 */
inline void swapOutput(FILE *a, FILE *b) {
	FILE tmp;
	memcpy(&tmp, a, sizeof(FILE));
	memcpy(a, b, sizeof(FILE));
	memcpy(b, &tmp, sizeof(FILE));
}
