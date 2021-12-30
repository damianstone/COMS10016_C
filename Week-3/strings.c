// char conversion without quotes => %hhi
// with quotes => %c
// '\0' => null character
// '0' => convert digit into a number o uppercase letter

#include <stdio.h>
#include <string.h>

//check identity
void checkIdentity(char str1[], char str2[]) {
    if (str1 == str2)
        printf("Strings are identical\n.");
    else
        printf("Strings are not identical\n.");
};

//compare content
void compareContent(char str1[], char str2[]) {
    if (strcmp(str1, str2) == 0) printf("Same Content \n");
    else printf("different content \n");
};


int main() {

    char c = 65;
    char e = 'A';
    printf("%c %hhi \n", c, e); // A 65

    char textA[3] = {72, 105, 0};
    printf("%s\n", textA); // prints "Hi"

    char textB[3] = {'H', 'i', '\0'};
    char textC[8] = " there!";
    printf("%s%s\n", textB, textC); // hi there!

    // length of a string
    char text[] = {'H', 'i', '\0', 'L', 'o', '\0'};
    int length = strlen(text);
    printf("%d %s\n", length, text); // prints “2 Hi”

    char str1[] = "Hi";
    char str2[] = "chupa la callampa aweonao";

    checkIdentity(str1, str2); // prints ‘not identical’
    checkIdentity(str1, str1); // prints ‘are identical’

    compareContent(str1, str2); // print "same content"

    // copy strings
    char str3[30];
    strcpy(str3, str2); // => copy(to, from)
    printf("%s\n", str3);

    return 0;
};