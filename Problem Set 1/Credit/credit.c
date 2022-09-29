#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long n = get_long("Number: ");

    int a = 0; // sum of every second digit times 2 and sum of that digit
    int b = 0; // sum of every first digit
    int digit = 0;

    for (long i = n; i > 0; i = ((i - (i % 10)) / 10))
    {
        // get number of each digit
        int c = i % 10;
        digit = digit + 1;

        // get every second digit
        if (digit % 2 == 0)
        {
            int d = 2 * c;
            // summary of sum of every second digit
            for (int j = d; j > 0; j = ((j - (j % 10)) / 10))
            {
                int e = j % 10;
                a = a + e;
            }
        }

        // get every first digit
        if (digit % 2 == 1)
        {
            b = b + c;
        }
    }
    // sum of a and b
    int f = a + b;


    //check sum last digit 0
    if (f % 10 != 0)
    {
        printf("INVALID\n");

    }

    else
    {
        if (digit == 15)
        {
            long g = (n - (n % 10000000000000)) / 10000000000000;
            if (g == 34 || g == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");

            }
        }
        else if (digit == 16)
        {
            long g = (n - (n % 100000000000000)) / 100000000000000;
            long h = (n - (n % 1000000000000000)) / 1000000000000000;
            if (g == 51 || g == 52 || g == 53 || g == 54 || g == 55 || h == 4)
            {
                if (g == 51 || g == 52 || g == 53 || g == 54 || g == 55)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("VISA\n");
                }
            }

            else
            {
                printf("INVALID\n");

            }
        }
        else if (digit == 13)
        {
            long h = (n - (n % 1000000000000)) / 1000000000000;
            if (h == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");

            }
        }
        else if (digit != 13 && digit != 15 && digit != 16)
        {
            printf("INVALID\n");

        }

    }

}