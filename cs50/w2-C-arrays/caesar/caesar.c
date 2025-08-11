#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Return true if argv contains any non-digit character
bool argv_conditions(const char *argv);

// Perform Caesar cipher encryption with the given key
void caesar_cipher(const unsigned int key);

int main(int argc, char *argv[])
{
    char *usage = "Usage: ./caesar key";
    // Check for correct number of command-line arguments
    if (argc != 2)
    {
        printf("Error: wrong number of arguments\n%s\n", usage);
        return 1;
    }

    // Validate that argv[1] contains only digits
    if (argv_conditions(argv[1]))
    {
        printf("%s\n", usage);
        return 1;
    }

    // Convert key from string to integer (no strtoul)
    caesar_cipher(atoi(argv[1]));

    return 0;
}

bool argv_conditions(const char *argv)
{
    // Check each character for non-digit
    for (unsigned int i = 0, argv_len = strlen(argv); i < argv_len; i++)
        if (argv[i] < '0' || argv[i] > '9')
            return true;

    return false;
}

void caesar_cipher(const unsigned int key)
{
    // Prompt user for plaintext input
    char *text = get_string("plaintext: ");

    // Encrypt each alphabetical character using Caesar cipher
    for (unsigned int i = 0, text_length = strlen(text); i < text_length; i++)
        if (isalpha((unsigned char) text[i]))
        {
            // Set base to 'A' or 'a' depending on upper or lower case
            char base = isupper((unsigned char) text[i]) ? 'A' : 'a';
            text[i] = (text[i] - base + key) % 26 + base;
        }

    // Print the resulting ciphertext
    printf("ciphertext: %s\n", text);
}
