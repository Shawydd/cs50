# Importing functions from core.error_catch and core.pyramid
from core.error_catch import integer_check
from core.pyramid import full_pyramid


def main():
    # Get a valid height from the user and print the full pyramid
    full_pyramid(integer_check())


# Run the main function if this script is executed directly
if __name__ == "__main__":
    main()
