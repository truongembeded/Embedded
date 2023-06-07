/*
* File: main.c
* Author: Nguyen Van Truong
* Date: 05/07/2023
* Description: This is a sample file for calculate The taxi fare
*/
#include <stdio.h>
#include<stdint.h>
//#include"main.h"

/*
* Function: calculateTaxiFare
* Description: This function calculate The taxi fare
* Input:
*   fKilometers - a float value
* Output:
*   returns the amount to be paid for the taxi
*/
int calculateTaxiFare(float fKilometers) {

    uint32_t iTaxiFare = 0;

    if (fKilometers <= 1) {

        iTaxiFare = 14000;

    } else if (fKilometers <= 30) {

        iTaxiFare = 14000 + (fKilometers - 1) * 10000;

    } else {

        iTaxiFare = 14000 + 29 * 10000 + (fKilometers - 30) * 8000;

    }
        printf("%2.f km gia taxi la: %d\n", fKilometers, iTaxiFare);

    return iTaxiFare;
}

int main() {

    calculateTaxiFare(10);

    return 0;
}
