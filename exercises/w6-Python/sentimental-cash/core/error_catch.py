def float_check():
    while True:
        try:
            # Prompt user for input and attempt to convert to integer
            user_input = (input("Change: "))

            num = float(user_input)
            # Check if the input is within the defined bounds
            if num < 0:
                # Raise an error if the input is out of bounds
                raise ValueError(
                    f"invalid Change")

            if '.' in user_input and len(user_input.split('.')[1]) > 2:
                # Raise an error if the input has more than 2 decimal places
                raise ValueError(
                    f"input with more than 2 decimal places")

            return num  # Return the valid change

        except ValueError as ex:
            # Handle invalid inputs and provide feedback to the user
            print(f"Input error: {ex}. Try again.")
