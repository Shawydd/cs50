from core.checks import regex_check
from utils.constants import AMEX_LENGTH, AMEX_PREFIX, LENGTH_13_15_16_REGEX, MASTERCARD_PREFIX, VISA_MIN_LENGTH, VISA_MAX_MASTERCARD_LENGTH, VISA_PREFIX, INVALID


def card_validation(card_number):
    """
    Validates the type of card (AMEX, MASTERCARD, VISA) based on the card number.
    Returns the card type or None if invalid.
    """
    card_number_length = len(card_number)

    # Check if the card number matches the length pattern (13, 15, or 16 digits)
    if regex_check(LENGTH_13_15_16_REGEX, card_number):
        first_two_numbers = int(card_number[:2])

        # Check if it's an AMEX card
        if card_number_length == AMEX_LENGTH and first_two_numbers in AMEX_PREFIX:
            return 'AMEX'
        # Check if it's a MasterCard card
        elif card_number_length == VISA_MAX_MASTERCARD_LENGTH and first_two_numbers in MASTERCARD_PREFIX:
            return 'MASTERCARD'
        # Check if it's a VISA card
        elif (card_number_length == VISA_MIN_LENGTH or card_number_length == VISA_MAX_MASTERCARD_LENGTH) and int(card_number[0]) == VISA_PREFIX:
            return 'VISA'

    return None  # Return None if card type is not found


def luhn_algorithm(card_number):
    """
    Luhn algorithm to validate the card number.
    Returns the card type if valid, or 'INVALID' if invalid.
    """
    type_of_card = card_validation(card_number)

    if type_of_card is not None:
        luhn_sum = 0

        # Iterate through the card number from right to left
        for index, digit in enumerate(reversed(card_number)):
            num = int(digit)

            # If it's an odd index, multiply by 2
            if index % 2 == 1:
                num *= 2
                if num > 9:
                    num -= 9  # Subtract 9 if the result is greater than 9

            luhn_sum += num

        # Check if the last digit is 0, which means the card is valid
        if luhn_sum % 10 == 0:
            print(type_of_card)
            return

    # Print INVALID if the card is not valid
    print(INVALID)
