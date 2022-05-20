#include <iostream>
#include <string>
using namespace std;

string calculate_days(string normal_start)
{
	*year = 1900;
	*month = 1;
	*date = 1;
	while (days >= 365)
	{
		(*year)++;
		days -= 365;
	}
	while (days >= 30)
	{
		(*month)++;
		days -= 30;
	}
	*date += days;

	return 
}

int main(void)
{
	int year;
	int month;
	int date;
	calculate_days(1000, &year, &month, &date);
	cout << "< The day > " << endl;
	cout << "Year : " << year << endl;
	cout << "Month : " << month << endl;
	cout << "Date : " << date << endl;
	system("pause");
	return 0;
}


//#include <iostream>
//#include <string>
//using namespace std;
//
//void calculate_days(int days, int* year, int* month, int* date)
//{
//	*year = 1900;
//	*month = 1;
//	*date = 1;
//	while (days >= 365)
//	{
//		(*year)++;
//		days -= 365;
//	}
//	while (days >= 30)
//	{
//		(*month)++;
//		days -= 30;
//	}
//	*date += days;
//}
//
//int main(void)
//{
//	int year;
//	int month;
//	int date;
//	calculate_days(1000, &year, &month, &date);
//	cout << "< The day > " << endl;
//	cout << "Year : " << year << endl;
//	cout << "Month : " << month << endl;
//	cout << "Date : " << date << endl;
//	system("pause");
//	return 0;
//}

