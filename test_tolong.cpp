#include "tolong.h"

#include <climits>
#include <cstdio>

using namespace std;


void test_empty_string() {
    long e1 = strtolong("");
    long e2 = strtolong(" ");
    long e3 = strtolong(NULL);

    if (e1 != 0)
        printf("TEST CASE: %s failed! Failed value:%d\n", __func__, e1);
    else if (e2 != 0)
        printf("TEST CASE: %s failed! Failed value:%d\n", __func__, e2);
    else if (e3 != 0)
        printf("TEST CASE: %s failed! Failed value:%d\n", __func__, e3);
    else
        printf("TEST CASE: %s succeeded!\n", __func__);
}

void test_positive_negative_long() {
    long r1 = strtolong("123456789");
    long r2 = strtolong("+123456789");
    long r3 = strtolong("-123456789");
    
    if (r1 != 123456789)
        printf("TEST CASE: %s failed! Failed value:%d\n", __func__, r1);
    else if (r2 != 123456789)
        printf("TEST CASE: %s failed! Failed value:%d\n", __func__, r2);
    else if (r3 != -123456789)
        printf("TEST CASE: %s failed! Failed value:%d\n", __func__, r3);
    else
        printf("TEST CASE: %s succeeded!\n", __func__);
}

void test_decimal_number() {
    long d1 = strtolong("123.");
    long d2 = strtolong("123.1");
    long d3 = strtolong("123.12");

    if (d1 != 123)
        printf("TEST CASE: %s failed! Failed value:%d\n", __func__, d1);
    else if (d2 != 123)
        printf("TEST CASE: %s failed! Failed value:%d\n", __func__, d2);    
    else if (d3 != 123)
        printf("TEST CASE: %s failed! Failed value:%d\n", __func__, d3);
    else
        printf("TEST CASE: %s succeeded!\n", __func__);
}

void test_invalid_number() {
    long i1 = strtolong("a");
    long i2 = strtolong(" a");
    long i3 = strtolong("a1");
    long i4 = strtolong("a 1");

    if (i1 != 0)
        printf("TEST CASE: %s failed! Failed value:%d\n", __func__, i1);
    else if (i2 != 0)
        printf("TEST CASE: %s failed! Failed value:%d\n", __func__, i2);    
    else if (i3 != 0)
        printf("TEST CASE: %s failed! Failed value:%d\n", __func__, i3);
    else if (i4 != 0)
        printf("TEST CASE: %s failed! Failed value:%d\n", __func__, i4);
 
    else
        printf("TEST CASE: %s succeeded!\n", __func__);
}

void test_string_with_alphabets_in_the_end() {
    long a1 = strtolong("1a");
    long a2 = strtolong("1 a");
    long a3 = strtolong("1a23");

    if (a1 != 1)
        printf("TEST CASE: %s failed! Failed value:%d\n", __func__, a1);
    else if (a2 != 1)
        printf("TEST CASE: %s failed! Failed value:%d\n", __func__, a2);    
    else if (a3 != 1)
        printf("TEST CASE: %s failed! Failed value:%d\n", __func__, a3);
    else
        printf("TEST CASE: %s succeeded!\n", __func__);
   
}


void test_string_with_zeros() {
    long z1 = strtolong("0123");
    long z2 = strtolong("00123");
    long z3 = strtolong(" 00123");

    if (z1 != 123)
        printf("TEST CASE: %s failed! Failed value:%d\n", __func__, z1);
    else if (z2 != 123)
        printf("TEST CASE: %s failed! Failed value:%d\n", __func__, z2);
    else if (z3 != 123)
        printf("TEST CASE: %s failed! Failed value:%d\n", __func__, z3);
    else
        printf("TEST CASE: %s succeeded!\n", __func__);
}

void test_exceed_long_limit() {
    long large = strtolong("92233720368547758078");
    long small = strtolong("-92233720368547758079");

    if (large != LONG_MAX) 
        printf("TEST CASE: %s failed! Failed value:%d\n", __func__, large);
    else if (small != LONG_MIN)
        printf("TEST CASE: %s failed! Failed value:%d\n", __func__, small);
    else
        printf("TEST CASE: %s succeeded!\n", __func__);
}

int main() {
    test_empty_string();
    test_positive_negative_long();
    test_decimal_number();
    test_invalid_number();
    test_string_with_alphabets_in_the_end();
    test_string_with_zeros();
    test_exceed_long_limit();
    return 0;
}
