// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// my own functions
unsigned int n_hash;
unsigned int n_word;

// verify if word exists
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // declare a hash value
    n_hash = hash(word);
    node *cursor = table[n_hash];

    // go through list
    while(cursor != 0)
    {
        if(strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long total = 0;
    for(int i = 0; i < strlen(word); i++)
    {
        total += tolower(word[i]);
    }
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //open dictionary file and returen null
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, word);
        n_hash = hash(word);
        n->next = table[n_hash];
        table[n_hash] = n;
        n_word ++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // return how many words there are
    if (n_word > 0)
    {
        return n_word;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // temporary variable pointing to node
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while(cursor)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }

    }
    return true;
}
