#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
bool recursive_lock_check(int winner, int loser);
void print_winner(void);
bool winner_flag(int index);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}
// --------------------------------------------------------------------------------------------------------------------------------------
// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // Search candidates for name match and record their index in preferences
    for (int i = 0; i < candidate_count; i++)
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }

    return false; // Invalid candidate name
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    /* For each candidate preferred over another,
    increment the count of voters who prefer ranks[i] over ranks[j] */
    for (int i = 0; i < candidate_count; i++)
        for (int j = i + 1; j < candidate_count; j++)
            preferences[ranks[i]][ranks[j]]++;

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // Compare every pair of candidates
    for (int i = 0; i < candidate_count; i++)
        for (int j = i + 1; j < candidate_count; j++)
            // Only add pairs where there is a clear preference
            if (preferences[i][j] != preferences[j][i])
            {
                // Determine the winner and loser for this pair
                if (preferences[i][j] > preferences[j][i])
                {
                    pairs[pair_count].winner = i;
                    pairs[pair_count].loser = j;
                }
                else
                {
                    pairs[pair_count].winner = j;
                    pairs[pair_count].loser = i;
                }
                pair_count++;
            }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Bubble sort pairs array by margin of victory
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int i = 0; i < pair_count - 1; i++)
        {
            // Swap pairs if the next pair has a stronger victory margin
            if (preferences[pairs[i].winner][pairs[i].loser] <
                preferences[pairs[i + 1].winner][pairs[i + 1].loser])
            {
                int winner_change[] = {pairs[i + 1].winner, pairs[i + 1].loser};
                pairs[i + 1].winner = pairs[i].winner, pairs[i + 1].loser = pairs[i].loser;

                pairs[i].winner = winner_change[0], pairs[i].loser = winner_change[1];

                flag = true;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // For each pair in sorted order, lock it unless it creates a cycle
    for (int i = 0; i < pair_count; i++)
        if (!recursive_lock_check(pairs[i].winner, pairs[i].loser))
            locked[pairs[i].winner][pairs[i].loser] = true;

    return;
}

// Recursive function to check if locking a pair would create a cycle
bool recursive_lock_check(int winner, int loser)
{
    // Check if loser links back to winner directly or through a chain
    for (int i = 0; i < candidate_count; i++)
        if (loser == winner || (locked[loser][i] && recursive_lock_check(winner, i)))
            return true;

    return false;
}

// Print the winner of the election
void print_winner(void)
{
    // The winner is the candidate with no edges pointing to them
    for (int i = 0; i < candidate_count; i++)
        if (winner_flag(i))
        {
            printf("%s\n", candidates[i]);
            return;
        }
}

// Helper function to determine if candidate is source of the graph
bool winner_flag(int index)
{
    // Candidate is winner only if no candidate is locked over them
    for (int i = 0; i < candidate_count; i++)
        if (locked[i][index])
            return false;

    return true;
}
