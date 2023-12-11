#include <stdio.h>

int main()
{
    int i, j;
    int row = 10, column = 20;
    
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            if (i == (row / 2) && j == (column / 2))
            {
                printf("*");
            }
            else if (j == (column / 2) - i || j == (column / 2) + i)
            {
                printf("*");
            }
            else if (i == j && j <= column / 2)
            {
                printf("*");
            }
            else if (i + j == row - 1 && j >= column / 2)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}