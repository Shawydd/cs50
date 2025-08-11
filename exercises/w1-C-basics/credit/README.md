# Credit

## Problem to Solve

In the file called ```credit.c``` in the ```credit``` directory, write a program that prompts the user for a credit card number and then reports (via ```printf```) whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein. So that we can automate some tests of your code, we ask that your program’s last line of output be ```AMEX\n``` or ```MASTERCARD\n``` or ```VISA\n``` or ```INVALID\n```, nothing more, nothing less. For simplicity, you may assume that the user’s input will be entirely numeric (i.e., devoid of hyphens, as might be printed on an actual card) and that it won’t have leading zeroes.

Most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:

1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
2. Add the sum to the sum of the digits that weren’t multiplied by 2.
3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

Consider the below representative of how your own program should behave when passed a valid credit card number.
```
Number: 4003600000000014
VISA
```
But it’s up to you to catch inputs that are not credit card numbers (e.g., a phone number), even if numeric:
```
Number: 6176292929
INVALID
```
---
Based on: [credit - CS50 Walkthroughs 2019](https://www.youtube.com/watch?v=dF7wNjsRBjI "https://www.youtube.com/watch?v=dF7wNjsRBjI")
