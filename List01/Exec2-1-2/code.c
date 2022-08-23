#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector[6] = {31, 41, 59, 26, 41, 58};

    // Reverse version of Insertion Sort

    int i, j, to_compare = 0;

    for (i = 1; i < 6; i++)
    {
        to_compare = vector[i];
        j = i - 1;

        while (j >= 0 && vector[j] < to_compare)
        {
            vector[j+1] = vector[j];
            j--;
        }

        vector[j+1] = to_compare;
    }
    
    // Test

    printf("\nTest\n");
    printf("\nvector = [");

    for (i = 0; i < 6; i++)
    {
        printf("%d", vector[i]);

        if (i != 5)
        {
            printf(", ");
        }
    }
    
    printf("]\n");
    

    return EXIT_SUCCESS;
}