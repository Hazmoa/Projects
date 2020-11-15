#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    
    string key = argv[argc - 1];
    
    // checks to see if encryption key length is 26 
    if (strlen(key) > 26 || strlen(key) < 26)
    {
        return 1;
    }
    // checks if every element is alphabetic
    for (int i = 0; i < strlen(key); i++)
    {
        if (!(isalpha(key[i])))
        {
            return 1;
        }
    }
    // converts all letters in key to lowercase
    for (int i = 0; i < strlen(key); i++)
    {
        // adds 32 to uppercase element to convert to lowercase ascii equivalent
        if (isupper(key[i]))
        {
            key[i] += 32; 
        }
    }
    char chr;
    int counter;
    // checks for duplicating chars in key 
    for (int i = 0; i < 26; i++)
    {
        chr = key[i];
        counter = 0;
        
        for (int j = 0; j < 26; j++)
        {
            if (chr == key[j])
            {
                counter++;
            }
            if (counter >= 2)
            {
                return 1;
            }
                
        }
    }
    
    string plain_txt = get_string("Plain Text: ");
    printf("ciphertext: ");  
    // loops through plain_txt and prints cipher text equivalent
    for (int i = 0; i < strlen(plain_txt); i++)
    { 
        if (islower(plain_txt[i]))
        {   
            // subtracts 97(ascii) from plain_txt lower case to find corrosponding letter in key 
            printf("%c", key[plain_txt[i] - 97]);
            continue;
        }
        if (isupper(plain_txt[i]))
        {
            // subtracts 32(ascii) from plain_txt upper case to find corrosponding letter in key 
            printf("%c", key[plain_txt[i] - 65] - 32);
            continue;
        }
        // if plain_txt isn't alphabetic print it as it is
        if (!(isalpha(plain_txt[i])))
        {
            printf("%c", plain_txt[i]);
        }
    }
    
    printf("\n");
    return 0; 
}