/* Find the area of paint I need. */
#include <stdio.h>

// Calculate area of walls and ceiling.
int area(int length, int width, int height) {
int sides = 2 * length * height;
int ends = 2 * width * height;
int ceiling = length * width;
return sides + ends + ceiling;
}

// Read room size and print area of paint.
int main(void) {
int length, width, height;
printf("Enter room length:\n");
scanf("%d", &length);
printf("Enter room width:\n");
scanf("%d", &width);
printf("Enter room height:\n");
scanf("%d", &height);
int total = area(length, width, height);
printf("The paint area is: %d\n", total);
return 0;
}

/*

Main => is always the last function because is the function that it will be called
%d\n => Conversion especification => its means print and integer in decimal format here
scanf() => enter an input

*/

