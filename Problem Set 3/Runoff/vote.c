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





bool vote(int voter, int rank, string name)
{
    for (int j = 0; j < candidate_count; j++)
    {
        if (strcmp(name, candidates[j].name) == 0)
        {
            preferences[voter][rank] = j;
            return true;
        }
    }
    return false;
}





int main(void)
{
    // mock candidates
    candidates[0].name = "Alice";
    candidates[1].name = "Bob";
    candidates[2].name = "Charlie";
    candidates[0].votes = 0;
    candidates[1].votes = 0;
    candidates[2].votes = 0;
    candidates[0].eliminated = false;
    candidates[1].eliminated = false;
    candidates[2].eliminated = false;

    // mock voter_count
    voter_count = 3;

    // mock candidate_count
    candidate_count = 3;


    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            //prompt voter for their preference
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // print preference table
    printf(" every row is different voter preference\n every column is the rank of different voters\n number is candidate number\n" );
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i ", preferences[i][j]);
        }
        printf("\n");
    }

}
