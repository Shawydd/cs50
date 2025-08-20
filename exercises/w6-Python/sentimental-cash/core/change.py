from decimal import Decimal

# Define coin denominations (QUARTERS, DIMES, NICKELS, PENNIES)
coin_to_change = (Decimal('.25'), Decimal(
    '.1'), Decimal('.05'), Decimal('.01'))


def change_result(coins):
    # Convert input to Decimal to handle floating-point precision issues
    coins = Decimal(coins).quantize(Decimal('0.01'))
    change_counter = 0

    # Keep subtracting coins until all value is converted
    while coins > 0:
        coins = coin_change(coins)
        change_counter += 1

    return change_counter


def coin_change(coins):
    # Subtract the largest possible coin from the remaining amount
    for coin in coin_to_change:
        if coins >= coin:
            # Return the new amount after subtracting the coin, rounded to 2 decimals
            return (coins - coin).quantize(Decimal('0.01'))
