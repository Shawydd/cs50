// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];  // Word stored in this node
    struct node *next;      // Pointer to next node in linked list
} node;

// Number of buckets in hash table, set to LENGTH (max word length)
const unsigned int N = LENGTH;
unsigned int hash_size = 0; // Tracks number of words loaded

// Hash table: array of pointers to nodes
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Traverse linked list at bucket given by hash(word)
    for (node *ptr = table[hash(word)]; ptr != NULL; ptr = ptr->next)
        // Case-insensitive comparison of stored word and input word
        if (strcasecmp(ptr->word, word) == 0)
            return true; // Word found

    return false; // Word not found
}

// Hashes word to a number (bucket index)
// Hash, in this case, is the length of the word minus one
unsigned int hash(const char *word)
{
    return strlen(word) - 1;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        printf("Could not open input file.\n");
        return false;
    }

    // Buffer to hold each word read from file
    char *word = malloc((LENGTH + 1) * sizeof(char));

    if (word == NULL)
    {
        printf("Memory allocation failed for the buffer.\n");
        fclose(input);
        return false;
    }

    // Read each word from dictionary file
    while (fscanf(input, "%s", word) == 1)
    {
        // Allocate new node for this word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Memory allocation failed for a new node.\n");
            fclose(input);
            free(word);
            unload();
            return false;
        }
        hash_size++; // Increment loaded word count

        // Hash word using its length - 1 as index
        unsigned int word_len_minus1 = hash(word);

        // Copy word into node
        strcpy(n->word, word);

        // Insert node at beginning of linked list for this bucket
        n->next = table[word_len_minus1];
        table[word_len_minus1] = n;
    }

    fclose(input);
    free(word);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return hash_size;
}

// Unloads dictionary from memory, returns true if successful
bool unload(void)
{
    // Iterate over all buckets
    for (unsigned int i = 0; i < LENGTH; i++)
    {
        node *ptr = table[i];

        // Free all nodes in linked list at this bucket
        while (ptr != NULL)
        {
            node *index = ptr->next; // Save pointer to next node
            free(ptr);               // Free current node
            ptr = index;             // Advance pointer
        }
    }
    return true;
}
