from re import match
from utils.constants import POSITIVE_INTEGER_REGEX


def integer_only_string_check():
    """
    Prompts the user to enter a valid card number.
    Returns the card number as a string.
    """
    while True:
        try:
            user_input = input("Please enter the card number: ")

            # Check if the input matches the regex for a valid card number
            if not regex_check(POSITIVE_INTEGER_REGEX, user_input):
                raise ValueError(
                    "invalid card number (digits only)")

            return user_input  # Return the valid card number as a string

        except ValueError as ex:
            print(f"Input error: {ex}. Try again.")


def regex_check(regex, input):
    # Returns True if input matches the regex pattern, False otherwise
    return bool(match(regex, input))
