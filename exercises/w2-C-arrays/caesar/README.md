# Caesar

# Problem to Solve

| plaintext | H | E | L | L | O |
|----------|---|---|---|---|---|
| key      | 1 | 1 | 1 | 1 | 1 |
| ciphertext | I | F | M | M | P |

Design and implement a program, ```caesar```, that encrypts messages using Caesar’s cipher.

- Implement your program in a file called ```caesar.c``` in a directory called ```caesar```.
- Your program must accept a single command-line argument, a non-negative integer. Let’s call it
 for the sake of discussion.
- If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with ```printf```) and return from ```main``` a value of ```1``` (which tends to signify an error) immediately.
- If any of the characters of the command-line argument is not a decimal digit, your program should print the message ```Usage: ./caesar key``` and return from ```main``` a value of ```1```.
- Do not assume that __k__ will be less than or equal to 26. Your program should work for all non-negative integral values of __k__ less than $2^{31} - 26$. In other words, you don’t need to worry if your program eventually breaks if the user chooses a value for __k__ that’s too big or almost too big to fit in an ```int``` (recall that an int can overflow). But, even if __k__ is greater than __26__, alphabetical characters in your program’s input should remain alphabetical characters in your program’s output. For instance, if __k__ is __27__, ```A``` should not become ```\``` even though ```\``` is __27__ positions away from ```A``` in ASCII, per [<u>asciitable.com</u>](https://www.asciitable.com/ "https://www.asciitable.com/"); ```A``` should become ```B```, since ```B``` is __27__ positions away from ```A```, provided you wrap around from ```Z``` to ```A```.
- Your program must output ```plaintext```: (with two spaces but without a newline) and then prompt the user for a ```string``` of plaintext (using ```get_string```).
- Your program must output ```ciphertext```: (with one space but without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext “rotated” by k positions; non-alphabetical characters should be outputted unchanged.
- Your program must preserve case: capitalized letters, though rotated, must remain capitalized letters; lowercase letters, though rotated, must remain lowercase letters.
- After outputting ciphertext, you should print a newline. Your program should then exit by returning ```0``` from ```main```.

---
Based on: [caesar - CS50 Walkthroughs 2019](https://www.youtube.com/watch?v=V2uusmv2wxI "https://www.youtube.com/watch?v=V2uusmv2wxI")
