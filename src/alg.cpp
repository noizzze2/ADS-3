// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t max_val = num;
    uint64_t n = num;

    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        if (n > max_val) {
            max_val = n;
        }
    }

    return max_val;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int length = 1;
    uint64_t n = num;

    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        length++;
    }

    return length;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound,
                        uint64_t rbound) {
    unsigned int best_num = lbound;
    unsigned int best_len = 0;

    for (uint64_t num = lbound; num <= rbound; num++) {
        unsigned int len = collatzLen(num);

        if (len > best_len) {
            best_len = len;
            best_num = num;
        }
    }

    *maxlen = best_len;
    return best_num;
}
