#include <stdio.h>
#include <iostream>

int nextYear, nextMonth;

void get_next(int year, int month) {
    if ((month + 1) == 13) {
        nextYear = year + 1;
        nextMonth = 1;
    }
    else {
        nextYear = year;
        nextMonth = month + 1;
    }
}

int main() {
    int year, month;
	scanf("%d %d", &year, &month);
	get_next(year, month);
	printf("%d-%d\n", nextYear, nextMonth);
    system("pause");
	return 0;
}