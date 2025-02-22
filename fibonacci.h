#ifndef FIBONACCI_H
#define FIBONACCI_H

#include "bignum.h"
#include "cache.h"

typedef void (*fib_func_ptr)(int, struct bn *);
extern fib_func_ptr fibonacci_provider;

void fibonacci(int n, struct bn *result);

#endif
