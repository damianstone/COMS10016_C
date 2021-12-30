#include <stdio.h>

// arguments with commmand line 
int main(int n, char *args[]) {
    for (int i = 0; i < n; i++) {
        printf("Argument %d is %s\n", i, args[i]);
    }

    return 0;
} 