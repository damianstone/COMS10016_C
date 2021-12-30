

/*
es posible que desee empaquetar varios datos en
una variable. Por ejemplo, en los gráficos, un color suele
cuatro componentes de 8 bits (para rojo, verde, azul y opacidad)
empaquetado en un solo int de 4 bytes:

*/

int pack(char a[4])
{                       // function to pack 4 char into 1 int
    unsigned int r = 0; // initialise result with 0
    for (int i = 0; i < 4; i++)
    {                                         // pack one char at a time
        unsigned int p = (unsigned char)a[i]; // expand char to uint
        r = (p << (8 * i)) | r;               // shift p to right position within r
    }                                         // and combine with r via OR
    return (int)r;                            // cast to signed int and return packed values
};


void unpack(int packed, char a[4])
{
    unsigned int p = (unsigned int)packed; // use an unsigned int
    unsigned int m = 0xFF;                 // create mask of 8 rightmost set bits
    for (int i = 0; i < 4; i++)
    {                         // unpack one char at a time
        a[i] = (char)(m & p); // copy rightmost 8bits from p to a[i]
        if (i < 3)
            p = p >> 8; // right-shift p to get next 8bits
    }
};