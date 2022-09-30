#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


//function to check whether the input characters are all digits
bool only_digits(string s)
{
    char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    int a = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (s[i] == digit[j])
            {
                a++;
            }
        }
    }
    if (a == strlen(s))
    {
        return 0; // all are digits
    }

    return 1; // contain none digit
}








int main(int argc, string argv[])
{
    //make sure input only one key
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key;

    // make sure input is digit
    if (only_digits(argv[1]) == 0)
    {
        key = atoi(argv[1]); // change into integer
    }
    if (only_digits(argv[1]) == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");

    // alphabet
    char L_alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char U_alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};


    //encryption
    for (int i = 0; i < strlen(plaintext); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            int m = ((j + key)) % 26 ;
            if (plaintext[i] == L_alphabet[j])
            {
                printf("%c", L_alphabet[m]);
            }
            else if (plaintext[i] == U_alphabet[j])
            {
                printf("%c", U_alphabet[m]);
            }
            else if ((isalpha(plaintext[i]) == 0))
            {
                printf("%c", plaintext[i]);
                j = 26;
            }
        }
    }
    printf("\n");
}