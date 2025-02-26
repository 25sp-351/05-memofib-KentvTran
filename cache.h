#ifndef CACHE_H
#define CACHE_H

#include "fibonacci.h"

typedef void (*fib_func_ptr)(int, struct bn *);

fib_func_ptr init_cache(fib_func_ptr real_provider);
void cache_func(int n, struct bn *result);

#endif
