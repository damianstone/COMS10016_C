/* Find the square root. */
#include <math.h>
#include <stdio.h>
// Square root (like sqrt) via Newton Algorithm
double root(double x) {
    double r = x / 2.0; // first guess
    double epsilon = 1E-14;
    while (fabs(r - x / r) > epsilon)
    {
        r = (r + x / r) / 2.0; // Newton step
    };
    return r;
}

int main() {
    double x;
    printf("Enter number:\n");
    scanf("%lf", &x);
    printf("The square root is: %lf\n", root(x));
    return 0;
}