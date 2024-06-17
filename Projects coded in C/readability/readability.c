#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string paragraph);
int count_words(string paragraph);
int count_sentences(string paragraph);

int main(void)
{
    // get the text input from user
    string text = get_string("Text:");

    int lettersc = count_letters(text);

    //printf("letter(s) %i\n", lettersc);

    int wordsc = count_words(text);

    // printf("word(s) %i\n", wordsc);

    int sentencesc = count_sentences(text);

    //printf("sentence(s) %i\n", sentencesc);

    float L = (((float)lettersc) / (wordsc)) * 100;
    float S = (((float)sentencesc) / (wordsc)) * 100;

    //printf("%f\n", L);
    //printf("%f\n", S);

    float floatindex = 0.0588 * L - 0.296 * S - 15.8;

    int index = round(floatindex);

    if (1 <= index && index < 16)
    {
        printf("Grade %i\n", index);
    }
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
}

// function to count how many letters there are
int count_letters(string paragraph)
{
    int letters_count = 0;
    for (int i = 0, n = strlen(paragraph); i < n; i++)
    {
        if (isalpha(paragraph[i]))
        {
            letters_count += 1;
        }
    }
    return letters_count;
}

//function to count how many words there are

int count_words(string paragraph)
{
    int word_count = 1;
    for (int i = 0, n = strlen(paragraph); i < n; i++)
    {
        if ((paragraph[i]) == ' ')
        {
            word_count += 1;
        }
    }
    return word_count;

}

int count_sentences(string paragraph)
{
    int sentence_count = 0;
    for (int i = 0, n = strlen(paragraph); i < n; i++)
    {
        if ((paragraph[i]) == '.' || (paragraph[i]) == '?' || (paragraph[i]) == '!')
        {
            sentence_count += 1;
        }
    }
    return sentence_count;
}