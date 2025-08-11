#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Calculate word score for each player
void players_total_score(char *players[], unsigned int players_score[]);

// Check if there is a winner or if it's a tie
void win_or_tie(unsigned int players_score[]);

const unsigned short int LETTER_SCORES[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                                            1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

const unsigned int NUMBER_OF_PLAYERS = 2;

int main(void)
{
    // Array to store each player's input string
    char *players[NUMBER_OF_PLAYERS];
    // Array to keep track of each player's score, initialized to zero
    unsigned int players_score[NUMBER_OF_PLAYERS] = {0};

    // Prompt each player to input their word
    for (unsigned int i = 0; i < NUMBER_OF_PLAYERS; i++)
        players[i] = get_string("Player %d: ", i + 1);

    players_total_score(players, players_score);

    win_or_tie(players_score);

    return 0;
}

void players_total_score(char *players[], unsigned int players_score[])
{
    // Loop through each player's word to calculate their total score
    for (unsigned int i = 0; i < NUMBER_OF_PLAYERS; i++)
        // Get the length once before inner loop for efficiency
        for (unsigned int j = 0, p_word_len = strlen(players[i]); j < p_word_len; j++)
            // Consider only alphabetic characters for scoring
            if (isalpha(players[i][j]))
                // Convert to uppercase and get score from LETTER_SCORES array
                players_score[i] += LETTER_SCORES[toupper(players[i][j]) - 'A'];
}

void win_or_tie(unsigned int players_score[])
{
    // Initialize winner variables with the first player's score and position
    unsigned int winner = players_score[0], winner_pos = 0;
    bool ties = false;

    // Compare scores of the remaining players to find the highest scorer
    for (unsigned int i = 1; i < NUMBER_OF_PLAYERS; i++)
    {
        if (players_score[i] > winner)
        {
            // New highest score found, update winner info and reset tie flag
            winner = players_score[i];
            winner_pos = i;
            ties = false;
        }
        else if (players_score[i] == winner)
            // Score matches current highest, mark as tie
            ties = true;
    }

    // Print result: either a tie or the winning player number (1-based)
    ties ? printf("Tie\n") : printf("Player %d wins!\n", winner_pos + 1);
}
