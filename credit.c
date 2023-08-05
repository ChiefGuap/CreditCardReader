#include <cs50.h>
#include <stdio.h>
#define MAX 100

long get_creditcard(void);
// void checksum(long cardnumber);

int main(void)
{
    //Asking the Credit Card Number from the User
    long cardnumber = get_creditcard();
    // checksum(cardnumber);
    // printf("%ld\n", cardnumber);

    int arr[MAX];
    int i = 0;
    int j, r, l;
    int sum = 0;
    long x = cardnumber;

    long y = cardnumber;

    //Starting from the second to last digit and going every other digit in reverse Luhn Algorithim pt. 1
    while (x != 0){
        //getting the specific digit from the credit card number
        r = ((x % 100) / 10) *2;
        // Making sure number 10+ are stripped into single digits such as 10 --> 1, 0
        r = (r % 100)/10 + (r % 10);
        //Adding the numbers into the array
        arr[i] = r;
        i++;

        x = x / 100;
    }

    //Starting from the last digit and goign every other digit in reverse Luhn Algorithim pt. 2
    while (y != 0){
        l = (y % 10);
        arr[i] = l;
        i++;

        y = y / 100;
    }

    // Adding all the elements from the araay and getting the sum Luhn Algorithim pt. 3
    for (j = i -1; j > -1; j--){
       sum = sum + arr[j];
    }

    if((sum % 10) != 0) {
        printf("%s\n", "INVALID");
        return 0;
    }


    //We have to differentiate between the three card types AMEX, VISA, or Master to see what card type your credit card number is
    int length = 0;
    long visa = cardnumber;
    long amex = cardnumber;
    long master = cardnumber;

    // finding out the length of the cardnumber given to us
    while (cardnumber > 0) {
        cardnumber = cardnumber /10;
        length++;
    }

    //Indentifiying if the card is a VISA card
    while (visa >= 10) {
        visa /= 10;
    }

    if((length == 16 || length == 13) && visa == 4) {
        printf("%s\n", "VISA");
        return 0;
    }

    //Identifying if the card is an Amex card
    while (amex >= 10000000000000){
        amex /= 10000000000000;
    }
    if(length == 15 && (amex == 34 || amex == 37)) {
        printf("%s\n", "AMEX");
        return 0;
    }

    //Identifying if the card is an Master card
    while(master >= 100000000000000) {
        master /= 100000000000000;
    }

    if(length == 16 && (master == 51 || master == 52 || master == 53 || master == 54 || master == 55)) {
        printf("%s\n", "MASTERCARD");
        return  0;
    }

    else
    printf("%s\n", "INVALID");
}






long get_creditcard()
{
    long cardnumber;
    do
    {
        cardnumber = get_long("Credit Card Number: ");
    }
    while(cardnumber < 0);
    return cardnumber;
}



