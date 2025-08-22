# Simple Constants
AMEX_PREFIX = {34, 37}  # Using a set for more efficient lookup
AMEX_LENGTH = 15

INVALID = "INVALID"  # Represents an invalid card

# Using a set for more efficient lookup
MASTERCARD_PREFIX = {51, 52, 53, 54, 55}

VISA_PREFIX = 4
VISA_MIN_LENGTH = 13
VISA_MAX_MASTERCARD_LENGTH = 16


# REGEX Constants
# ^(?:.{13}|.{15,16})$ means: any character with a length between 13 and 16, except 14
LENGTH_13_15_16_REGEX = r'^(?:.{13}|.{15,16})$'

# ^\d+$ means: only digits.
POSITIVE_INTEGER_REGEX = r'^\d+$'
