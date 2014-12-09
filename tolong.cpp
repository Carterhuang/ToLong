#include "tolong.h"

#include <cstring>
#include <climits>

bool exceedlimit(long digit, long sum, long sign) {
    if (sign > 0) {
        long roof = LONG_MAX;
        for (int i = 0; i < 10; ++i) {
            roof -= sum;
            if (digit > roof)
                return true;
        }
        return false;
    }
        
    if (sign < 0) {
        long floor = LONG_MIN;
        for (int i = 0; i < 10; ++i) {
            floor += sum;
            if (digit * sign < floor)
                return true;
        }
        return false;
    }
}
    
long strtolong(const char *str) {
    long result = 0;
    const char*ptr = str;
        
    // Skip white spaces and 0s.
    while(ptr != NULL && 
            (*ptr == ' ' || *ptr == '0')) {
        ptr ++;
    }
        
    // The string only contains white
    // spaces.
    if (ptr == NULL) {
        return result;
    }
        
    long sign = 1;
    if (*ptr == '-' || *ptr == '+') {
        sign = (*ptr == '-') ? (-1) : 1;
        ptr ++;
    }
        
    long newdigit;
    while(ptr != NULL && (*ptr >= 48 && *ptr <= 57)) {
        newdigit = *ptr - 48;
        if (exceedlimit(newdigit, result, sign)) {
            return (sign > 0) ? LONG_MAX :LONG_MIN;
        }
            
        result = result * 10 + newdigit;
        ptr ++;
    }
        
    return result * sign;
}


