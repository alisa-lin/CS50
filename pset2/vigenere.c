#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    //check that input is correct
    if (argc != 2)
    {
        printf("Error. Invalid input.\n");
        return 1;
    }

    string alphakey = argv[1];
    int k = strlen(argv[1]);

    for (int i = 0; i < k; i++)
    {
        if (isalpha(alphakey[i]) == false)
        {
            printf("Error. Invalid input.\n");
            return 1;
        }
    }

    string plaintext = get_string("plaintext: ");
    int n = strlen(plaintext);

    //translate key into numbers
    int key[k];
    for (int i = 0; i < k; i++)
    {
        if (isupper(alphakey[i]))
        {
            key[i] = (int) alphakey[i] - 65;
            //printf("%i", key[i]);
        }
        else if (islower(alphakey[i]))
        {
            key[i] = (int) alphakey[i] - 97;
            //printf("%i", key[i]);
        }
        //printf("\n");
    }

    printf("ciphertext: ");

    int index = 0;
    //cipher if plaintext is alphabetical
    for (int i = 0; i < n; i++)
    {
        //regular encryption
        if (isalpha(plaintext[i]))
        {
            if ((isupper(plaintext[i]) && plaintext[i] <= 'Z' - key[index]) || (islower(plaintext[i]) && plaintext[i] <= 'z' - key[index]))
            {
                printf("%c", plaintext[i] + key[index]);
                if (index < k - 1)
                {
                    index++;
                }
                else
                {
                    index = 0;
                }
            }
            //wrapping around the alphabet
            else if ((isupper(plaintext[i]) && plaintext[i] >= 'Z' - key[index]) || (islower(plaintext[i]) && plaintext[i] >= 'z' - key[index]))
            {
                printf("%c", plaintext[i] + key[index] - 26);
                if (index < k - 1)
                {
                    index++;
                }
                else
                {
                    index = 0;
                }
            }
        }
        //non alphabetical
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
}