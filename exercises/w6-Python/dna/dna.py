import core.checks as checks
from utils.constants import ARGUMENT_TO_CHECK

import sys

# --------------------------------------------------------------------------------------------------------------------------------------
def main():

    # Check for command-line usage
    if not len(sys.argv) == ARGUMENT_TO_CHECK:
        print("Error: Invalid number of arguments. "
              "Usage: python dna.py databases/database_name.csv sequences/sequence_name.txt")
        sys.exit(1)

    try:
        # Read database file into a variable
        fieldnames, rows = checks.fieldnames_and_immutable_rows(sys.argv[1])

        # Read DNA sequence file into a variable
        dna_sequence = checks.file_read(sys.argv[2])

    except FileNotFoundError as ex:
        print(f"Input error: {ex}.")
        sys.exit(2)

    # Exit if one of the two file is empty
    if not fieldnames or not dna_sequence:
        print(f"Error: one or more file were empty")
        sys.exit(1)

    # Find longest match of each STR in DNA sequence
    diz = {field: str(longest_match(dna_sequence, field))
           for field in fieldnames if field != "name"}

    # Check database for matching profiles
    for row in rows:
        if all(row[index] == value for index, value in diz.items()):
            print(row["name"])
            return

    print("No match")
# --------------------------------------------------------------------------------------------------------------------------------------

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in sequence, return longest run found
    return longest_run

if __name__ == "__main__":
    main()
