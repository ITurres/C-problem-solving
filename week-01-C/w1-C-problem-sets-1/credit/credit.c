#include <cs50.h>
#include <stdio.h>

int getCardLength(long);
int checkCardLength(int, long);
int checkCardName(int, int, long, int);
int sumDoubleCardNumber(int);
void checkAMEX(long);
void checkMC(long);

int main(void)
{
    long creditCardNum = get_long("Enter your credit card Number:\n");
    int cardLength = getCardLength(creditCardNum);
    checkCardLength(cardLength, creditCardNum);
}

int getCardLength(long cardNumber)
{
    int length = 0;
    long copyOfCard = cardNumber;
    do
    {
        copyOfCard /= 10;
        length++;
    } while (copyOfCard > 0);
    return length;
}

int checkCardLength(int cardLength, long creditCardNum)
{
    if (cardLength != 13 && cardLength != 15 && cardLength != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    long copyOfCard = creditCardNum;
    int addResults = 0;
    int last;
    long last2;
    int x = 0;
    int sum1;
    int secondToLast;
    int notDoubledSum = 0;
    int doubledSum = 0;

    do
    {
        last = copyOfCard % 10;
        copyOfCard /= 10;
        notDoubledSum += last;

        secondToLast = copyOfCard % 10;
        copyOfCard /= 10;
        x = sumDoubleCardNumber(secondToLast);
        doubledSum += x;
    } while (copyOfCard > 0);

    addResults = doubledSum + notDoubledSum;

    checkCardName(addResults, cardLength, creditCardNum, secondToLast);

    return 0;
}

int checkCardName(int addResults, int length, long cardNumber, int secondToLast)
{
    if (addResults % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    if (length == 13 || (secondToLast == 4 && length == 16))
    {
        printf("VISA\n");
    }
    else if (length == 15)
    {
        checkAMEX(cardNumber);
    }
    else if (length == 16)
    {
        checkMC(cardNumber);
    }
    return 0;
}

int sumDoubleCardNumber(int digit)
{
    digit *= 2;

    if (digit >= 10)
    {
        digit = 1 + digit % 10;
        return digit;
    }

    return digit;
}

void checkAMEX(long card)
{
    do
    {
        card /= 10;
    } while (card > 38);

    if (card == 34 || card == 37)
    {
        printf("AMEX\n");
        return;
    }
    printf("INVALID\n");
}

void checkMC(long card)
{
    do
    {
        card /= 10;
    } while (card > 56);

    if (card == 51 || card == 55)
    {
        printf("MASTERCARD\n");
        return;
    }
    printf("INVALID\n");
}

//////////////////////////////////////////////////////////
//* In this we get introduced to the Luhn’s Algorithm, this algorithm allows us to determine
//* if a credit card number is syntactically valid, a database check will be also necessary for real-world problems,
//* but what the Luhn’s algorithm does is:

//* Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
//* Add the sum to the sum of the digits that weren’t multiplied by 2.
//* If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
//* The above algorithm is what we have to implement in our program. Looks simple right?

//* Let's look at the first part of the main. The first thing we need to do is get the card number from the user,
//* we use the function get_long we can’t use int because credit card numbers have too many characters, get_long
//* already handles inputs like letters or other characters that do not number, we need to get the length of the Credit Card,
//* we declare two variables length which is equal to 0, it is going to store the total card length and a which is going to store
//* the card number.

//* I decided to use a do while loop, dividing a number by 10 drops the last digit of it, so while a is bigger than 0 we drop the last digit
//* of a and we increment the length variable to get the length of the CC entered

//* In the second part of the main, we check if the card is valid. We need to print INVALID or if it is valid we need to print the
//* name of the company.

//* The card number can only have 13, 15 or 16 digits, so this is the first thing we check with an if statement.

//* After that, we initialize and declare some variables that we are going to use later, one of them is last which is to store the last
//* numbers after each do while the loop which we need to sum later after we store the current last number at last with last = x % 10;
//* we drop the current last number, and then we sum the last numbers in each loop, this will be the second part of Luhn’s algorithm
//* (Add the sum to the sum of the digits that weren’t multiplied by 2.0) and we store it at notDoubledSum .

//* Now we have to do the first part of Luhn’s algorithm, doing this second might be kind of confusing, but I found it easier to do it
//* this way, we need to Multiply “every other digit by 2, starting with the number’s second-to-last digit, and then add those
//* products’ digits together”. After the previous part, we dropped the last digit, so now we have the second to last digit that we store
//* in its variable, and then we drop it, we call the function sumDoubledNumber that is in charge of adding double-digit numbers that result
//* from the multiplication, and then we add the products together and the loop begins again until there are no card digits left and
//* doubledSum and notDoubledSum are added.

//* In the third part of the main, we check for the Brand name, the first check-in this part is “If the total’s last digit is 0
//* (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!”, If this is passed we check for the brands,
//* the first one we do is VISA, the only type of card that has 13 digits is VISA, so if the length is 13 we print VISA or if the card
//* number starts with 4 and has 16 digits as length it should also be a VISA, here secondToLast acts as the first digit of the card number.

//* If the number does meet the requirements to be a VISA, we check if it is an American Express card, which has to have 15 digits with
//* the checkAMEX function.

//* If the number has 16 digits, we check if it is a Master Card with the checkMC function, and that’s how we finish our main function.

//* Functions.
//* The first function is to deal with doubled digit numbers, if the multiplication by 2 returns a doubled digit number we need to
//* separate and sum them individually, to do this we use the modulo operator to drop the second digit, and we sum that with 1,
//* because the highest a digit multiply by 2 can be is 18, else we just return the sum. It takes the second to last digit as an argument in every loop.

//* The Second function will check if the card is American Express taking the card Number as an argument, in this situation all the
//* AMEX cards starts with 37, I decided to do a do while loop, while the last digits are more than 38, keep dropping numbers,
//* if the last two digits are equal to 34 or 37, the card is an AMEX else it is INVALID.

//* The third function will check if the card is a Master Card, with basically the same algorithm as the above, we just replace the
//* number with 56, 51 and 55.

//* Now our program is complete, and it should pass the test. Here are some numbers to check your program: 378282246310005 as AMEX,
//* 5105105105105100 as MASTERCARD, 4012888888881881 as VISA, 5673598276138003 as INVALID.