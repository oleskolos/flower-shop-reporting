#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <string.h> 
#include <string>
using namespace std;


class Date // клас Дата
{
	int year, week, day; //Поля класу

public:
	Date();				//конструктор за замовчуванням
	Date(int, int, int); //конструктор з параметрами
	Date(const Date&);	//конструктор копіювання
	~Date();			//деструктор
	int GetDay();		//далі ййдуть метоли Геттерів та Сеттерів для полів класу 
	int GetWeek();
	int GetYear();
	void ScannerYear(char*); //Сканери для перевірки коректоного вводу даних
	void SetYear(int);
	void ScannerWeek(char*);
	void SetWeek(int);
	void ScannerDay(char*);
	void SetDay(int);
	Date& operator= (const Date obj);					//перевантаження оператора присвоєння
	friend bool operator== (Date var1, Date var2);		//перевантаження оператора порівняння "=="
	friend bool operator!= (Date var1, Date var2);		//перевантаження оператора порівняння "!="
	friend ostream& operator<<(ostream&, Date);			//перевантаження оператора виводу
	friend istream& operator>>(istream&, Date&);		//перевантаження оператора вводу
};



class Flower //клас Квітка
{
	string name;	//поля класу
	string color;

public:
	Flower();					//конструктор за замовчуванням
	Flower(string, string);		//конструктор з параметрами
	Flower(const Flower&);		//конструктор копіювання
	~Flower();					//деструктор
	string GetName();			//далі ййдуть метоли Геттерів та Сеттерів для полів класу 
	string GetColor();
	void SetName(string);
	void SetColor(string);
	void ScannerName(char*);	//Сканери для перевірки коректоного вводу даних
	void ScannerColor(char*);
	Flower& operator= (Flower& obj);					//перевантаження оператора присвоєння
	friend bool operator== (Flower var1, Flower var2);	//перевантаження оператора порівняння "=="
	friend bool operator!= (Flower var1, Flower var2);	//перевантаження оператора порівняння "!="
	friend ostream& operator<<(ostream&, Flower);		//перевантаження оператора виводу
	friend istream& operator>>(istream&, Flower&);		//перевантаження оператора вводу
};



class Product : public Flower	//клас Одиниця товару, разом з успадкуванняям від класу Квітка
{
	int price;		//поля класу

public:
	Product();						//конструктор за замовчуванням
	Product(string, string, int);	 //конструктор з параметрами
	Product(Product&);				//конструктор копіювання
	~Product();						//деструктор
	int GetPrice();					//далі ййдуть метоли Геттерів та Сеттерів для полів класу
	void ScannerPrice(char*);		//Сканери для перевірки коректоного вводу даних
	void SetPrice(int); 
	Product& operator= (Product obj);							//перевантаження оператора присвоєння
	friend bool operator== (Product& var1, Product& var2);		//перевантаження оператора порівняння "=="
	friend bool operator!= (Product& var1, Product& var2);		//перевантаження оператора порівняння "!="
	friend ostream& operator<<(ostream&, Product);				//перевантаження оператора виводу
	friend istream& operator>>(istream&, Product&);				//перевантаження оператора вводу
};


class List_Flower //клас Асортименнт продажу
{
	Flower* list; //поля класу
	int number;

public:
	List_Flower();					//конструктор за замовчуванням
	List_Flower(Flower*, int);		//конструктор з параметрами
	List_Flower(List_Flower&);		//конструктор копіювання
	~List_Flower();					//деструктор
	void SetNumber(int);			//Сеттер для number
	void ScannerNumber(char*);		//Сканер для перевірки коректоного вводу даних
	List_Flower& operator= (List_Flower& obj);							//перевантаження оператора присвоєння
	friend bool operator== (List_Flower& var1, List_Flower& var2);		//перевантаження оператора порівняння "=="
	friend bool operator!= (List_Flower& var1, List_Flower& var2);		//перевантаження оператора порівняння "!="
	Flower& operator [] (int);											//перевантаження оператора індексування
};



class Sale_Operation //клас Операція продажу
{
	Product product;			//поля класу
	int number;
	int price_operation;
	Date date;

public:
	Sale_Operation();							//конструктор за замовчуванням
	Sale_Operation(Product, int, Date);			//конструктор з параметрами
	Sale_Operation(Sale_Operation&);			//конструктор копіювання
	~Sale_Operation();							//деструктор
	Product GetProduct();						//далі ййдуть методи Геттерів для полів класу
	int GetPriceOperation();
	int GetNumber();
	Date GetDate();
	void ScannerNumber(char*);					//Сканер для перевірки коректоного вводу даних
	Sale_Operation& operator= (Sale_Operation obj);								//перевантаження оператора присвоєння
	friend bool operator== (Sale_Operation& var1, Sale_Operation& var2);		//перевантаження оператора порівняння "=="
	friend bool operator!= (Sale_Operation& var1, Sale_Operation& var2);		//перевантаження оператора порівняння "!="
	friend ostream& operator<<(ostream&, Sale_Operation);						//перевантаження оператора виводу
	friend istream& operator>>(istream&, Sale_Operation&);						//перевантаження оператора вводу
};



class Week_Operations  //клас Тижневий баланс
{
	Sale_Operation* list; //поля класу
	int number_operation;
	int total_sum;

public:
	Week_Operations();							//конструктор за замовчуванням
	Week_Operations(Sale_Operation*, int);		//конструктор з параметрами
	Week_Operations(const Week_Operations&);	//конструктор копіювання
	~Week_Operations();							//деструктор
	Sale_Operation* GetList();					//далі ййдуть метоли Геттерів та Сеттерів для полів класу
	int GetNumberOperation();
	int GetTotalSum();
	void SetList(Sale_Operation*, int);
	void SetNumberOperation(int);
	void ScannerNumberOperation(char*);			//Сканер для перевірки коректоного вводу даних
	Week_Operations& operator= (Week_Operations obj);							//перевантаження оператора присвоєння
	friend bool operator== (Week_Operations& var1, Week_Operations& var2);		//перевантаження оператора порівняння "=="
	friend bool operator!= (Week_Operations& var1, Week_Operations& var2);		//перевантаження оператора порівняння "!="
	Sale_Operation& operator[] (int);											//перевантаження оператора індексування
};
