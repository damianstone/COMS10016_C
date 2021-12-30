#include <stdio.h>

int nextHailstone(int x) {
    int next;
    switch (x % 2) {
        case 1: next = 3 * x + 1; break;
        default: next = x / 2;
    };

    return next;
} ;