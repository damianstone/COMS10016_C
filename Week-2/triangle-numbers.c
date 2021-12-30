/* Find the n'th triangle number. */
#include <stdio.h>

// Find the sum of the numbers from 1 to n.
int sum(int n) {
    if (n == 1) return 1;
    else return n + sum(n - 1);
    }
    int main(void) {
    int n;
    printf("Enter n:\n");
    scanf("%d", &n);
    printf("The %dth triangle number is: %d\n", n, sum(n));
    return 0;
};