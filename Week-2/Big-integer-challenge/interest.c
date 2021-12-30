/*
TASK => Write a program interest.c which uses the double type to calculate
   interest on savings. It contains a function add which takes an amount
   of money, and a percentage rate of interest, and works out the total after adding
   the interest. And it has a function main which finds the total after adding 2.7 percent
   interest to 1000.0 pounds. Then extend the program so it can calculate interest based
   on an amount of monay and an interest rate entered by the user.
*/

#include <stdio.h>

double add(double amount, double interestRate) {
    amount = amount + (amount * interestRate / 100.0);
    return amount;
};

int main() {
    double a, i;
    printf("Enter your amount:\n");
    scanf("%lf", &a);
    printf("Enter interest rate:\n");
    scanf("%lf", &i);
    double total = add(a, i);
    printf("Adding %lf%% interest to %lf gives %lf\n", i, a, total);
    return 0;
};