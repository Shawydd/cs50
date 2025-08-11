#include <cs50.h>
#include <stdio.h>

// Prompts the user for the pyramid's height (between 1 and 8)
int pyramid_height(void);

// Prints a pyramid of a given height
void pyramid_creation(int max_height);

int main(void)
{
    // Get the desired height of the pyramid from the user
    int max_height = pyramid_height();

    // Construct and print the pyramid
    pyramid_creation(max_height);

    return 0;
}

// Prompt the user until a valid height is entered
int pyramid_height(void)
{
    int height;
    do
    {
        height = get_int("Enter the pyramid height: ");
    }
    while (height < 1);
    // Safe typecasting post validation
    return height;
}

// Builds and prints the pyramid line by line
void pyramid_creation(int max_height)
{
    // Iterate through each row of the pyramid
    for (int row = 0; row < max_height; row++)
    {
        // Calculate the number of leading spaces for alignment
        int hash_to_print = max_height - row - 1;

        // Iterate through each column in the current row
        for (int col = 0; col < max_height; col++)
            // Print '#' if column index is at or beyond the start of bricks, else print space
            printf("%c", (col >= hash_to_print) ? '#' : ' ');

        // Move to the next line after finishing the current row
        printf("\n");
    }
}
