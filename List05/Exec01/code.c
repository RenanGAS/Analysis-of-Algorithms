#include <stdio.h>
#include <stdlib.h>

int binarySearchR(int *vect, int i, int f, int elem)
{
    if (f >= i)
    {
        int m = i + ((f - i) / 2);

        if (vect[m] == elem)
        {
            return vect[m];
        }

        if (vect[m] > elem)
        {
            return binarySearchR(vect, i, m - 1, elem);
        }
        else if (vect[m] < elem)
        {
            return binarySearchR(vect, m + 1, f, elem);
        }
    }

    return -1;
}

int binarySearchR_wrapper(int *vect, int tam, int elem)
{
    return binarySearchR(vect, 0, tam - 1, elem);
}

int main()
{
    int tam = 20;
    int vect[tam];

    for (int i = 0; i < tam; i++)
    {
        vect[i] = i;
    }

    int elem = 19;

    // Busca Binária iterativa

    int i = 0;
    int f = tam - 1;

    while (f >= i)
    {
        int m = (i + f) / 2;

        if (vect[m] == elem)
        {
            printf("\nIterativa: %d\n", vect[m]);
            break;
        }

        if (vect[m] > elem)
        {
            f = m - 1;
        }
        else if (vect[m] < elem)
        {
            i = m + 1;
        }
    }

    int res = binarySearchR_wrapper(vect, tam, elem);

    printf("\nRecursiva: %d\n\n", res);

    return EXIT_SUCCESS;
}