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


int find_min(void)
{
    int min = voter_count;
    for (int i = 1; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false)
        {
            if (candidates[i].votes < min)
            {
                min = candidates[i].votes;
            }
        }
    }
    return min;
}




int main(void)
{
    // mock candidates 1
    candidates[0].name = "Alice";
    candidates[1].name = "Bob";
    candidates[2].name = "Charlie";
    candidates[0].votes = 3;
    candidates[1].votes = 5;
    candidates[2].votes = 2;
    candidates[0].eliminated = false;
    candidates[1].eliminated = false;
    candidates[2].eliminated = true;

    // mock voter_count
    voter_count = 3;

    // mock candidate_count
    candidate_count = 3;

    printf("%i\n", find_min());

}