#include <stdio.h>
#include <cs50.h>
// this code will not work without the CS50 library
//I may come back and define get_int so that it works with cs50.h once I learn how to do that

int main(void)
{
    int height = get_int("Height: ");

    while (height < 0 || height > 23) //rejecting out of bounds height
    {
        height = get_int("Height: ");
    }

    for (int i = 0; i < height; i++) //rows
    {
        for (int j = 0; j < height - i - 1; j++) //spaces
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++) //left side of pyramid
        {
            printf("#");
        }

        printf("  "); //space between two sides of the pyramid

        for (int k = 0; k < i + 1; k++) //right side of pyramid
        {
            printf("#");
        }
        printf("\n");
    }
}
