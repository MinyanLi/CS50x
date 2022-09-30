#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9
int preferences[MAX_VOTERS][MAX_CANDIDATES];

typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;
candidate candidates[MAX_CANDIDATES];

int voter_count;
int candidate_count;



bool print_winner(void)
{
    float threshold = voter_count / 2.0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false)
        {
            if (candidates[i].votes > threshold)
            {
                printf("%s\n", candidates[i].name);
                return true;
            }
        }

    }
    return false;
}





int main(void)
{
    // mock candidates 1
    candidates[0].name = "Alice";
    candidates[1].name = "Bob";
    candidates[2].name = "Charlie";
    candidates[0].votes = 2;
    candidates[1].votes = 1;
    candidates[2].votes = 0;
    candidates[0].eliminated = true;
    candidates[1].eliminated = false;
    candidates[2].eliminated = false;

    // mock voter_count
    voter_count = 3;

    // mock candidate_count
    candidate_count = 3;

    print_winner();
}