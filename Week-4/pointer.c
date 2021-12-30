#include <stdio.h>

int main()
{
    int i, j, k = 137;
    int a[3] = {2, 4, 6};
    int *p;                           // pointer to an int, not initialised
    p = &k;                           // p now points to the int k
    printf("k is stored at %p\n", p); // print the pointer
}

/*

El puntero p apunta a una posición aleatoria en la memoria hasta que
inicializado en última instancia, tendrá que apuntar a un int.
• Podemos inicializar un puntero asignando la dirección de
la variable int k a ella usando el operador de dirección &
que hemos visto antes al usar scanf:

*/