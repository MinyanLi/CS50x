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


void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[preferences[i][j]].eliminated == false)
            {
                candidates[preferences[i][j]].votes += 1;
                break;
            }
        }
    }
    return;
}






int main(void)
{

    // mock candidates 1
    //candidates[0].name = "Alice";
    //candidates[1].name = "Bob";
    //candidates[2].name = "Charlie";
    //candidates[0].votes = 0;
    //candidates[1].votes = 0;
    //candidates[2].votes = 0;
    //candidates[0].eliminated = false;
    //candidates[1].eliminated = false;
    //candidates[2].eliminated = false;


    // mock candidates 2
    candidates[0].name = "Alice";
    candidates[1].name = "Bob";
    candidates[2].name = "Charlie";
    candidates[0].votes = 0;
    candidates[1].votes = 0;
    candidates[2].votes = 0;
    candidates[0].eliminated = true;
    candidates[1].eliminated = false;
    candidates[2].eliminated = false;

    // mock preferce 1
    preferences[0][0] = 0;
    preferences[0][1] = 1;
    preferences[0][2] = 2;
    preferences[1][0] = 0;
    preferences[1][1] = 1;
    preferences[1][2] = 2;
    preferences[2][0] = 1;
    preferences[2][1] = 2;
    preferences[2][2] = 0;

    // mock voter_count
    voter_count = 3;

    // mock candidate_count
    candidate_count = 3;




    tabulate();
    for (int i = 0; i < candidate_count; i ++)
    {
        printf("%s %i\n", candidates[i].name, candidates[i].votes);
    }



}