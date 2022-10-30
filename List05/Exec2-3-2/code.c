#include <stdio.h>
#include <stdlib.h>

int *merge(int *vect, int p, int q, int r)
{
    int tam_l = (q - p) + 1;
    int tam_r = r - q;

    int left[tam_l], right[tam_r];

    for (int i = 0; i < tam_l; i++)
    {
        left[i] = vect[p + i];
    }

    for (int i = 0; i < tam_r; i++)
    {
        right[i] = vect[(q + 1) + i];
    }

    int n = tam_l + tam_r;

    int countL = 0, countR = 0;

    for (int i = p; i <= r; i++)
    {
        if (left[countL] <= right[countR] && (countL < tam_l))
        {
            vect[i] = left[countL];
            countL++;
        }
        else
        {
            vect[i] = right[countR];
            countR++;
        }
    }

    return vect;
}

int *ms_wrapper(int *vect, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        ms_wrapper(vect, p, q);
        ms_wrapper(vect, q + 1, r);
        return merge(vect, p, q, r);
    }

    return NULL;
}

int *mergesort(int *vect, int tam)
{
    return ms_wrapper(vect, 0, tam - 1);
}

int main()
{
    int n = 10;

    int *vect = malloc(n * sizeof(int));

    srand(20);

    for (int i = 0; i < n; i++)
    {
        vect[i] = rand() % 20;
    }

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", vect[i]);
    }

    mergesort(vect, n);

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", vect[i]);
    }

    printf("\n");

    return EXIT_SUCCESS;
}