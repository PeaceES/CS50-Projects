#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count; // it was important to declare this outside main so that it can be used in our own custom functions later

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1; // gotcha
    if (candidate_count > MAX)  // if there are more candidates than the allowed max
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2; // we're keeping count of the types of errors
    }
    for (int i = 0; i < candidate_count; i++) // going through each candidate
    {
        candidates[i].name = argv[i + 1]; // population the candidate's array (names) and vote count (0 for now)
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: "); // ask the user how many voters

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: "); // for every voter, get a name of their chosen candidate

        // Check for invalid vote
        if (!vote(name)) // it wwould be invalid if the name entered does not appear on any of the candidate[i].name lists
        {                // so it is a vote if we've counted it, else it is not a vote and this function is activated
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name) // the output of this function is boolean so it's either true or false
{
    for (int i = 0; i < (candidate_count); i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++; // the name matches a name in the candidates list
            return true;
        }
    }

    return false; // there was no match
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // sort the list, selection sort runs once to determine the highest candidate[i].vote
    // TODO
    int i = 0;
    candidate buffer;
    for (int j = i + 1; j < candidate_count; j++)
    {
        if (candidates[j].votes > candidates[i].votes)
        {
            // swap
            buffer = candidates[j];
            candidates[j] = candidates[i]; // candidate[j] is now in position[0] so it's the value that will be used to comp.
            candidates[i] = buffer;
        }
    }
    printf("%s\n", candidates[i].name); // print the name of the first winner
    // looking for ties: if any other vote(s) in the list candidates[j].votes is equal to candidates[i].votes,
    // their name should also be printed
    for (int j = 1; j < candidate_count; j++)
    {
        if (candidates[i].votes == candidates[j].votes)
        {
            printf("%s\n", candidates[j].name);
        }
    }
    return;
}