#include "fibonacci.h"

#include <stdio.h>

fib_func_ptr fibonacci_provider;

void fibonacci(int n, struct bn *result) {
    struct bn a, b;
    bignum_init(&a);
    bignum_init(&b);

    if (n == 0) {
        bignum_from_int(result, 0);
        return;
    }
    if (n == 1) {
        bignum_from_int(result, 1);
        return;
    }

    struct bn fib1, fib2;
    bignum_init(&fib1);
    bignum_init(&fib2);

    // Recursive calls now use caching
    fibonacci_provider(n - 1, &fib1);
    fibonacci_provider(n - 2, &fib2);

    // Compute F(n) = F(n-1) + F(n-2)
    bignum_add(&fib1, &fib2, result);
}
