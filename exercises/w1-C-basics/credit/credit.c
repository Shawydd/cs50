#include <cs50.h>
#include <stdint.h> // using smaller integer types to save memory where large sizes aren't needed
#include <stdio.h>
#include <string.h> // strcmp for string comparison

typedef uint8_t BYTE;

// Runs the Luhn algorithm on the card number to check for validity
bool luhn_algorithm(long int card_number);

// Checks if the card number has the correct length and valid starting digits
char *first_step_validation(long int card_number);

// Computes integer powers of 10 without using math.h (avoids floating point calculations)
long int power_of_10(const BYTE exp);

// Prompts the user until a valid (non-negative) long integer is entered
long int user_input_validation(void);

// String used as the default value for an invalid card
char *INVALID = "INVALID";

int main(void)
{
    // Prompt the user and store their card number input
    long int card_number = user_input_validation();

    // Determine the card type based on number length and starting digits
    char *type_of_card = first_step_validation(card_number);
    // If type_of_card is "INVALID", skip further checks; otherwise, check Luhn validity
    if (strcmp(type_of_card, INVALID) != 0)
        if (luhn_algorithm(card_number))
            // If the card number fails the Luhn check, set its type to INVALID
            type_of_card = INVALID;

    printf("%s\n", type_of_card);

    return 0;
}

bool luhn_algorithm(long int card_number)
{
    long int luhn_sum = 0;
    long int modified_card_number;

    // Process digits two at a time: units place (added as-is), then tens place (possibly doubled)
    while (card_number != 0)
    {
        // Add the rightmost digit directly to the sum
        luhn_sum += card_number % 10;
        modified_card_number = (card_number / 10) % 10;
        /* For every second digit (from the right), double it and subtract 9 if result >= 10; then
        add to sum */
        luhn_sum += ((modified_card_number) * 2 > 9) ? ((modified_card_number) * 2 - 9)
                                                     : (modified_card_number) * 2;
        card_number /= 100; // Remove the two digits we just processed
    }

    // Return true if the total sum ends in zero, indicating a valid card number per Luhn algorithm
    return (luhn_sum % 10);
}

char *first_step_validation(long int card_number)
{
    // First two digits for identifying American Express cards
    const BYTE AMEX[] = {34, 37};
    // First two digits for identifying MasterCard cards
    const BYTE MASTERCARD[] = {51, 52, 53, 54, 55};
    // First digit for identifying Visa cards
    const BYTE VISA = 4;

    BYTE card_number_length = 0;
    long int temp_card_number = card_number;

    // Count how many digits are in the card number
    while (temp_card_number != 0)
    {
        temp_card_number /= 10;
        card_number_length++;
    }

    // Only proceed if the length matches known valid card formats (Visa, Amex, Mastercard)
    BYTE min_visa_length = 13, amex_length = 15, max_mastercard_visa_length = 16;
    if (card_number_length == min_visa_length || card_number_length == amex_length ||
        card_number_length == max_mastercard_visa_length)
    {
        // Check if it's a Visa by comparing the first digit and length
        if ((card_number / power_of_10(card_number_length - 1)) == VISA &&
            (card_number_length == min_visa_length ||
             card_number_length == max_mastercard_visa_length))
            return "VISA";

        // Extract the first two digits for Amex and Mastercard validation
        BYTE card_first_two_digits = (BYTE) (card_number / power_of_10(card_number_length - 2));

        // Check if the number matches any known Amex prefix with correct length
        BYTE amex_array_length = (BYTE) (sizeof(AMEX) / sizeof(AMEX[0]));
        for (BYTE i = 0; i < amex_array_length; i++)
            if (card_first_two_digits == AMEX[i] && card_number_length == amex_length)
                return "AMEX";

        // Check if the number matches any known Mastercard prefix with correct length
        BYTE mastercard_array_length = (BYTE) (sizeof(MASTERCARD) / sizeof(MASTERCARD[0]));
        for (BYTE i = 0; i < mastercard_array_length; i++)
            if (card_first_two_digits == MASTERCARD[i] &&
                card_number_length == max_mastercard_visa_length)
                return "MASTERCARD";
    }
    // If checks fail, return INVALID type
    return INVALID;
}

long int power_of_10(const BYTE exp)
{
    long int result = 1;
    // Iteratively multiply result by 10 to get 10^exp
    for (BYTE i = 0; i < exp; i++)
        result *= 10;

    return result;
}

long int user_input_validation(void)
{
    long int user_input;

    // Keep prompting until a non-negative number is entered
    do
    {
        user_input = get_long("Number: ");
    }
    while (user_input < 0);

    return user_input;
}
