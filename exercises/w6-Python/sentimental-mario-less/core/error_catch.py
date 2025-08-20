# Import constants for validation
from utils.constants import LOWER_BOUND, UPPER_BOUND


def integer_check():
    while True:
        try:
            # Prompt user for input and attempt to convert to integer
            n = int(input("Height: "))

            # Check if the input is within the defined bounds
            if not LOWER_BOUND <= n <= UPPER_BOUND:
                # Raise an error if the input is out of bounds
                raise ValueError(
                    f"input out of bound: ({LOWER_BOUND}-{UPPER_BOUND})")

            return n  # Return the valid height

        except ValueError as ex:
            # Handle invalid inputs and provide feedback to the user
            print(f"Input error: {ex}. Try again.")
