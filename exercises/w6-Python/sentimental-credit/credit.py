from core.checks import integer_only_string_check
from core.luhn import luhn_algorithm


def main():
    # Get a valid card number from the user
    card_number = integer_only_string_check()
    # Validate the card number using the Luhn algorithm
    luhn_algorithm(card_number)


if __name__ == "__main__":
    main()
