//given a date print the date as text, example: 10/1/1992 shoudl be printed as tenth january of nineteen ninety two.
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
bool validation(int, int, int);
void dateEnglish(char*);
bool isLeapYear(int);
void days(int, char*[], char*[]);
void months(int);
void years(int, char*[], char*[]);
void main() {
	char* date;
	printf("Enter the date in dd/mm/yyyy format :\n");
	date = (char*)malloc(sizeof(char)*10);
	scanf("%s", date);
	dateEnglish(date);
	_getch();
}

// date in english function
void dateEnglish(char* date) {
	// for numbers from 1 to 19
	char *digit[] = { "", "one", "two", "three", "four", "five", "six",
		"seven", "eight", "nine", "ten", "eleven", "twelve",
		"thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
		"eighteen", "nineteen" };
	// all tens
	char *tens[] = { "", "", "twenty", "thirty", "forty", "fifty",
		"sixty", "seventy", "eighty", "ninety" };
	int day = (date[0] - '0') * 10 + (date[1] - '0');
	int month = (date[3] - '0') * 10 + (date[4] - '0');
	int year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + ((date[8] - '0') * 10 + date[9] - '0');
	if (validation(day,month,year)) {
		days(day, digit, tens);
		months(month);
		printf(" of ");
		years(year, digit, tens);
	}
	else
		printf("Its not a valid date");
}
void days(int day, char* digit[], char* tens[]) {
	// for the numbers from 11 to 19
	if (day / 10 == 1)
		printf("%sth ", digit[day]);
	// for remaining numbers upto 31
	else {
		printf(" %s", tens[day / 10]);
		if (day % 10 == 1 )
			printf(" first ");
		else if (day  % 10 == 2)
			printf(" second ");
		else if (day % 10 == 3)
			printf(" third ");
		else if (day == 20)
			printf(" twentieth ");
		else if (day == 30)
		    printf(" thirtieth ");
		else {
			printf(" %sth ", digit[day % 10]);
		}
			
	}

}


//function to print month
void months(int months) {
	switch (months) {
	case 1: printf(" January ");
		break;
	case 2:printf(" Febrauary ");
		break;
	case 3:printf(" March ");
		break;
	case 4:printf(" April ");
		break;
	case 5:printf(" May ");
		break;
	case 6:printf(" June ");
		break;
	case 7:printf(" July ");
		break;
	case 8:printf(" August ");
		break;
	case 9:printf(" September ");
		break;
	case 10:printf(" October ");
		break;
	case 11:printf(" November ");
		break;
	case 12:printf(" December ");
		break;
	}
}

void years(int year, char* digit[], char* tens[]) {
	// example 2005 = two thousand five
	if ((year / 100) % 10 == 0) {
		printf("%s thousand ", digit[year / 1000]);
		if ((year % 100) >= 0 && (year % 100) <= 19)
			printf("%s ", digit[year % 100]);
		else
			printf("%s %s ", tens[(year / 10) % 10], digit[year % 10]);
	}
	// for 1998 = nineteen ninty eight and 1905 nighteen hundred five
	else {
		// for the first 1wo digits of the number
		if ((year / 100) >= 0 && (year / 100) <= 19)
			printf("%s ", digit[year / 100]);
		else
			printf("%s %s ", tens[year / 1000], digit[(year / 100) % 10]);
		// if third digit is '0'
		if ((year / 10) % 10 == 0) {
			printf("hundred %s ", digit[year % 10]);
		}
		//otherwise 
		else {
			if ((year % 100) >= 0 && (year % 100) <= 19)
				printf("%s ", digit[year % 100]);
			else
				printf("%s %s ", tens[(year / 10) % 10], digit[year % 10]);
		}
	}
}
	bool validation(int day, int month, int year){
		bool valid = false;
		// check if date month or year is valid (above zero)
		if (day <= 0 || month <= 0 || year <= 0)
			valid = false;
		else {
			// if given year is a leap year
			if (month == 2) {
				bool leap = isLeapYear(year);
				if (leap == true) {
					if (day <= 29)
						valid = true;
				}

				else if (leap == false) {
					if (day <= 28)
						valid = true;
				}
			}
			// months with 30 days
			else if (month == 4 || month == 6 || month == 9 || month == 11) {
				if (day <= 30)
					valid = true;
			}
			// month with 31 days
			else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
				if (day <= 31)
					valid = true;
			}
		}
		return valid;
	}

// function for leap year 
bool isLeapYear(int year) {
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		return true;
	return false;
}
