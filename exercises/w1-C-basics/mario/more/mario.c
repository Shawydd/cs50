#include <cs50.h>
#include <stdint.h>
#include <stdio.h>

typedef uint8_t BYTE;

// Prompts the user for a valid pyramid height (between 1 and 8)
BYTE pyramid_height(void);

// Constructs and prints a two-sided pyramid of the given height
void pyramid_creation(BYTE max_height);

int main(void)
{
    // Get the pyramid height from the user
    BYTE max_height = pyramid_height();

    // Build and print the pyramid
    pyramid_creation(max_height);

    return 0;
}

// Repeatedly asks the user for a height until a valid value (1-8) is entered
BYTE pyramid_height(void)
{
    int height;
    do
    {
        height = get_int("Enter the pyramid height (1-8): ");
    }
    while (height < 1 || height > 8);

    // Safe typecasting after input validation
    return (BYTE) height;
}

// Builds and prints a Mario-style double pyramid of the specified height
void pyramid_creation(BYTE max_height)
{
    const BYTE number_of_spaces = 2; // Spaces between the two sides of the pyramid
    BYTE max_length = max_height + number_of_spaces +
                         1; // Total line length for the print loop (increases by row)

    // Iterate through each row to construct the pyramid
    for (BYTE row = 0; row < max_height; row++)
    {
        BYTE hash_to_print = max_height - row - 1; // Number of leading spaces before left hashes

        // Iterate through each "column" on the current row
        for (BYTE col = 0; col < max_length; col++)
            // Print '#' if within the left or right pyramid; otherwise print space
            printf("%c", (col >= hash_to_print &&
                          (col < max_height || col >= max_height + number_of_spaces))
                             ? '#'
                             : ' ');

        max_length++; // Each subsequent row is one character longer for mirroring

        // Move to the next line after printing current row
        printf("\n");
    }
}
