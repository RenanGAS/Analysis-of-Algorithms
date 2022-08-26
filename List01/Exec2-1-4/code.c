#include <stdio.h>
#include <stdlib.h>

#define mod2(X) X % 2

void randomBinSeq(int n, int *v)
{
    for (int i = 0; i < n; i++)
    {
        v[i] = mod2(rand());
    }
}

void printV(int n, int *v)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d", v[i]);
    }
}

int main()
{
    int n = 5, sum = 0, c_in = 0, vA[n], vB[n], vC[n + 1];

    randomBinSeq(n, vA);
    randomBinSeq(n, vB);

    for (int i = n - 1; i >= 0; i--)
    {
        sum = vA[i] + vB[i] + c_in;

        if (sum >= 2)
        {
            vC[i + 1] = mod2(sum);
            c_in = 1;
        }
        else
        {
            vC[i + 1] = sum;
            c_in = 0;
        }
    }

    vC[0] = c_in;

    printf("\n  ");
    printV(n, vA);
    printf("\n");

    printf("\n  ");
    printV(n, vB);
    printf("\n");

    printf("\n");
    printV(n + 1, vC);
    printf("\n");

    return EXIT_SUCCESS;
}