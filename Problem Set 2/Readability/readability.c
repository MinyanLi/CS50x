#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);



int main(void)
{
    string s = get_string("Text: ");
    int l = count_letters(s);
    int w = count_words(s);
    int sen = count_sentences(s);
    //L is the average number of letters per 100 words in the text
    float L = (100.0 * l) / w;
    // S is the average number of sentences per 100 words in the text
    float S = (100.0 * sen) / w;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }


}






int count_letters(string text)
{
    int count = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            count += 1;
        }
    }
    return count;
}



int count_words(string text)
{
    int count = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (isspace(text[i]))
        {
            count += 1;
        }
    }
    return count + 1;
}



int count_sentences(string text)
{
    int count = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            count += 1;
        }
    }
    return count;
}
