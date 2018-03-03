#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    //check that input is correct
    if (argc != 2)
    {
        printf("Error. Invalid key.\n");
        return 1;
    }

    //retrieve key
    int key = atoi(argv[1]);

    //check that key is positive
    if (key < 0)
    {
        printf("Error. Invalid key.\n");
        return 1;
    }

    //get plaintext
    string plainText = get_string("plaintext:  ");
    int n = strlen(plainText);

    //account for key values over 26
    while (key >= 26)
    {
        key = key - 26;
    }

    printf("ciphertext: ");

    for (int i = 0; i < n; i++)
    {
        //regular decryption
        if ((plainText[i] >= 'a' && plainText[i] <= 'z' - key) || (plainText[i] >= 'A' && plainText[i] <= 'Z' - key))
        {
            printf("%c", plainText[i] + key);
        }
        //wrapping around the alphabet
        else if ((plainText[i] >= 'z' - key && plainText[i] <= 'z') || (plainText[i] >= 'Z' - key && plainText[i] <= 'Z'))
        {
            printf("%c", plainText[i] + key - 26);
        }
        //non alphabetical input goes through
        else
        {
            printf("%c", plainText[i]);
        }
    }

    printf("\n");
}