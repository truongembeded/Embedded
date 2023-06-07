/*
* File: main.c
* Author: Nguyen Van Truong
* Date: 06/07/2023
* Description: This is a sample file for the days of the week
*/
#include <stdio.h>
#include<stdint.h>
#include"day.h"

/*
* Function: theDaysOfTheWeek
* Description: This function is print the days of the week
* Input:
*   iDay    - an interger value
*   iMonth  - an interger value
*   iYear   - an interger value
* Output:
*   returns to monday from sunday
*/
int theDaysOfTheWeek(int iDay, int iMonth, int iYear){

     if (iDay < 1 || iDay > 31 || iMonth < 1 || iMonth > 12 || iYear < 0) {

        perror("Error");

        return 0;
    }

    int days = 0;

    for (int m = BASE_MONTH; m < iMonth; m++) {
        if (m == 2) {
            if ((iYear % 4 == 0 && iYear % 100 != 0) || (iYear % 400 == 0)) {

                days += 29;
            } else {

                days += 28;
            }
        } else if (m == 4 || m == 6 || m == 9 || m == 11) {

            days += 30;

        } else {

            days += 31;
        }
    }

    days += iDay - BASE_DAY;

    int weekday = (BASE_WEEKDAY + days) % 7;

        switch (weekday) {

        case 0:
            printf("Sunday\n");
            break;
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
    }

    return weekday;
}

int main() {

    theDaysOfTheWeek(8, 6, 2023);

    return 0;
}