#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // values for each coin (quarter, dime, nickle, penny)
    int q, d, n, p; 
    q = 25, d = 10, n = 5, p = 1;
    
    float change;
    do
    {
        
        // prompt user for change 
        change = get_float("Change:");
    
    }
    // if change is less than or equal to zero prompt the user again
    while (change <= 0); 

    // convert input to a whole number
    int dollars = round(change * 100);

    int coins_used = 0;
   
    // subtract the minimuim amount of coins until 0 
    while (dollars > 0)
    {
        
        dollars -= q;
        coins_used++;

        if (dollars < 0)
        {
            dollars += q;
            dollars -= d;
        }

        if (dollars < 0)
        {
            dollars += d;
            dollars -= n;
        }

        if (dollars < 5 && dollars > 0)
        {
            dollars -= p;
            coins_used++;
        }

    }
    // display coins_used
    printf("%i\n", coins_used);
}

