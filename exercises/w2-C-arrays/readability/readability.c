#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Calculate the coleman lieu index
short int coleman_lieu_index(char *user_input);

// Print grade level output based on index value
void grade_result(short int index);

int main(void)
{
    // Prompt user for input text
    char *user_input = get_string("Text: ");

    // Compute the Coleman-Liau index for the input
    short int index = coleman_lieu_index(user_input);

    grade_result(index);

    return 0;
}

short int coleman_lieu_index(char *user_input)
{
    unsigned int letters = 0, sentences = 0,
                 words = 1; // words starts at 1 assuming at least one word

    // Iterate through each character in the input string
    for (unsigned int i = 0, user_input_length = strlen(user_input); i < user_input_length; i++)
    {
        if (isalpha(user_input[i]))
            letters++; // Count alphabetic characters as letters
        else if (isspace(user_input[i]))
            words++; // Count whitespace as word separators
        else if (user_input[i] == '.' || user_input[i] == '!' || user_input[i] == '?')
            sentences++; // Count '.', '!' and '?' as sentence endings
    }

    // Apply Coleman-Liau formula, casting to float to avoid integer division
    return (short int) (0.0588 * (letters / (float) words) * 100 -
                        0.296 * (sentences / (float) words) * 100 - 15.3);
}

void grade_result(short int index)
{
    short int min_grade_value = 1, max_grade_value = 16;

    if (index < min_grade_value)
        printf("Before Grade %d\n", min_grade_value);
    else if (index > max_grade_value)
        printf("Grade %d+\n", max_grade_value);
    else
        printf("Grade %d\n", index);
}
