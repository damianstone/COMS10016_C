// VIDEO 1

// COMPILE MULTIPLE FILES => 
//gcc -std=c11 - wall file1.c file2.c -lm -o file.

// HEADER FILE =>
//is a file that contains function prototypes
// for example print.c and print.h.

// VARIABLES => 
// could be auto, register, static, extern 

// FUNCTIONS => 
// Can be extern or static

// OPAQUE TYPES => 
// types are only declared in the header and defined in the c file.

// ENCAPSULATION => 
// protective wrapper. the user can only call functions no more. 


// VIDEO 2

// PREPROCESSOR => 
// run before the compiler

// MACRO => 
// identifier es replaced in the program with the replacement text before the program is compiled
// it can be defined with arguments of without it
#define INDENTIFIER REPLACEMENT
#define PI 3.14
#define DISC(radious) ((PI) * (radious) * (radious))

// # and ## => 
// # transform into a string
#define PRINT(x) printf(#x) // PRINT(Welcone) = printf("welcome")

// ## concatenate two tokens 
#define CONCAT(x,y) x##y 
int hello = 5;
printf("%d\n", CONCAT(hel, lo)); // prints 5

#error "Stopped before compilation" // stops the processor
#pragma startup f // run f() before main()
#pragma exit g // run g() before the program exits

// ENUM => 
// extern const variables
extern int const Club, Diamond, Heart, Spade;
typedef int suit;

