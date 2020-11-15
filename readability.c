#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// functions for counting letters, words, and sentences in given a string (a)
float letters(string a); 
float words(string a);
float sentences(string a);

int main(void)
{
    // get text from user
    string text = get_string("Text: ");
    
    // use functions to assign approriate value (eg. no. of letters)
    float num_letters = letters(text);
    float num_words = words(text);
    float num_sentences = sentences(text);
    
    // calculate average letters and sentences per 100 words
    float letters_100 = (num_letters * 100) / num_words;
    float sentences_100 = (num_sentences * 100) / num_words;
    
    // calculate the Coleman-Liau index to nearest whole number
    int index = round((0.0588 * letters_100) - (0.296 * sentences_100) - 15.8);
    
    
    // if the C.L index is less than 1 print "Before Grade 1 and return 0"
    if (index < 1)
    {
        printf("Before Grade 1\n");
        return (0);
    }
    
    // if the C.L index is greater than 16 print "Grade 16+" and return 0
    if (index > 16)
    {
        printf("Grade 16+\n");
        return (0);
    }
    
   
    printf("Grade %i\n", index);
    return (0);

    
}


float letters(string a)
{   
    float n = 0;
    // loop through every element in a 
    for (int i = 0; i != strlen(a); i++)
    {
        // if a is in an alphabetic letter increment n by 1
        if isalpha(a[i])
        {
            n++;
        }
    }

    return (n);
}

float words(string a) 
{
    float n = 0;
    // loop through each element of a
    for (int i = 0; i != strlen(a); i++)
    {
        // if there's a space char (i.e word end) increment n by 1
        if (a[i] == ' ')
        {
            n++;
        }
    }
    
    // increment n by 1 ... last word
    n++;
    return (n);
}
 
 
float sentences(string a)
{
    float n = 0;
    
    // loop through each element of a
    for (int i = 0; i != strlen(a); i++)
    {
        // if char is a end char (e.g ., ?) increment n by 1
        if (a[i] == '.' || a[i] ==  '!' || a[i] == '?')
        {
            n++;
        }
    }
    return (n);
}
  