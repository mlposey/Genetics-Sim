#include <cstdio>
#include <cstring>

/**
 * This function can be used to redirect stdout to files
 * 
 * The first call to swapOutput redirects A to B
 * The second call redirects B to A
 *
 * courtesty of JackCColeman on stackoverflow
 * papa bless
 */
inline void swapOutput(FILE *A, FILE *B) {
	FILE temp;
	memcpy(&temp, A, sizeof(struct _iobuf));
	memcpy(A, B, sizeof(struct _iobuf));
	memcpy(B, &temp, sizeof(struct _iobuf));
}
