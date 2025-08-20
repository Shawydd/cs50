def half_pyramid(height):
    # Loop through 1 to height (inclusive) to print each row of the pyramid
    for i in range(1, height + 1):
        # Print spaces followed by the correct number of '#' for each row
        print(' ' * (height - i) + '#' * i)
