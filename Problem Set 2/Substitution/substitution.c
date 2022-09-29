#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>


bool twenty_six_char(string key);
bool all_alpha(string key);
bool contain_repeat(string key);


int main(int argc, string argv[])
{
    // validate key
    if (argc != 2)
    {
        printf("Usage: .substitution KEY\n");
        return 1;
    }

    if (twenty_six_char(argv[1]) == 0)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    if (all_alpha(argv[1]) == 0)
    {
        printf("Key must contain alphabetic characters.\n");
        return 1;
    }

    if (contain_repeat(argv[1]))
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }

    string input = get_string("plaintext: ");

    // cipher
    string alpha = "abcdefghijklmnopqrstuvwxyz";

    int input_len = strlen(input);
    char cipher_s[input_len];

    char low_key[26];
    for (int i = 0; i < 26; i++)
    {
        low_key[i] = tolower(argv[1][i]);
    }


    for (int a = 0; a < input_len; a++)
    {
        if (isupper(input[a]))
        {
            int b = tolower(input[a]);
            for (int c = 0; c < 26; c++)
            {
                if (b == alpha[c])
                {
                    cipher_s[a] = toupper(low_key[c]);
                }
            }
        }
        else if (islower(input[a]))
        {
            for (int c = 0; c < 26; c++)
            {
                if (input[a] == alpha[c])
                {
                    cipher_s[a] = low_key[c];
                }
            }
        }
        else
        {
            cipher_s[a] = input[a];
        }
    }



    printf("ciphertext: ");
    for (int i = 0; i < input_len; i ++)
    {
        printf("%c", cipher_s[i]);
    }
    printf("\n");

}


bool twenty_six_char(string key)
{
    int len = strlen(key);
    if (len == 26)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool all_alpha(string key)
{
    int len = strlen(key);
    for (int i = 0; i < len; i++)
    {
        if (isalpha(key[i]) == 0)
        {
            return false;
        }
    }
    return true;
}


bool contain_repeat(string key)
{
    char low_key[26];
    for (int i = 0; i < 26; i++)
    {
        low_key[i] = tolower(key[i]);
    }



    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (low_key[i] == low_key[j])
            {
                return true;
            }
        }
    }
    return false;
}


