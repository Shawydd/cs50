#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool argv_conditions(const char *argv);
void characters_substitution(const char *key);

int main(int argc, char *argv[])
{
    // Check correct number of arguments
    if (argc != 2)
    {
        printf("Error: wrong number of arguments\nUsage: ./substitution key\n");
        return 1;
    }

    // Validate key length and unique characters
    if (argv_conditions(argv[1]))
    {
        printf("Key must contain 26 unique characters\n");
        return 1;
    }

    // Apply substitution cipher
    characters_substitution(argv[1]);

    return 0;
}

bool argv_conditions(const char *argv)
{
    const unsigned int alphabet_length = 26;
    const unsigned int argv_len = strlen(argv);

    if (argv_len == alphabet_length)
    {
        // Check all characters are alphabetic
        for (unsigned int i = 0; i < argv_len; i++)
        {
            unsigned char temp = toupper((unsigned char) argv[i]);
            
            if (temp < 'A' || temp > 'Z')
                return true; // Non-alphabetic character found

            // Check for duplicate letters (case-insensitive)
            for (unsigned int j = i + 1; j < argv_len - 1; j++)
                if (temp == toupper((unsigned char) argv[j]))
                    return true; // Duplicate character found
        }
        return false; // Valid key
    }
    return true; // Invalid length
}

void characters_substitution(const char *key)
{
    char *text = get_string("plaintext: ");

    // Substitute each alphabetical character based on key
    for (unsigned int i = 0, text_length = strlen(text); i < text_length; i++)
    {
        // Check if character is an alphabetic letter
        if (isalpha((unsigned char) text[i]))
            // If uppercase, substitute using key with uppercase base
            // Else substitute using key with lowercase base (converted to lowercase)
            text[i] =
                isupper((unsigned char) text[i])
                    ? toupper(key[text[i] - 'A']) // Map uppercase letter to key character
                    : tolower(
                          key[text[i] - 'a']); // Map lowercase letter to lowercase key character
    }
    // Output ciphertext
    printf("ciphertext: %s\n", text);
}
