#include <cs50.h>
#include <stdio.h>

// Prompts the user to input a non-negative amount of change owed (in cents)
int user_input_validation(void);

// Calculates and prints the minimum number of coins needed for the given change
void coins_given(int money_to_change);

int main(void)
{
    // Get the amount of change owed from the user (in cents)
    int money_to_change = user_input_validation();

    // Calculate and print the minimum number of coins needed
    coins_given(money_to_change);

    return 0;
}

// Repeatedly prompt the user until a non-negative integer is entered
int user_input_validation(void)
{
    int user_input;
    do
    {
        user_input = get_int("Change owed: ");
    }
    while (user_input < 0);
    return user_input;
}

/* Determines the minimum number of US coins (quarters, dimes, nickels, pennies)
needed to make the given amount of change (in cents) and prints the total */
void coins_given(int money_to_change)
{
    // Coin denominations in cents
    const unsigned short penny = 1, nickel = 5, dime = 10, quarter = 25;

    int coin_count = 0;

    // Greedily subtract the largest possible coin from the remaining amount
    while (money_to_change > 0)
    {
        if (money_to_change >= quarter)
            money_to_change -= quarter;
        else if (money_to_change >= dime)
            money_to_change -= dime;
        else if (money_to_change >= nickel)
            money_to_change -= nickel;
        else
            money_to_change -= penny;
        coin_count++;
    }
    // Print the total number of coins used
    printf("%d\n", coin_count);
}
