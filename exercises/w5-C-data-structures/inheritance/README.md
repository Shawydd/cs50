# Inheritance

## Problem to Solve

Complete the implementation of ```inheritance.c```, such that it creates a family of a specified generation size and assigns blood type alleles to each family member. The oldest generation will have alleles assigned randomly to them.

- The ```create_family``` function takes an integer (```generations```) as input and should allocate (as via ```malloc```) one ```person``` for each member of the family of that number of generations, returning a pointer to the ```person``` in the youngest generation.
    - For example, ```create_family(3)``` should return a pointer to a person with two parents, where each parent also has two parents.
    - Each ```person``` should have ```alleles``` assigned to them. The oldest generation should have alleles randomly chosen (as by calling the ```random_allele``` function), and younger generations should inherit one allele (chosen at random) from each parent.
    - Each person should have ```parents``` assigned to them. The oldest generation should have both ```parents``` set to ```NULL```, and younger generations should have ```parents``` be an array of two pointers, each pointing to a different parent.

- The ```free_family``` function should free every space allocated with ```malloc```.

---
Based on: [Inheritance - Walkthrough - CS50 Labs 2020](https://www.youtube.com/watch?v=9p7ddI3ozTY "https://www.youtube.com/watch?v=9p7ddI3ozTY")
