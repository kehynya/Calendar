#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

const int ENTER = 13;
const int UP = 72;
const int DOWN = 80;
const int BS = 8;
const int DOT = 46;
const int COLON = 58;

void menu(int k, int hour1, int min1, int sec1, int day1, int month1, int year1, int hour2, int min2, int sec2, int day2, int month2, int year2, int days) {
	if (k == 1) { printf("1.Введите первое время %02d:%02d:%02d <--\n2.Введите первую дату %02d.%02d.%02d \n3.Введите второе время %02d:%02d:%02d \n4.Введите вторую дату %02d.%02d.%02d\n5.Результат 1\n6.Количество дней %d\n7.Результат 2\n",hour1, min1, sec1, day1, month1, year1, hour2, min2, sec2, day2, month2, year2, days); }
	if (k == 2) { printf("1.Введите первое время %02d:%02d:%02d\n2.Введите первую дату %02d.%02d.%02d <--\n3.Введите второе время %02d:%02d:%02d \n4.Введите вторую дату %02d.%02d.%02d\n5.Результат 1\n6.Количество дней %d\n7.Результат 2\n", hour1, min1, sec1, day1, month1, year1, hour2, min2, sec2, day2, month2, year2, days); }
	if (k == 3) { printf("1.Введите первое время %02d:%02d:%02d\n2.Введите первую дату %02d.%02d.%02d \n3.Введите второе время %02d:%02d:%02d <--\n4.Введите вторую дату %02d.%02d.%02d\n5.Результат 1\n6.Количество дней %d\n7.Результат 2\n", hour1, min1, sec1, day1, month1, year1, hour2, min2, sec2, day2, month2, year2, days); }
	if (k == 4) { printf("1.Введите первое время %02d:%02d:%02d\n2.Введите первую дату %02d.%02d.%02d \n3.Введите второе время %02d:%02d:%02d \n4.Введите вторую дату %02d.%02d.%02d <--\n5.Результат 1\n6.Количество дней %d\n7.Результат 2\n", hour1, min1, sec1, day1, month1, year1, hour2, min2, sec2, day2, month2, year2, days); }
	if (k == 5) { printf("1.Введите первое время %02d:%02d:%02d\n2.Введите первую дату %02d.%02d.%02d \n3.Введите второе время %02d:%02d:%02d \n4.Введите вторую дату %02d.%02d.%02d\n5.Результат 1 <--\n6.Количество дней %d\n7.Результат 2\n", hour1, min1, sec1, day1, month1, year1, hour2, min2, sec2, day2, month2, year2, days); }
	if (k == 6) { printf("1.Введите первое время %02d:%02d:%02d\n2.Введите первую дату %02d.%02d.%02d \n3.Введите второе время %02d:%02d:%02d \n4.Введите вторую дату %02d.%02d.%02d\n5.Результат 1\n6.Количество дней %d <--\n7.Результат 2\n", hour1, min1, sec1, day1, month1, year1, hour2, min2, sec2, day2, month2, year2, days); }
	if (k == 7) { printf("1.Введите первое время %02d:%02d:%02d\n2.Введите первую дату %02d.%02d.%02d \n3.Введите второе время %02d:%02d:%02d \n4.Введите вторую дату %02d.%02d.%02d\n5.Результат 1\n6.Количество дней %d\n7.Результат 2 <--\n", hour1, min1, sec1, day1, month1, year1, hour2, min2, sec2, day2, month2, year2, days); }
	if (k >= 8 || k <= 0) { printf("ОШИБКА"); }
}

int d[8];

