/*
    Author: Sahil Samanta
    Project: Astrology Sun Zodiac Sign Calculator
*/

#include <stdio.h>
#include <string.h>

char* outputStatement(char name[15], int birthday, int birthmonth){
    static char output[100];
    char zodiac[15] = "Unknown";
    switch(birthmonth){
        case 1:
            if (birthday >= 1 && birthday <= 19) {
                strcpy(zodiac, "Capricorn");
            } else {
                strcpy(zodiac, "Aquarius");
            }
            break;
        case 2:
            if (birthday >=1 && birthday <= 18) {
                strcpy(zodiac, "Aquarius");
            } else {
                strcpy(zodiac, "Pisces");
            }
            break;
        case 3:
            if (birthday>=1 && birthday <= 20) {
                strcpy(zodiac, "Pisces");
            } else {
                strcpy(zodiac, "Aries");
            }
            break;
        case 4:
            if (birthday >= 1 && birthday <= 19) {
                strcpy(zodiac, "Aries");
            } else {
                strcpy(zodiac, "Taurus");
            }
            break;
        case 5:
            if (birthday >= 1 && birthday <= 20) {
                strcpy(zodiac, "Taurus");
            } else {
                strcpy(zodiac, "Gemini");
            }
            break;
        case 6:
            if (birthday >= 1 && birthday <= 20) {
                strcpy(zodiac, "Gemini");
            } else {
                strcpy(zodiac, "Cancer");
            }
            break;
        case 7:
            if (birthday >= 1 && birthday <= 22) {
                strcpy(zodiac, "Cancer");
            } else {
                strcpy(zodiac, "Leo");
            }
            break;
        case 8:
            if (birthday >= 1 && birthday <= 22) {
                strcpy(zodiac, "Leo");
            } else {
                strcpy(zodiac, "Virgo");
            }
            break;
        case 9:
            if (birthday >= 1 && birthday <= 22) {
                strcpy(zodiac, "Virgo");
            } else {
                strcpy(zodiac, "Libra");
            }
            break;
        case 10:
            if (birthday >= 1 && birthday <= 22) {
                strcpy(zodiac, "Libra");
            } else {
                strcpy(zodiac, "Scorpio");
            }
            break;
        case 11:
            if (birthday >= 1 && birthday <= 21) {
                strcpy(zodiac, "Scorpio");
            } else {
                strcpy(zodiac, "Sagittarius");
            }
            break;
        case 12:
            if (birthday >= 1 && birthday <= 21) {
                strcpy(zodiac, "Sagittarius");
            } else {
                strcpy(zodiac, "Capricorn");
            }
            break;
    }

    sprintf(output, "Hello %s,\nAccording to our analysis, your zodiac sun sign is %s.", name, zodiac);
    return output;
}

char* monthString(int birthmonth){
    char* MONTH_STR;
    switch(birthmonth){
        case 1: MONTH_STR = "January"; break;
        case 2: MONTH_STR = "February"; break;
        case 3: MONTH_STR = "March"; break;
        case 4: MONTH_STR = "April"; break;
        case 5: MONTH_STR = "May"; break;
        case 6: MONTH_STR = "June"; break;
        case 7: MONTH_STR = "July"; break;
        case 8: MONTH_STR = "August"; break;
        case 9: MONTH_STR = "September"; break;
        case 10: MONTH_STR = "October"; break;
        case 11: MONTH_STR = "November"; break;
        case 12: MONTH_STR = "December"; break;
        default: MONTH_STR = "Unknown"; break;
    }

    return MONTH_STR;
}

int main() {
    char name[100];
    int day;
    int month;
    char* MONTH_STR;

    printf("Hello User, Please enter your name: ");
    scanf("%[^\n]%*c", name);

    printf("Day of Birth (example: 11, 20, 31, etc): ");
    scanf("%d", &day);

    printf("Month of Birth:\n1. January\n2. February\n3. March\n4. April\n5. May\n6. June\n7. July\n8. August\n9. September\n10. October\n11. November\n12. December\n\nSelect your month between 1 and 12: ");
    

    scanf("%d", &month);

    if (month < 1 || month > 12) {
        printf("Month should be greater than 0 and less than 13");
        return 1;
    }

    MONTH_STR = monthString(month);

    if (day > 31 || day < 1) {
        printf("Month of %s cannot have %d in date", MONTH_STR, day);
        return 1;
    }
    if (month == 2){
        if (day > 29) {
            printf("Month of february cannot have more than 29 in date");
            return 1;
        }
    } else if(month < 8) {
        if (day > 30 && month % 2 == 0) {
            printf("Month of %s cannot have more than 30 in date", MONTH_STR);
            return 1;
        }
    } else if(month >= 8) {
        if (day > 30 && month % 2 != 0) {
            printf("Month of %s cannot have more than 30 in date", MONTH_STR);
            return 1;
        }
    }

    printf(outputStatement(name, day, month));
    return 0;
}