#include "cache.h"

#include <stdio.h>

#define MAX_MEMOIZED 100
#define ARRAY_SIZE (MAX_MEMOIZED + 1)

fib_func_ptr _original_provider;
struct bn
    _memoization_data[ARRAY_SIZE];  // stores the value of the fibonacci number

// tracks if the value is cached or not
static int _is_cached[ARRAY_SIZE] = {0};  // 0 = not cached, 1 = cached

void cache_func(int n, struct bn *result) {

    //  checks if the value is already cached
    if (n <= MAX_MEMOIZED && _is_cached[n]) {
        bignum_assign(result, &_memoization_data[n]);
        return;
    }

    // Compute Fibonacci and store in cache
    (*_original_provider)(n, &_memoization_data[n]);

    if (n <= MAX_MEMOIZED)
        _is_cached[n] = 1;
    bignum_assign(result, &_memoization_data[n]);
}

fib_func_ptr init_cache(fib_func_ptr real_provider) {
    for (int i = 0; i < ARRAY_SIZE; i++)
        bignum_init(&_memoization_data[i]);

    // Preload base cases
    bignum_from_int(&_memoization_data[0], 0);
    _is_cached[0] = 1;

    bignum_from_int(&_memoization_data[1], 1);
    _is_cached[1]      = 1;

    _original_provider = real_provider;
    return cache_func;
}
