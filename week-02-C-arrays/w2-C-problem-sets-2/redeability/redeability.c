#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

int count_letters(int, string);
int count_words(int, string);
int count_sentences(int, string);
int formula(int, int, int);

int main(void)
{
    string userText = get_string("Text: ");
    const int textLength = strlen(userText);
    const int letters = count_letters(textLength, userText);
    const int words = count_words(textLength, userText);
    const int sentences = count_sentences(textLength, userText);
    const int grade = formula(letters, words, sentences);

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(int textLength, string text)
{
    int nLetters = 0;
    for (int i = 0; i < textLength; i++)
    {
        if (!isspace(text[i]) &&
            isalpha(text[i]))
        {
            // printf("%c\n", text[i]);
            nLetters++;
        }
    }
    // printf("%i nLetters\n", nLetters);
    return nLetters;
}

int count_words(int textLength, string text)
{
    int nWords = 1;
    for (int i = 0; i < textLength; i++)
    {
        if (isspace(text[i]))
        {
            nWords++;
        }
    }
    // printf("%i nWords\n", nWords);
    return nWords;
}

int count_sentences(int textLength, string text)
{
    int nSentences = 0;
    for (int i = 0; i < textLength; i++)
    {
        if (text[i] == '.' ||
            text[i] == '!' ||
            text[i] == '?')
        {
            nSentences++;
        }
    }
    // printf("%i nSentences\n", nSentences);
    return nSentences;
}

int formula(int letters, int words, int sentences)
{
    // printf("letters: %i, words: %i, sentences: %i \n", letters, words, sentences);
    const int L = ((float)letters / (float)words) * 100;
    const int S = ((float)sentences / (float)words) * 100;
    // printf("L = %d\n", L);
    // printf("S = %d\n", S);
    return round(0.0588 * L - 0.296 * S - 15.8);
}