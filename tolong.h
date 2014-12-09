#ifndef _TOLONG_
#define _toLONG_

/* A helper function that is used in strtolong.
 * The input sum denote the current value of 
 * the numerical value scanned so far. It returns
 * true if sum is about to exceed limit of 8-byte
 * long value.
 */
bool exceedlimit(long digit, long sum, long sign);

/* The function that takes a c-string as input and
 * returns a 8-byte long value */
long strtolong(const char* str);
#endif
