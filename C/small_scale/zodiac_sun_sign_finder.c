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

int main() {
    char name[100];
    int day;
    int month;

    printf("Hello User, Please enter your name: ");
    scanf("%[^\n]%*c", name);

    printf("Day of Birth (example: 11, 20, 31, etc): ");
    scanf("%d", &day);

    printf("Month of Birth (example: 1, 7, 9, 12): ");
    scanf("%d", &month);

    printf(outputStatement(name, day, month));
    return 0;
}