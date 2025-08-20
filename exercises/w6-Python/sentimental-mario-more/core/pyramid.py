from utils.constants import GAP


def full_pyramid(height):
    # Loop through 1 to height (inclusive) to print each row of the pyramid
    for i in range(1, height + 1):
        """
        Print spaces followed by the correct number of '#' for each row
        plus the GAP and the mirrored number of #
        """
        left_part = ' ' * (height - i) + '#' * i
        right_part = ' ' * GAP + '#' * i
        print(left_part + right_part)
