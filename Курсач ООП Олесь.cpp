#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <string.h> 
#include <string>
#include "classes.h"
using namespace std;



template <class T>			//шаблон функції сер. знач. кількості квітів 
double MiddleNumber(T& obj)
{
	int all_number = 0;
	for (int i = 0; i < obj.GetNumberOperation(); i++) all_number += obj[i].GetNumber();

	double mid_num = all_number / obj.GetNumberOperation();

	return mid_num;
}
template <class T>			//шаблон функції сер. знач. виручки
double MiddlePrice(T& obj)
{
	double mid_sum = obj.GetTotalSum() / obj.GetNumberOperation();

	return mid_sum;
}

void WriteReport1(Week_Operations& report) //запис у файл
{
	ofstream fout("Report(bin).txt", ios_base::binary); //виключна ситуація
	try
	{
		if (!fout.is_open()) throw - 1;			//перевірка на відкриття фйалу
	}
	catch (int)
	{
		cout << "Program couldn`t write data in file!";
	}

	fout << report.GetNumberOperation();
	for (int i = 0; i < report.GetNumberOperation(); i++)
	{
		fout.write((char*)&report[i], sizeof(Sale_Operation)); //безпосередньо записуємо використовуючи функцію write()
	}

	fout.close(); //закриваємо файл
}
void ReadReport1(Week_Operations& report) //зчитування з файлу
{
	ifstream fin("Report(bin).txt", ios_base::binary);
	//виключна ситуація
	try
	{
		if (!fin.is_open()) throw - 1;				//перевірка на відкриття фйалу
	}
	catch (int)
	{
		cout << "Program couldn`t read data from file!";
	}


	int n;
	fin >> n;
	Sale_Operation* list = new Sale_Operation[n];
	for (int i = 0; i < n; i++)
	{
		fin.read((char*)&list[i], sizeof(Sale_Operation)); // безпосередньо записуємо використовуючи функцію read()
	}
	report.SetList(list, n);

	fin.close(); //закриваємо файл
}

//аналогічно проводимо тіж операціїї, але не використовуємо ios_base::binary
void WriteReport2(Week_Operations& report)
{
	ofstream fout("Report.txt");

	try
	{
		if (!fout.is_open()) throw - 1;
	}
	catch (int)
	{
		cout << "Program couldn`t write data in file!";
	}

	fout << report.GetNumberOperation();
	for (int i = 0; i < report.GetNumberOperation(); i++)
	{
		fout.write((char*)&report[i], sizeof(Sale_Operation));
	}

	fout.close();
}
void ReadReport2(Week_Operations& report)
{
	ifstream fin("Report.txt");

	try
	{
		if (!fin.is_open()) throw - 1;
	}
	catch (int)
	{

	}


	int n;
	fin >> n;
	Sale_Operation* list = new Sale_Operation[n];
	for (int i = 0; i < n; i++)
	{
		fin.read((char*)&list[i], sizeof(Sale_Operation));
	}
	report.SetList(list, n);

	fin.close();
}
void PrintReport(Week_Operations& report) //виведення даних у вигл. таблиці
{
	unsigned char					//ініціалізація та присвоєння змінним ASCCI-кодів
		top_left_angle = 201,
		gorizontal = 205,
		top_right_angle = 187,
		vertical = 186,
		down_left_angle = 200,
		down_right_angle = 188,
		center = 206,
		top_center = 203,
		down_center = 202,
		left_center = 204,
		right_center = 185;

	printf("%c", top_left_angle);
	for (int i = 0; i < 90; i++)
	{
		if (i != 15 && i != 30 && i != 45 && i != 60 && i != 75) printf("%c", gorizontal);
		else  printf("%c", top_center);
	}
	printf("%c\n", top_right_angle);
	printf("%c    FLOWER     %c    COLOR     %c    NUMBER    %c     PRICE    %c     DATE     %c TOTAL PRICE  %c\n", vertical, vertical, vertical, vertical, vertical, vertical, vertical);
	printf("%c", left_center);
	for (int i = 0; i < 90; i++)
	{
		if (i != 15 && i != 30 && i != 45 && i != 60 && i != 75) printf("%c", gorizontal);
		else  printf("%c", center);
	}
	printf("%c\n", right_center);


	for (int i = 0; i < report.GetNumberOperation(); i++)
	{
		cout << vertical;
		cout << setw(15) << report[i].GetProduct().GetName() << vertical;				//використаємо функцію setw(), яка відповідає за встановлення кількості символів, які будуть використовуватися як ширина поля для наступної операції вставки
		cout << setw(14) << report[i].GetProduct().GetColor() << vertical;
		cout << setw(14) << report[i].GetNumber() << vertical;
		cout << setw(14) << report[i].GetProduct().GetPrice() << vertical;
		cout << setw(6) << report[i].GetDate() << vertical;
		cout << setw(14) << report[i].GetPriceOperation() << vertical << endl;

		printf("%c", left_center);
		for (int i = 0; i < 90; i++)
		{
			if (i != 15 && i != 30 && i != 45 && i != 60 && i != 75) printf("%c", gorizontal);
			else  printf("%c", center);
		}
		printf("%c\n", right_center);
	}

	printf("%c", down_left_angle);
	for (int i = 0; i < 90; i++)
	{
		if (i != 15 && i != 30 && i != 45 && i != 60 && i != 75) printf("%c", gorizontal);
		else  printf("%c", down_center);
	}
	printf("%c\n", down_right_angle);
}
void AddToReport(Week_Operations& report) // додавання нового елементу
{
	Sale_Operation* list = new Sale_Operation[report.GetNumberOperation() + 1];
	for (int i = 0; i < report.GetNumberOperation(); i++) list[i] = report[i];


	Product product;
	int number;
	int price_operation;
	Date date;
	cout << "Input product: ";
	cin >> product;
	cout << "Input number: ";
	cin >> number;
	cout << "Input date: ";
	cin >> date;
	Sale_Operation t(product, number, date);
	list[report.GetNumberOperation()] = t;

	Week_Operations temp(list, report.GetNumberOperation() + 1);
	report = temp;
}
void DeleteFromReport(Week_Operations& report) //видалення необхідного елементу
{
	cout << "Which element you want delete? ";
	int number;
	cin >> number;
	while (number <= 0 || number > report.GetNumberOperation())
	{
		cout << "Unreal index, try againe: ";
		cin >> number;
	}

	Sale_Operation* list = new Sale_Operation[report.GetNumberOperation() - 1];
	for (int i = 0; i < number - 1; i++)
	{
		list[i] = report[i];
	}
	for (int i = number; i < report.GetNumberOperation(); i++)
	{
		list[i - 1] = report[i];
	}

	Week_Operations temp(list, report.GetNumberOperation() - 1);
	report = temp;
}
void SearchFlowerInReport(Week_Operations& report) // пошук за текстом
{
	int n = report.GetNumberOperation();
	cout << "Input flower: ";
	string name;
	cin >> name;

	int m = 0;
	for (int i = 0; i < n; i++)
	{
		if (name == report[i].GetProduct().GetName()) m++;
	}
	Sale_Operation* temp_list = new Sale_Operation[m];

	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (name == report[i].GetProduct().GetName())
		{
			temp_list[j++] = report[i];
		}
	}

	if (!m)
	{
		cout << "We don't have this flower\n";
	}
	else
	{
		Week_Operations temp_report(temp_list, m);
		PrintReport(temp_report);
	}
}
void SearchDateInReport(Week_Operations& report) // пошук за числом
{
	int n = report.GetNumberOperation();
	cout << "Input date: ";
	Date date;
	cin >> date;

	int m = 0;
	for (int i = 0; i < n; i++)
	{
		Date date1();
		if (date == report[i].GetDate()) m++;
	}
	Sale_Operation* temp_list = new Sale_Operation[m];

	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (date == report[i].GetDate())
		{
			temp_list[j++] = report[i];
		}
	}

	if (!m)
	{
		cout << "We don't have this date\n";
	}
	else
	{
		Week_Operations temp_report(temp_list, m);
		PrintReport(temp_report);
	}
}


