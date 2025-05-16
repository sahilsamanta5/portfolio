/*
    Author: Sahil Samanta
    Project: Astrology Sun Zodiac Sign Calculator
*/

#include <stdio.h>
#include <string.h>

typedef struct {
        int MONTH;
        char* MONTH_NAME;
        int MIN_DAY;
        int MAX_DAY;
        int FIRST_ZODIAC_START;
        int FIRST_ZODIAC_END;
        char* FIRST_ZODIAC_NAME;
        char* SECOND_ZODIAC_NAME;

} MONTH_STRUCT;

MONTH_STRUCT MONTH_ARRAY[] = {
    {1, "January", 1, 31, 1, 19, "Capricorn", "Aquarius"},
    {2, "February", 1, 29, 1, 18, "Aquarius", "Pisces"},
    {3, "March", 1, 31, 1, 20, "Pisces", "Aries"},
    {4, "April", 1, 30, 1, 19, "Aries", "Taurus"},
    {5, "May", 1, 31, 1, 20, "Taurus", "Gemini"},
    {6, "June", 1, 30, 1, 20, "Gemini", "Cancer"},
    {7, "July", 1, 31, 1, 22, "Cancer", "Leo"},
    {8, "August", 1, 31, 1, 22, "Leo", "Virgo"},
    {9, "September", 1, 30, 1, 22, "Virgo", "Libra"},
    {10, "October", 1, 31, 1, 22, "Libra", "Scorpio"},
    {11, "November", 1, 30, 1, 21, "Scorpio", "Sagittarius"},
    {12, "December", 1, 31, 1, 21, "Sagittarius", "Capricorn"}
};

char* outputStatement(char name[], int birthday, int birthmonth){
    static char output[256];
    char zodiac[15] = "Unknown";
    if (MONTH_ARRAY[birthmonth-1].FIRST_ZODIAC_END < birthday){
        strcpy(zodiac, MONTH_ARRAY[birthmonth-1].SECOND_ZODIAC_NAME);
    } else {
        strcpy(zodiac, MONTH_ARRAY[birthmonth-1].FIRST_ZODIAC_NAME);
    }
    sprintf(output, "Hello %s,\nAccording to our analysis, your zodiac sun sign is %s.", name, zodiac);
    return output;
}

char* getMonthString(int birthmonth){
    if (birthmonth < 1 || birthmonth > 12) return "Unknown";
    return MONTH_ARRAY[birthmonth-1].MONTH_NAME;
}

char* getAllMonthsStr(){
    static char output[512];
    strcpy(output, "");
    for (int i = 0; i < 12; i++) {
        char line[50];
        sprintf(line, "%d) %s\n", MONTH_ARRAY[i].MONTH, MONTH_ARRAY[i].MONTH_NAME);
        strcat(output, line);
    }

    return output;
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

    printf("Month of Birth:\n%s\nSelect your month between 1 and 12: ", getAllMonthsStr());
    

    scanf("%d", &month);

    if (month < 1 || month > 12) {
        printf("Month should be greater than 0 and less than 13\n");
        return 1;
    }

    MONTH_STR = getMonthString(month);

    if (day < MONTH_ARRAY[month-1].MIN_DAY || day > MONTH_ARRAY[month-1].MAX_DAY) {
        printf("Month of %s starts from %d and ends on %d", MONTH_ARRAY[month-1].MONTH_NAME, MONTH_ARRAY[month-1].MIN_DAY, MONTH_ARRAY[month-1].MAX_DAY);
        return 1;
    }

    char* result = outputStatement(name, day, month);
    printf("%s\n", result);
    return 0;
}