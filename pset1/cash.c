#include <stdio.h>
#include <cs50.h>
#include <math.h>
//may come back and define get_float so that cs50.h is not needed

int main(void)
{
    float change = get_float("Change owed: ");

    while (change < 0) //check for negative numbers
    {
        change = get_float("Change owed: ");
    }
    // could also write using do { } while
    
    int changeInCents = round(change * 100);

    int numCoins = 0;
    while (changeInCents >= 25) //number of quarters
    {
        changeInCents = changeInCents - 25;
        numCoins = numCoins + 1;
    }

    while (changeInCents >= 10) //number of dimes
    {
        changeInCents = changeInCents - 10;
        numCoins = numCoins + 1;
    }

    while (changeInCents >= 5) //number of nickels
    {
        changeInCents = changeInCents - 5;
        numCoins = numCoins + 1;
    }

    while (changeInCents > 0) //number of pennies
    {
        changeInCents = changeInCents - 1;
        numCoins = numCoins + 1;
    }

    printf("%i\n", numCoins);
}
