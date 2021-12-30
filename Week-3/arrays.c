/* Average a sequence of numbers */
#include <stdio.h>

// Calculate average of numbers
double avg(int n, double numbers[n]) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }

    return sum / n;
}

int main(void) {
    int n;
    printf("How many numbers to average:\n");
    scanf("%d", &n);
    double numbers[n];

    for (int i = 0; i < n; i++) {
        printf("Enter number no %d:\n", i + 1);
        scanf("%lf", &numbers[i]);
    }

    printf("Average is: %lf\n", avg(n, numbers));
    return 0;
}


// Differetns arrays
array[2] = {2, 3};
array2D[2][3] = {{1, 2, 3}, {4, 5, 6}};
seq[] = {10, 11, 12};