void data(int w[]) {
	int symb, k = 0;
	//int d[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };

	for (int i = 0; i < 8; ++i) d[i] = -1;

	printf("Введите дату формата 00.00.0000: ");
	while (d[7] == -1) {
		symb = _getch();
		if (isdigit(symb)) {
			sscanf_s(&symb, "%d", &d[k]);
			k++;
			system("cls");
			printf("DATA: ");
			for (int i = 0; i < 8; i++) {
				if (d[i] != -1) {
					printf("%d", d[i]);
					if (i == 1 || i == 3) {
						printf(".");
					}
				}
				else break;
			}

		}
		else if (symb == DOT || symb == 47) {
			if (k == 1 || k == 3) {
				d[k] = d[k - 1];
				d[k - 1] = 0;
				k++;
				system("cls");
			}
			printf("DATA: ");
			for (int i = 0; i < 8; i++) {
				if (d[i] != -1) {
					printf("%d", d[i]);
					if (i == 1 || i == 3) {
						printf(".");
					}
				}
				else break;
			}
		}
		else if (symb == BS) {
			d[k] = -1;
			if (k > 0) k--;
			system("cls");
			printf("DATA: ");
			//printf("%d\n", k);
			for (int i = 0; i < k; i++) {
				if (d[i] != -1) {
					printf("%d", d[i]);
					if (i == 1 || i == 3) {
						printf(".");
					}
				}
				else break;
			}
		}
	}
	return;
}
int t[6];
void time() {
	int symb, k = 0;
	//int d[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };

	for (int i = 0; i < 6; ++i) t[i] = -1;

	printf("Введите время формата 00:00:00: ");
	while (t[5] == -1) {
		symb = _getch();
		if (isdigit(symb)) {
			sscanf_s(&symb, "%d", &t[k]);
			k++;
			system("cls");
			printf("TIME: ");
			for (int i = 0; i < 6; i++) {
				if (t[i] != -1) {
					printf("%d", t[i]);
					if (i == 1 || i == 3) {
						printf(":");
					}
				}
				else break;
			}

		}
		else if (symb == COLON || symb == 59) {
			if (k == 1 || k == 3) {
				t[k] = t[k - 1];
				t[k - 1] = 0;
				k++;
				system("cls");
			}
			printf("TIME: ");
			for (int i = 0; i < 6; i++) {
				if (t[i] != -1) {
					printf("%d", t[i]);
					if (i == 1 || i == 3) {
						printf(":");
					}
				}
				else break;
			}
		}
		else if (symb == BS) {
			t[k] = -1;
			if (k > 0) k--;
			system("cls");
			printf("TIME: ");
			//printf("%d\n", k);
			for (int i = 0; i < k; i++) {
				if (t[i] != -1) {
					printf("%d", t[i]);
					if (i == 1 || i == 3) {
						printf(":");
					}
				}
				else break;
			}
		}
		else if (symb == ENTER && k == 5) {
			t[5] = t[4];
			t[4] = 0;
		}
	}
	return;
}
bool leap_year(int year) {
	bool flag = false;
	if (year % 100 == 0) {
		if (year % 400 == 0) {
			flag = true;
		}
		else {
			flag = false;
		}
	}
	else {
		if (year % 4 == 0 && year % 100 != 0) {
			flag = true;
		}
		else {
			flag = false;
		}
	}
	return flag;
}
int days_in_month(int day, int month, int year) {
	day = 0;
	if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) {
		day = 31;
	}
	else {
		if (month == 2) {
			if (leap_year(year)) {
				day = 29;
			}
			else {
				day = 28;
			}
		}
		else {
			day = 30;
		}
	}
	return day;
}
int day_of_the_week(int day, int month, int year) {
	int kmonth = -1, kyear = -1, kday = -1;
	if (!leap_year(year)) {
		if (month == 1 || month == 10) {
			kmonth = 1;
		}
		else if (month == 2 || month == 3 || month == 11) {
			kmonth = 4;
		}
		else if (month == 4 || month == 7) {
			kmonth = 0;
		}
		else if (month == 9 || month == 12) {
			kmonth = 6;
		}
		else if (month == 5) {
			kmonth = 2;
		}
		else if (month == 6) {
			kmonth = 5;
		}
		else if (month == 8) {
			kmonth = 3;
		}
	}
	else {
		if (month == 1 || month == 4 || month == 7) {
			kmonth = 0;
		}
		else if (month == 2 || month == 8) {
			kmonth = 3;
		}
		else if (month == 3 || month == 11) {
			kmonth = 4;
		}
		else if (month == 9 || month == 12) {
			kmonth = 6;
		}
		else if (month == 5) {
			kmonth = 2;
		}
		else if (month == 6) {
			kmonth = 5;
		}
		else if (month == 10) {
			kmonth = 1;
		}
	}
	if (year / 100 == 20) {
		kyear = (6 + (year % 100) + ((year % 100) / 4)) % 7;
	}
	else if (year / 100 == 19) {
		kyear = (0 + (year % 100) + ((year % 100) / 4)) % 7;
	}
	kday = (day + kmonth + kyear) % 7;
	return kday;
}
int days_in_data(int day, int month, int year) {
	int alldays = 0;
	alldays = day;
	while (year > 0 || (year == 0 && month > 1)) {
		month--;
		if (month == 0) {
			month = 12;
			year--;
		}
		alldays += days_in_month(0, month, year);
	}
	return alldays;
}
int seconds_in_time(int hour, int minutes, int seconds) {
	int allseconds = 0;
	allseconds = hour * 3600 + minutes * 60 + seconds;
	return allseconds;
}
void main() {
	setlocale(LC_ALL, "Rus");
	int day1 = 0, month1 = 0, year1 = 0;
	int day2 = 0, month2 = 0, year2 = 0;
	int sec1 = 0, minute1 = 0, hour1 = 0;
	int sec2 = 0, minute2 = 0, hour2 = 0;
	int t11, t22, dt11, dt22;
	int k;
	int daysm;
	int month11;
	int days = 0, abs_days = 0;
	int days_in_data1, days_in_data2;
	int seconds_in_time1, seconds_in_time2;
	int dif_data, dif_time;
	int hours_in_dif, minutes_in_dif, seconds_in_dif;
	int s = 1;
	bool was_days = false;
	bool was_t1 = false;
	bool was_t2 = false;
	bool was_dt1 = false;
	bool was_dt2 = false;
	menu(s, hour1, minute1, sec1, day1, month1, year1, hour2, minute2, sec2, day2, month2, year2, days);
	while (1) {
		k = _getch();
		system("cls");
		if (k == UP) {
			s = s - 1;
			if (s < 1) s = 1;
		}
		if (k == DOWN) {
			s = s + 1;
			if (s > 7) s = 7;
		}
		menu(s, hour1, minute1, sec1, day1, month1, year1, hour2, minute2, sec2, day2, month2, year2, days);
		if (k == ENTER) {
			k = s + '0'; //по аське 0 = 48, т.е. к = код числа по аське
		}
		if (k == '1') {
			was_t1 = false;
			printf("Введите первое время: ");
			time(t);
			hour1 = t[0] * 10 + t[1];
			minute1 = t[2] * 10 + t[3];
			sec1 = t[4] * 10 + t[5];
			if (0 <= hour1  && hour1 <= 24 && 0 <= minute1 && minute1 <= 60 && 0 <= sec1 && sec1 <= 60) {
				printf("\nЧасы: %d Минуты: %d Секунды: %d", hour1, minute1, sec1);
				was_t1 = true;
			}
			else {
				was_t1 = false;
				printf("\nВведите другое время");
				hour1 = 0;
				minute1 = 0;
				sec1 = 0;
			}
		}
		if (k == '2') {
			was_dt1 = false;
			printf("Введите первую дату: ");
			data(d);
			day1 = d[0] * 10 + d[1];
			month1 = d[2] * 10 + d[3];
			year1 = d[4] * 1000 + d[5] * 100 + d[6] * 10 + d[7];
			if (1 <= day1 && day1 <= 31 && 1 <= month1 && month1 <= 12 && 1930 <= year1 && year1 <= 2030 && day1 <= days_in_month(day1, month1, year1)) {
				was_dt1 = true;
				printf("\nDAY: %d\nMONTH: %d\nYEAR: %d", day1, month1, year1);
				if (day_of_the_week(day1, month1, year1) == 0) {
					printf("\nДень недели: Суббота");
				}
				if (day_of_the_week(day1, month1, year1) == 1) {
					printf("\nДень недели: Воскресенье");
				}
				if (day_of_the_week(day1, month1, year1) == 2) {
					printf("\nДень недели: Понедельник");
				}
				if (day_of_the_week(day1, month1, year1) == 3) {
					printf("\nДень недели: Вторник");
				}
				if (day_of_the_week(day1, month1, year1) == 4) {
					printf("\nДень недели: Среда");
				}
				if (day_of_the_week(day1, month1, year1) == 5) {
					printf("\nДень недели: Четверг");
				}
				if (day_of_the_week(day1, month1, year1) == 6) {
					printf("\nДень недели: Пятница");
				}
			}
			else {
				was_dt1 = false;
				printf("\nВведите другую дату: ");
				day1 = 0;
				month1 = 0;
				year1 = 0;
			}
			/*if (day_of_the_week(day1, month1, year1) == 0) {
				printf("\nДень недели: Суббота");
			}
			if (day_of_the_week(day1, month1, year1) == 1) {
				printf("\nДень недели: Воскресенье");
			}
			if (day_of_the_week(day1, month1, year1) == 2) {
				printf("\nДень недели: Понедельник");
			}
			if (day_of_the_week(day1, month1, year1) == 3) {
				printf("\nДень недели: Вторник");
			}
			if (day_of_the_week(day1, month1, year1) == 4) {
				printf("\nДень недели: Среда");
			}
			if (day_of_the_week(day1, month1, year1) == 5) {
				printf("\nДень недели: Четверг");
			}
			if (day_of_the_week(day1, month1, year1) == 6) {
				printf("\nДень недели: Пятница");
			}*/
		}
		if (k == '3') {
			was_t2 = false;
			printf("Введите второе время: ");
			time(t);
			hour2 = t[0] * 10 + t[1];
			minute2 = t[2] * 10 + t[3];
			sec2 = t[4] * 10 + t[5];
			if (0 <= hour2 && hour2 <= 24 && 0 <= minute2 && minute2 <= 60 && 0 <= sec2 && sec2 <= 60) {
				printf("\nЧасы: %d Минуты: %d Секунды: %d", hour2, minute2, sec2);
				was_t2 = true;
			}
			else {
				was_t2 = false;
				printf("\nВведите другое время");
				hour2 = 0;
				minute2 = 0;
				sec2 = 0;
			}
		}
		if (k == '4') {
			was_dt2 = false;
			printf("Введите первую дату: ");
			data(d);
			day2 = d[0] * 10 + d[1];
			month2 = d[2] * 10 + d[3];
			year2 = d[4] * 1000 + d[5] * 100 + d[6] * 10 + d[7];
			if (1 <= day2 && day2 <= 31 && 1 <= month2 && month2 <= 12 && 1930 <= year2 && year2 <= 2030) {
				if (day2 <= days_in_month(day2, month2, year2)) {
					was_dt2 = true;
					printf("\nDAY: %02d\nMONTH: %02d\nYEAR: %d", day2, month2, year2);
					if (day_of_the_week(day2, month2, year2) == 0) {
						printf("\nДень недели: Суббота");
					}
					if (day_of_the_week(day2, month2, year2) == 1) {
						printf("\nДень недели: Воскресенье");
					}
					if (day_of_the_week(day2, month2, year2) == 2) {
						printf("\nДень недели: Понедельник");
					}
					if (day_of_the_week(day2, month2, year2) == 3) {
						printf("\nДень недели: Вторник");
					}
					if (day_of_the_week(day2, month2, year2) == 4) {
						printf("\nДень недели: Среда");
					}
					if (day_of_the_week(day2, month2, year2) == 5) {
						printf("\nДень недели: Четверг");
					}
					if (day_of_the_week(day2, month2, year2) == 6) {
						printf("\nДень недели: Пятница");
					}
				}
			}
			else {
				was_dt2 = false;
				printf("\nВведите другую дату: ");
				day2 = 0;
				month2 = 0;
				year2 = 0;
			}
			/*if (day_of_the_week(day1, month1, year1) == 0) {
				printf("\nДень недели: Суббота");
			}
			if (day_of_the_week(day1, month1, year1) == 1) {
				printf("\nДень недели: Воскресенье");
			}
			if (day_of_the_week(day1, month1, year1) == 2) {
				printf("\nДень недели: Понедельник");
			}
			if (day_of_the_week(day1, month1, year1) == 3) {
				printf("\nДень недели: Вторник");
			}
			if (day_of_the_week(day1, month1, year1) == 4) {
				printf("\nДень недели: Среда");
			}
			if (day_of_the_week(day1, month1, year1) == 5) {
				printf("\nДень недели: Четверг");
			}
			if (day_of_the_week(day1, month1, year1) == 6) {
				printf("\nДень недели: Пятница");
			}*/
		}
		if (k == '5') {
			if (was_dt1 && was_dt2 && was_t1 && was_t2) {
				days_in_data1 = days_in_data(day1, month1, year1);
				days_in_data2 = days_in_data(day2, month2, year2);
				seconds_in_time1 = seconds_in_time(hour1, minute1, sec1);
				seconds_in_time2 = seconds_in_time(hour2, minute2, sec2);
				if (days_in_data1 >= days_in_data2) {
					dif_data = days_in_data1 - days_in_data2;
					if (seconds_in_time1 > seconds_in_time2) {
						dif_time = seconds_in_time1 - seconds_in_time2;
					}
					else if (seconds_in_time1 == seconds_in_time2) {
						dif_time = 0;
					}
					else if (seconds_in_time1 < seconds_in_time2) {
						dif_data = dif_data - 1;
						dif_time = seconds_in_time1 + 24 * 3600 - seconds_in_time2;
					}
				}
				else {
					dif_data = days_in_data2 - days_in_data1;
					if (seconds_in_time2 > seconds_in_time1) {
						dif_time = seconds_in_time2 - seconds_in_time1;
					}
					else if (seconds_in_time1 == seconds_in_time2) {
						dif_time = 0;
					}
					else if (seconds_in_time2 < seconds_in_time1) {
						dif_data = dif_data - 1;
						dif_time = seconds_in_time2 + 24 * 3600 - seconds_in_time1;
					}
				}
				hours_in_dif = dif_time / 3600;
				dif_time = dif_time - hours_in_dif * 3600;
				minutes_in_dif = dif_time / 60;
				dif_time = dif_time - minutes_in_dif * 60;
				seconds_in_dif = dif_time;
				if (day_of_the_week(day1, month1, year1) == 0) {
					printf("\nДень недели: Суббота");
				}
				if (day_of_the_week(day1, month1, year1) == 1) {
					printf("\nДень недели: Воскресенье");
				}
				if (day_of_the_week(day1, month1, year1) == 2) {
					printf("\nДень недели: Понедельник");
				}
				if (day_of_the_week(day1, month1, year1) == 3) {
					printf("\nДень недели: Вторник");
				}
				if (day_of_the_week(day1, month1, year1) == 4) {
					printf("\nДень недели: Среда");
				}
				if (day_of_the_week(day1, month1, year1) == 5) {
					printf("\nДень недели: Четверг");
				}
				if (day_of_the_week(day1, month1, year1) == 6) {
					printf("\nДень недели: Пятница");
				}

				if (day_of_the_week(day2, month2, year2) == 0) {
					printf("\nДень недели: Суббота");
				}
				if (day_of_the_week(day2, month2, year2) == 1) {
					printf("\nДень недели: Воскресенье");
				}
				if (day_of_the_week(day2, month2, year2) == 2) {
					printf("\nДень недели: Понедельник");
				}
				if (day_of_the_week(day2, month2, year2) == 3) {
					printf("\nДень недели: Вторник");
				}
				if (day_of_the_week(day2, month2, year2) == 4) {
					printf("\nДень недели: Среда");
				}
				if (day_of_the_week(day2, month2, year2) == 5) {
					printf("\nДень недели: Четверг");
				}
				if (day_of_the_week(day2, month2, year2) == 6) {
					printf("\nДень недели: Пятница");
				}
				printf("\nРазница: %d дней, %02d:%02d:%02d", dif_data, hours_in_dif, minutes_in_dif, seconds_in_dif);
			}
			else {
				printf("Проверьте корректность введенных данных");
			}
			/*else if (was_dt1 == true && was_dt2 == false && was_t1 && was_t2) {
				printf("Введите вторую дату\n");
			}
			else if (was_dt1 == false && was_dt2 == true && was_t1 && was_t2) {
				printf("Введите первую дату\n");
			}
			else if (was_dt1 == false && was_dt2 == false && was_t1 && was_t2) {
				printf("Введите первую и вторую дату\n");
			}*/
		}
		if (k == '6') {
			was_days = false;
			printf("Введите количество дней от -10000 до +10000 (дни прибавляются к первой дате): ");
			scanf("%d", &days);
			/*abs_days = abs(days);
			printf("%d", abs_days);*/
			if (-10000 <= days && days <= 10000) {
				was_days = true;
			}
			else {
				was_days = false;
				printf("Введите количество дней в диапазоне от -10000 до 10000 включительно");
				scanf("%d", &days);
			}
			/*printf("Первая дата: %02d.%02d.%d\n", day1, month1, year1);
			printf("Добавляем количество дней: %d\n", days);*/
			/*if (-10000 <= days && days <= 10000) {
				printf("days: %d\n", days);
				if (days >= 0) {
					day11 += days;
					if (day11 > days_in_month(day1, month1, year1)) {
						while (day11 > days_in_month(0, month11, year11)) {
							day11 -= days_in_month(0, month11, year11);
							month11++;
							if (month11 > 12) {
								month11 -= 12;
								year11++;
							}
						}

					}
				}
				else if (days < 0) {
					day11 += days;

					while (day11 <= 0) {
						month11--;
						if (month11 <= 0) {
							month11 = 12;
							year11--;
						}
						day11 += days_in_month(0, month11, year11);
					}
				printf("Результат: %02d.%02d.%d\n", day11, month11, year11);
			}*/
		}
		if (k == '7') {
			int month11 = month1;
			int day11 = day1;
			int year11 = year1;
			if (was_days && was_dt1) {
				printf("\nПервая дата: %02d.%02d.%d", day1, month1, year1);
				if (day_of_the_week(day1, month1, year1) == 0) {
					printf("\nДень недели: Суббота");
				}
				if (day_of_the_week(day1, month1, year1) == 1) {
					printf("\nДень недели: Воскресенье");
				}
				if (day_of_the_week(day1, month1, year1) == 2) {
					printf("\nДень недели: Понедельник");
				}
				if (day_of_the_week(day1, month1, year1) == 3) {
					printf("\nДень недели: Вторник");
				}
				if (day_of_the_week(day1, month1, year1) == 4) {
					printf("\nДень недели: Среда");
				}
				if (day_of_the_week(day1, month1, year1) == 5) {
					printf("\nДень недели: Четверг");
				}
				if (day_of_the_week(day1, month1, year1) == 6) {
					printf("\nДень недели: Пятница");
				}
				printf("\nДобавляем количество дней: %d\n", days);
				if (-10000 <= days && days <= 10000) {
					//printf("days: %d\n", days);
					if (days >= 0) {
						day11 += days;
						if (day11 > days_in_month(day1, month1, year1)) {
							while (day11 > days_in_month(0, month11, year11)) {
								day11 -= days_in_month(0, month11, year11);
								month11++;
								if (month11 > 12) {
									month11 -= 12;
									year11++;
								}
							}

						}
						printf("Результат: %02d.%02d.%d", day11, month11, year11);
						if (day_of_the_week(day11, month11, year11) == 0) {
							printf("\nДень недели новой даты: Суббота");
						}
						if (day_of_the_week(day11, month11, year11) == 1) {
							printf("\nДень недели новой даты: Воскресенье");
						}
						if (day_of_the_week(day11, month11, year11) == 2) {
							printf("\nДень недели новой даты: Понедельник");
						}
						if (day_of_the_week(day11, month11, year11) == 3) {
							printf("\nДень недели новой даты: Вторник");
						}
						if (day_of_the_week(day11, month11, year11) == 4) {
							printf("\nДень недели новой даты: Среда");
						}
						if (day_of_the_week(day11, month11, year11) == 5) {
							printf("\nДень недели новой даты: Четверг");
						}
						if (day_of_the_week(day11, month11, year11) == 6) {
							printf("\nДень недели новой даты: Пятница");
						}
					}
					else if (days < 0) {
						day11 += days;

						while (day11 <= 0) {
							month11--;
							if (month11 <= 0) {
								month11 = 12;
								year11--;
							}
							day11 += days_in_month(0, month11, year11);
						}
						printf("Результат: %02d.%02d.%d", day11, month11, year11);
						if (day_of_the_week(day11, month11, year11) == 0) {
							printf("\nДень недели новой даты: Суббота");
						}
						if (day_of_the_week(day11, month11, year11) == 1) {
							printf("\nДень недели новой даты: Воскресенье");
						}
						if (day_of_the_week(day11, month11, year11) == 2) {
							printf("\nДень недели новой даты: Понедельник");
						}
						if (day_of_the_week(day11, month11, year11) == 3) {
							printf("\nДень недели новой даты: Вторник");
						}
						if (day_of_the_week(day11, month11, year11) == 4) {
							printf("\nДень недели новой даты: Среда");
						}
						if (day_of_the_week(day11, month11, year11) == 5) {
							printf("\nДень недели новой даты: Четверг");
						}
						if (day_of_the_week(day11, month11, year11) == 6) {
							printf("\nДень недели новой даты: Пятница");
						}
					}
				}
			}
			else if (!was_days && was_dt1) {
				printf("Введите количество дней в 6 пункте\n");
			}
			else if (was_days && !was_dt1) {
				printf("Введите дату в 2 пункте\n");
			}
			else if (!was_days && !was_dt1) {
				printf("Введите первую дату в пункте 2\nВведите количество дней в 6 пункте\n");
			}
		}
	}

	_getch();
	return 0;
}
