#include <stdio.h>

int main() {
    int num1;
    int num2;
    int result;
    printf("enter the first number\n");
    scanf("%d", &num1);
    printf("enter the second number\n");
    scanf("%d", &num2);
    result = num1 + num2;
    printf("the result of the sum is: %d\n", result);
    return 0;
};

/*

scanf() => to read the value entered. first arg = type of value. second arg = variable where the value will be stored.
%d => entered decimal number
& => to indicate the variable

*/