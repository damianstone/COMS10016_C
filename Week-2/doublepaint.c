/* Find the area of paint I need. */
#include <stdio.h>

// Calculate area of walls and ceiling.
double area(double length, double width, double height) {
double sides = 2 * length * height;
double ends = 2 * width * height;
double ceiling = length * width;
return sides + ends + ceiling;
}

// Read room size and print area of paint.
int main(void) {
double length, width, height; // double => commonly used to represent real numbers
printf("Enter room length:\n");
scanf("%lf", &length);
printf("Enter room width:\n");
scanf("%lf", &width);
printf("Enter room height:\n");
scanf("%lf", &height);
double total = area(length, width, height);
printf("The paint area is: %lf\n", total);
return 0;
}
