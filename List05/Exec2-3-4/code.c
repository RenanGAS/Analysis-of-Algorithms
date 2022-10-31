#include <stdio.h>
#include <stdlib.h>

void insert(int *vect, int pos)
{
    int posToInsert = -1;

    for (int i = 0; i < pos; i++)
    {
        if (vect[i] > vect[pos])
        {
            posToInsert = i;
            break;
        }
    }

    if (posToInsert == -1)
    {
        return;
    }

    int val = vect[pos];

    for (int i = pos; i > posToInsert; i--)
    {
        vect[i] = vect[i - 1];
    }

    vect[posToInsert] = val;

    return;
}

void insertionR(int *vect, int pos, int tam)
{
    if (pos == tam)
    {
        return;
    }

    insert(vect, pos);

    pos++;
    insertionR(vect, pos, tam);
}

void insertionR_wrapper(int *vect, int tam)
{
    insertionR(vect, 1, tam);

    return;
}

int main()
{
    int tam = 10;
    int *vect = malloc(tam * sizeof(int));

    for (int i = 0; i < tam; i++)
    {
        vect[i] = rand() % 20;
    }

    printf("\n");

    for (int i = 0; i < tam; i++)
    {
        printf(" %d", vect[i]);
    }

    printf("\n");

    insertionR_wrapper(vect, tam);

    printf("\n");

    for (int i = 0; i < tam; i++)
    {
        printf(" %d", vect[i]);
    }

    printf("\n");

    return EXIT_SUCCESS;
}