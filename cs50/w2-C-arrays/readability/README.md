# Readability

## Problem to Solve

In a file called ```readability.c``` in a folder called ```readability```, you’ll implement a program that calculates the approximate grade level needed to comprehend some text. Your program should print as output “Grade X” where “X” is the grade level computed, rounded to the nearest integer. If the grade level is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output “Grade 16+” instead of giving the exact index number. If the grade level is less than 1, your program should output “Before Grade 1”.

## Background

A number of “readability tests” have been developed over the years that define formulas for computing the reading level of a text. One such readability test is the Coleman-Liau index. The Coleman-Liau index of a text is designed to output that (U.S.) grade level that is needed to understand some text. The formula is

```index = 0.0588 * L - 0.296 * S - 15.8```

where ```L``` is the average number of letters per 100 words in the text, and ```S``` is the average number of sentences per 100 words in the text.

## Specification
For the purpose of this problem, we’ll consider any sequence of characters separated by a space to be a word (so a hyphenated word like “sister-in-law” should be considered one word, not three). You may assume that a sentence:

1. will contain at least one word;
2. will not start or end with a space; and
3. will not have multiple spaces in a row.

Under those assumptions, you might already be able to find a mathematical relationship between the number of words and the number of spaces.

---
Based on: [readability - CS50 Walkthroughs 2020](https://www.youtube.com/watch?v=AOVyZEh9zgE&t=1s "https://www.youtube.com/watch?v=AOVyZEh9zgE&t=1s")