void main()
{
	Week_Operations report;

	cout << "From which file you want read data? ";
	string file_type1;
	cin >> file_type1;
	//виключна ситуація
	try
	{
		if (file_type1 == "txt")
		{
			ReadReport2(report);
		}
		else
		{
			if (file_type1 == "bin")
			{
				ReadReport1(report);
			}
			else
			{
				throw - 1;
			}
		}
	}
	catch (int)
	{
		cout << "Incorrect type. Data will be write to binary file";
		ReadReport1(report);
	}

	system("pause");  //чекання будь-якого символу
	system("cls");   //очистка екрану
	//меню
	int exit = 0;
	while (!exit)
	{
		cout << "                                                    FLOWER SHOP REPORT      \n";
		cout << "                                               1. Print.\n";
		cout << "                                               2. Add.\n";
		cout << "                                               3. Delete.\n";
		cout << "                                               4. Search flower.\n";
		cout << "                                               5. Search date.\n";
		cout << "                                               6. Middle number.\n";
		cout << "                                               7. Middle price.\n";
		cout << "                                               8. Exit.\n\n";
		cout << "     Variant: ";

		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			PrintReport(report);
			break;
		case 2:
			AddToReport(report);
			break;
		case 3:
			DeleteFromReport(report);
			break;
		case 4:
			SearchFlowerInReport(report);
			break;
		case 5:
			SearchDateInReport(report);
			break;
		case 6:
			cout << MiddleNumber(report);
			break;
		case 7:
			cout << MiddlePrice(report);
			break;
		case 8:
			cout << "In which file type you want write data? ";
			string file_type2;
			cin >> file_type2;
			try
			{
				if (file_type2 == "txt")
				{
					WriteReport2(report);
				}
				else
				{
					if (file_type2 == "bin")
					{
						WriteReport1(report);
					}
					else
					{
						throw - 1;
					}
				}
			}
			catch (int)
			{
				cout << "Incorrect type. Data will be write to binary file";
			}

			exit = 1;
			break;
		}

		char next = 0;
		do
		{
			next = _getch();
			if (next == 13)
			{
				system("cls");
				break;
			}
		} while (1);
	}

}

