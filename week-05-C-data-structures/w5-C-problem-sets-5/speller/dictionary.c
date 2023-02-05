// Implements a dictionary's functionality

#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
int words = 0; // global word counter

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    bool found = false;
    int head = hash(word);
    node *cursor = table[head];

    while (cursor != NULL && found != true) // <= with while, time gets an average of 1.60... replacing while with if, average gets 0.2..significantly faster. but, fails test for most basic word
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            found = true;
        }
        cursor = cursor->next;
    }

    return found;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int val = 0;

    for (int i = 0, length = strlen(word); i < length; i++)
    {
        val += tolower(word[i]);
    }

    return val % N; // if the value > N then do val % N
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // check if open was successful returning true else false
    char word[LENGTH + 1];

    FILE *dictionaryFile = fopen(dictionary, "r");
    if (!dictionaryFile)
    {
        return false;
    }

    while (fscanf(dictionaryFile, "%s", word) != EOF)
    {
        node *newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            return 1;
        }
        strcpy(newNode->word, word);
        int dicIndex = hash(word);
        (table[dicIndex] != NULL) ? (newNode->next = table[dicIndex]) : (newNode->next = NULL);
        table[dicIndex] = newNode;
        words++; // update word global counter
    }

    fclose(dictionaryFile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO if load() == true then do... else return 0;
    if (&load)
    {
        return words;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    bool memoryFreed = false;

    for (int i = 0; i < N; i++) // i < buckets in hash table
    {
        node *cursor = table[i];
        node *tmp = cursor;
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
            memoryFreed = true;
        }
    }

    return memoryFreed;
}
