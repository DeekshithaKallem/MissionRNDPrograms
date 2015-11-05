#define _CRT_SECURE_NO_DEPRECATE

#define _CRT_SECURE_NO_WARNING

#include <stdio.h>

int validation(int day, int month, int year);

int isLeapYear(int year);

void dateInEng(char * date, char * ones[], char * tens[]);

void monthInEng(int month);

void dayInEng(int day, char * ones[], char * tens[]);

void yearInEng(int year, char * ones[], char * tens[]);

int main() {

	char * date = (char*)malloc(sizeof(char) * 10);

	char * ones[] = { "", "one", "two", "three", "four", "five", "six",

		"seven", "eight", "nine", "ten", "eleven", "twelve",

		"thirteen", "fourteen", "fifteen", "sixteen", "seventeen",

		"eighteen", "nineteen" };

	char * tens[] = { "", "", "twenty", "thirty", "forty", "fifty",

		"sixty", "seventy", "eighty", "ninety" };

	printf("Enter the date in dd/mm/yyyy : ");

	scanf("%s", date);

	dateInEng(date, ones, tens);

	getchar();

	getchar();

	return 0;

}



void dateInEng(char * date, char * ones[], char * tens[]) {

	int day = ((date[0]) - 48) * 10 + (date[1]) - 48;

	int month = ((date[3]) - 48) * 10 + (date[4]) - 48;

	int year = (((date[6]) - 48) * 1000) + (((date[7]) - 48) * 100) + (((date[8]) - 48) * 10) + ((date[9]) - 48);

	if (validation(day, month, year)) {

		dayInEng(day, ones, tens);

		monthInEng(month);

		yearInEng(year, ones, tens);

	}

}



int validation(int date, int month, int year) {

	int valid = 0;

	if (date <= 0 || month <= 0 || year <= 0)

		valid = 0;

	else {

		int leap = 0;

		if (month == 2) {

			leap = isLeapYear(year);

			if (leap == 1) {

				if (date <= 29)

					valid = 1;

			}

			else if (leap == 0) {

				if (date <= 28)

					valid = 1;

			}

		}

		else if (month == 4 || 6 || 9 || 11) {

			if (date <= 30)

				valid = 1;

		}

		else if (month == 1 || 3 || 5 || 7 || 8 || 10 || 12) {

			if (date <= 31)

				valid = 1;

		}

	}

	return valid;

}



int isLeapYear(int year) {

	int leap = 0;

	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))

		leap = 1;

	return leap;

}



void dayInEng(int day, char * ones[], char * tens[]) {

	if (day / 10 == 1)

		printf("%sth ", ones[day]);

	else {

		printf("%s ", tens[day / 10]);

		if (day % 10 == 1)

			printf("first ");

		else if (day % 10 == 2)

			printf("second ");

		else if (day % 10 == 3)

			printf("third ");

		else if (day == 20)

			printf("twentieth ");

		else if (day == 30)

			printf("thirtieth ");

		else {

			printf(" %sth ", ones[day % 10]);

		}

	}

}



void monthInEng(int month) {

	switch (month) {

	case	1: printf("January");

		break;

	case 2:printf("Febrauary ");

		break;

	case 3:printf("March ");

		break;

	case 4:printf("April ");

		break;

	case 5:printf("May ");

		break;

	case 6:printf("June ");

		break;

	case 7:printf("July ");

		break;

	case 8:printf("August ");

		break;

	case 9:printf("September ");

		break;

	case 10:printf("October ");

		break;

	case 11:printf("November ");

		break;

	case 12:printf("December ");

		break;

	}

	printf(" of ");

}



void yearInEng(int year, char * ones[], char * tens[]) {

	if ((year / 100) % 10 == 0) {

		printf("%s thousand ", ones[year / 1000]);

		if ((year % 100) >= 0 && (year % 100) <= 19)

			printf("%s ", ones[year % 100]);

		else

			printf("%s %s ", tens[(year / 10) % 10], ones[year % 10]);

	}

	else {

		if ((year / 100) >= 0 && (year / 100) <= 19)

			printf("%s ", ones[year / 100]);

		else

			printf("%s %s ", tens[year / 1000], ones[(year / 100) % 10]);

		if ((year / 10) % 10 == 0)

			printf("hundred %s ", ones[year % 10]);

		else {

			if ((year % 100) >= 0 && (year % 100) <= 19)

				printf("%s ", ones[year % 100]);

			else

				printf("%s %s ", tens[(year / 10) % 10], ones[year % 10]);

		}

	}

}