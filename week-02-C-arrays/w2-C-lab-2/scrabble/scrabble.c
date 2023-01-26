#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}

int compute_score(string word)
{
    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    const int alphabetSize = 26;
    int finalPoints = 0;

    for (int i = 0, length = strlen(word); i < length; i++)
    {
        for (int j = 0; j < alphabetSize; j++)
        {
            if (tolower(word[i]) == alphabet[j])
            {
                // printf("%i %c\n", POINTS[j], alphabet[j]);
                finalPoints += POINTS[j];
            }
        }
    }

    return finalPoints;
}
