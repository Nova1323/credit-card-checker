#include <cs50.h>
#include <stdio.h>

int luhn(long);
void card_check(long);

int main(void)
{
    long credit_card_number = get_long("Number: ");

    // Calculate Luhn's Method
    int valid = luhn(credit_card_number);

    if (valid % 10 == 0)
    {
        // Check the type of credit card
        card_check(credit_card_number);
    }

    else
    {
        printf("INVALID\n");
    }
}


int luhn(long credit_card_number)
{
    int sum1 = 0, sum2 = 0, counter = 0;
    do
    {
        // Find odd digits
        int mod1 = credit_card_number % 10;

        // Add odd digits
        sum1 = sum1 + mod1;

        credit_card_number = credit_card_number / 10;

        // Find even digits
        int mod2 = credit_card_number % 10;

        // Double even digits
        int mod2_double = mod2 * 2;

        // Seperate digits after doubling
        int x = mod2_double % 10; //4
        int y = mod2_double / 10; //0

        // Add the digits
        sum2 = sum2 + x + y; // 0=0+4+0=4

        credit_card_number = credit_card_number / 10;
        counter = counter + 2;
    }
    while (credit_card_number > 0);

    // Sum of odd digits and double of even digits
    int total = sum1 + sum2;

    if (counter > 10)
    {
        return total;
    }
    else
    {
        return 11;
    }
}


void card_check(long credit_card_number)
{
    // Get starting digits
    do
    {
        credit_card_number = credit_card_number / 10;
    }
    while (credit_card_number > 100);

    // Check for MASTERCARD
    if ((credit_card_number / 10 == 5) && (0 < credit_card_number % 10 && credit_card_number % 10 < 6))
    {
        printf("MASTERCARD\n");
    }

    // Check for AMERICAN EXPRESS
    else if ((credit_card_number / 10 == 3) && (credit_card_number % 10 == 4 || credit_card_number % 10 == 7))
    {
        printf("AMEX\n");
    }

    // Check for VISA
    else if (credit_card_number / 10 == 4)
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }
}
