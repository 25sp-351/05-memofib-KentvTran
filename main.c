#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bignum.h"
#include "cache.h"
#include "fibonacci.h"

int main(int argc, char *argv[]) {

    // Parse command line argument
    int test_val;
    if (argc < 2 || 1 != sscanf_s(argv[1], "%d", &test_val) || test_val < 0)
        return 1;

    fibonacci_provider = init_cache(fibonacci);

    // Compute Fibonacci numbers
    for (int ix = 0; ix <= test_val; ix++) {
        struct bn result;  // uses bn struct as long doesn't store large numbers for fibonacci
        bignum_init(&result);

        fibonacci_provider(ix, &result);

        char hex_str[1024];  // bignum_to_string function prints out in HEX not Decimals
        bignum_to_string(&result, hex_str, sizeof(hex_str));

        // couldn't find a way to use bn to print out in decimal so after 94 it doesn't work
        unsigned long long decimal_value =
            strtoull(hex_str, NULL, 16);  // converts hex to decimal

        printf("Fibonacci(%d) = HEX: %s = Decimal: %llu \n", ix, hex_str,
               decimal_value);
    }

    return 0;
}
