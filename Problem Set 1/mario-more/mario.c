#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // For each row
    for (int i = 0; i < n; i++)
    {
        // For each column

        // print blanks
        for (int j = n - i - 1; j > 0; j--)
        {
            printf(" ");
        }
        // print hashes
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        // print blanks
        for (int j = 0; j < 2; j++)
        {
            printf(" ");
        }
        // print hashes
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }


        // Move to next row
        printf("\n");
    }
}
