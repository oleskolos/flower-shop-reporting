#include "classes.h"


//заповнення конструкторів, Геттерів та Сеттерів
Date::Date() {
	year = 0;
	week = 0;
	day = 0;
}
Date::Date(int day, int week, int year) {
	this->year = year;
	this->week = week;
	this->day = day;
}
Date::Date(const Date& obj)
{
	year = obj.year;
	week = obj.week;
	day = obj.day;
}
Date::~Date() {

}
int Date::GetDay()
{
	return day;
}
int Date::GetWeek()
{
	return week;
}
int Date::GetYear()
{
	return year;
}
Date& Date::operator= (const Date obj)
{
	// захист від самоприсвоєння
	if (this == &obj)
		return *this;

	// робимо копію
	year = obj.year;	// можуть обрабляти самоприсвоєння
	week = obj.week;
	day = obj.day; 

	// повертаємо існуючий об'єкт, щоб
	// можна було додати цей оператор в ланцюжок
	return *this;
}
//перевантажуємо оператори
bool operator== (Date var1, Date var2)
{
	return (var1.year == var2.year &&
		var1.week == var2.week &&
		var1.day == var2.day);
}
bool operator!= (Date var1, Date var2)
{
	return !(var1 == var2);
}
ostream& operator<<(ostream& out, Date obj)
{
	out << obj.day << "." << obj.week << "." << obj.year;
	return out;
}
istream& operator>>(istream& in, Date& obj)
{
	in >> obj.day >> obj.week >> obj.year;
	return in;
}
//перевірка на коректність вводу
void Date::ScannerYear(char* _year)
{
	int temp;
	char* ctemp = new char[100];
	if (atoi(_year)) temp = atoi(_year);
	else
	{
		cout << "Input number year: ";
		do cin >> ctemp; while (!atoi(ctemp));
		temp = atoi(ctemp);
	}
	if (temp > 1790 && temp < 2022) SetYear(temp);
	else
	{
		do
		{
			cout << "Input 1791-2021 year: ";
			cin >> temp;
		} while (!(temp > 1790 && temp < 2022));
	}
	SetYear(temp);
}
void Date::SetYear(int year)
{
	this->year = year;
}
void Date::ScannerWeek(char* _week)
{
	int temp;
	char* ctemp = new char[100];
	if (atoi(_week)) temp = atoi(_week);
	else
	{
		cout << "Input number week: ";
		do cin >> ctemp; while (!atoi(ctemp));
		temp = atoi(ctemp);
	}
	if (temp > 1 && temp < 53) SetWeek(temp);
	else
	{
		do
		{
			cout << "Input 1-52 week: ";
			cin >> temp;
		} while (!(temp > 1 && temp < 53));
	}
	SetWeek(temp);
}
void Date::SetWeek(int week)
{
	this->week = week;
}
void Date::ScannerDay(char* _day)
{
	int temp;
	char* ctemp = new char[100];
	if (atoi(_day)) temp = atoi(_day);
	else
	{
		cout << "Input number week: ";
		do cin >> ctemp; while (!atoi(ctemp));
		temp = atoi(ctemp);
	}
	if (temp > 1 && temp < 53) SetWeek(temp);
	else
	{
		do
		{
			cout << "Input 1-52 week: ";
			cin >> temp;
		} while (!(temp > 1 && temp < 53));
	}
	SetWeek(temp);
}
void Date::SetDay(int day)
{
	this->week = week;
}


//заповнення конструкторів, Геттерів та Сеттерів

Flower::Flower()
{
	name = "";
	color = "";
}
Flower::Flower(string name, string color)
{
	this->name = name;
	this->color = color;
}
Flower::Flower(const Flower& obj)
{
	name = obj.name;
	color = obj.color;
}
Flower::~Flower() {

}
string Flower::GetName()
{
	return name;
}
string Flower::GetColor()
{
	return color;
}
void Flower::SetName(string _name)
{
	name = _name;
}
void Flower::SetColor(string _color)
{
	color = _color;
}
void Flower::ScannerName(char* _name)
{
	char* temp;
	if (strlen(_name) < 20 && !atoi(_name) && isupper(_name[0])) SetName(_name); //atoi - character-to-number conversion function
	else
	{
		do
		{
			temp = new char[100];
			cout << "Input name word in capital: ";
			cin >> temp;
		} while (!(strlen(temp) < 20 && !atoi(temp) && isupper(temp[0])));
		SetName(temp);
	}
}
void Flower::ScannerColor(char* _color)
{
	char* temp;
	if (strlen(_color) < 20 && !atoi(_color) && isupper(_color[0])) SetColor(_color); //atoi - character-to-number conversion function
	else
	{
		do
		{
			temp = new char[100];
			cout << "Input name word in capital: ";
			cin >> temp;
		} while (!(strlen(temp) < 20 && !atoi(temp) && isupper(temp[0])));
		SetColor(temp);
	}
Flower& Flower::operator= (Flower& obj)
{
	// захист від самоприсвоєння
	if (this == &obj)
		return *this;

	// робимо копію
	name = obj.name; // можуть обрабляти самоприсвоєння
	color = obj.color;
	// повертаємо існуючий об'єкт, щоб
	//  можна було додати цей оператор в ланцюжок
	return *this;
}
//перевантаж. оператори
bool operator== (Flower var1, Flower var2)
{
	return (var1.name == var2.name &&
		var1.color == var2.color);
}
bool operator!= (Flower var1, Flower var2)
{
	return !(var1 == var2);
}
ostream& operator<<(ostream& out, Flower obj)
{
	out << obj.name << " " << obj.color << endl;
	return out;
}
istream& operator>>(istream& in, Flower& obj)
{
	in >> obj.name >> obj.color;
	return in;
}


//заповнення конструкторів, Геттерів та Сеттерів

Product::Product() : Flower()
{
	price = 0;
}
Product::Product(string name, string color, int price) : Flower(name, color) {
	this->price = price;
}
Product::Product(Product& obj) : Flower(obj)
{
	price = obj.price;
}
Product::~Product()
{

}
int Product::GetPrice()
{
	return price;
}
void Product::SetPrice(int price)
{
	this->price = price;
}
void Product::ScannerPrice(char* price) //inventary number input function
{
	int temp;
	char* ctemp = new char[100];
	if (atoi(price)) temp = atoi(price);
	else
	{
		cout << "Input correct price: ";
		do cin >> ctemp; while (!atoi(ctemp));
		temp = atoi(ctemp);
	}
	if (temp > 0) SetPrice(temp);
	else
	{
		do
		{
			cout << "Input natural number of price: ";
			cin >> temp;
		} while (!(temp > 0));
	}
	SetPrice(temp);
}
Product& Product::operator= (Product obj)
{
	// защита от самоприсваивания
	if (this == &obj)
		return *this;

	// делаем копию
	SetColor(obj.GetColor());
	SetName(obj.GetName());
	price = obj.price;		// можуть обрабляти самоприсвоєння

	// повертаємо існуючий об'єкт, щоб
	//  можна було додати цей оператор в ланцюжок
	return *this;
}
//перевантаж. оператори
bool operator== (Product& var1, Product& var2)		
	return (var1.GetName() == var2.GetName() &&
		var1.GetColor() == var2.GetColor() &&
		var1.price == var2.price);
}
bool operator!= (Product& var1, Product& var2)
{
	return !(var1 == var2);
}
ostream& operator<<(ostream& out, Product obj)
{
	out << obj.GetName() << " " << obj.GetColor() << " " << obj.price << endl;
	return out;
}
istream& operator>>(istream& in, Product& obj)
{
	string name, color;
	in >> name >> color >> obj.price;
	obj.SetName(name);
	obj.SetColor(color);
	return in;
}


//заповнення конструкторів, Геттерів та Сеттерів

List_Flower::List_Flower()
{
	list = NULL;
	number = 0;
}
List_Flower::List_Flower(Flower* list, int number) {
	this->list = new Flower[number];
	for (int i = 0; i < number; i++)
	{
		this->list[i] = list[i];
	}
	this->number = number;
}
List_Flower::List_Flower(List_Flower& obj) {
	this->list = new Flower[obj.number];
	for (int i = 0; i < obj.number; i++)
	{
		this->list[i] = obj.list[i];
	}
	this->number = obj.number;
}
List_Flower::~List_Flower() {

}
void List_Flower::SetNumber(int number)
{
	this->number = number;
}
void List_Flower::ScannerNumber(char* number) // number input function
{
	int temp;
	char* ctemp = new char[100];
	if (atoi(number)) temp = atoi(number);
	else
	{
		cout << "Input correct number: ";
		do cin >> ctemp; while (!atoi(ctemp));
		temp = atoi(ctemp);
	}
	if (temp > 0) SetNumber(temp);
	else
	{
		do
		{
			cout << "Input natural number: ";
			cin >> temp;
		} while (!(temp > 0));
	}
	SetNumber(temp);
}
//перевантаж. оператори
List_Flower& List_Flower::operator= (List_Flower& obj)
{
	// защита от самоприсваивания
	if (this == &obj)
		return *this;

	// делаем копию
	this->list = new Flower[obj.number];
	for (int i = 0; i < obj.number; i++)
	{
		this->list[i] = obj.list[i];
	}
	this->number = obj.number;		// можуть обрабляти самоприсвоєння
	//повертаєсо існ. об'єкт, щоб
	// можна було додати цей оператор в ланцююжок
	return *this;
}
Flower& List_Flower::operator [] (int i)
{
	return list[i];
}
bool operator== (List_Flower& var1, List_Flower& var2)		
{
	return (var1.list == var2.list &&
		var1.number == var2.number);
}
bool operator!= (List_Flower& var1, List_Flower& var2)
{
	return !(var1 == var2);
}


//заповнення конструкторів, Геттерів та Сеттерів

Sale_Operation::Sale_Operation() : product(), date()
{
	number = 0;
	price_operation = 0;
}
Sale_Operation::Sale_Operation(Product product, int number, Date date) : product(product), date(date)
{
	this->number = number;
	price_operation = number * product.GetPrice();
}
Sale_Operation::Sale_Operation(Sale_Operation& obj) : product(obj.product), date(obj.date) {
	this->number = obj.number;
	price_operation = obj.number * obj.product.GetPrice();
}
Sale_Operation::~Sale_Operation() {

}
Product Sale_Operation::GetProduct()
{
	return product;
}
int Sale_Operation::GetNumber()
{
	return number;
}
int Sale_Operation::GetPriceOperation()
{
	return price_operation;
}
Date Sale_Operation::GetDate()
{
	return date;
}
void Sale_Operation::ScannerNumber(char* number) // number input function
{
	int temp;
	char* ctemp = new char[100];
	if (atoi(number)) temp = atoi(number);
	else
	{
		cout << "Input correct number: ";
		do cin >> ctemp; while (!atoi(ctemp));
		temp = atoi(ctemp);
	}
	if (temp > 0) temp = 1;
	else
	{
		do
		{
			cout << "Input natural number: ";
			cin >> temp;
		} while (!(temp > 0));
	}
}
Sale_Operation& Sale_Operation::operator= (Sale_Operation obj)
{
	// захист від самоприсвоєння
	if (this == &obj)
		return *this;

	// робимо копію
	this->product = obj.product;
	this->number = obj.number;									// можуть оброблювати самоприсвоєння
	this->price_operation = obj.price_operation;
	this->date = obj.date;	
	// повертає існуючий об'єкт, щоб
	// можна було додати цей оператор в ланцюжжок
	return *this;
}
//перевантаж. оператори
bool operator== (Sale_Operation& var1, Sale_Operation& var2)
{
	return (var1.number == var2.number &&
		var1.price_operation == var2.price_operation &&
		var1.date == var2.date &&
		var1.product == var2.product);
}
bool operator!= (Sale_Operation& var1, Sale_Operation& var2)
{
	return !(var1 == var2);
}
ostream& operator<<(ostream& out, Sale_Operation obj)
{
	out << obj.product << " " << obj.number << " " << obj.price_operation << " " << obj.date << endl;
	return out;
}
istream& operator>>(istream& in, Sale_Operation& obj)
{
	in >> obj.product >> obj.number >> obj.date;
	obj.price_operation = obj.product.GetPrice() * obj.number;
	return in;
}


//заповнення конструкторів, Геттерів та Сеттерів

Week_Operations::Week_Operations()
{
	list = NULL;
	number_operation = 0;
	total_sum = 0;
}
Week_Operations::Week_Operations(Sale_Operation* list, int number_operation)
{
	this->list = new Sale_Operation[number_operation];
	for (int i = 0; i < number_operation; i++)
	{
		this->list[i] = list[i];
	}
	this->number_operation = number_operation;
	total_sum = 0;
	for (int i = 0; i < number_operation; i++)
	{
		total_sum += list[i].GetPriceOperation();
	}
}
Week_Operations::Week_Operations(const Week_Operations& obj)
{
	list = new Sale_Operation[obj.number_operation];
	for (int i = 0; i < obj.number_operation; i++)
	{
		list[i] = obj.list[i];
	}
	number_operation = obj.number_operation;
	total_sum = obj.total_sum;
}
Week_Operations::~Week_Operations() {

}
Sale_Operation* Week_Operations::GetList()
{
	return list;
}
int Week_Operations::GetNumberOperation()
{
	return number_operation;
}
int Week_Operations::GetTotalSum()
{
	return total_sum;
}
void Week_Operations::SetList(Sale_Operation* list, int number_operation)
{
	this->list = new Sale_Operation[number_operation];
	for (int i = 0; i < number_operation; i++)
	{
		this->list[i] = list[i];
	}
	this->number_operation = number_operation;
	total_sum = 0;
	for (int i = 0; i < number_operation; i++)
	{
		total_sum += list[i].GetPriceOperation();
	}
}
void Week_Operations::SetNumberOperation(int number_operation)
{
	this->number_operation = number_operation;
}
void Week_Operations::ScannerNumberOperation(char* number_operation) // number_operation input function
{
	int temp;
	char* ctemp = new char[100];
	if (atoi(number_operation)) temp = atoi(number_operation);
	else
	{
		cout << "Input correct number: ";
		do cin >> ctemp; while (!atoi(ctemp));
		temp = atoi(ctemp);
	}
	if (temp > 0) SetNumberOperation(temp);
	else
	{
		do
		{
			cout << "Input natural number: ";
			cin >> temp;
		} while (!(temp > 0));
	}
	SetNumberOperation(temp);
}
Week_Operations& Week_Operations::operator= (Week_Operations obj)
{
	// захист від самоприсвоєння
	if (this == &obj)
		return *this;

	// робимо копію
	list = new Sale_Operation[obj.number_operation];
	for (int i = 0; i < obj.number_operation; i++)
	{
		list[i] = obj.list[i];
	}
	number_operation = obj.number_operation;		
	total_sum = obj.total_sum;						// можуть обробляти самоприсвоєння
	// повертаємо існуючий об'єкт, щоб 
	// можна було додати цей оператор в ланцюжжок
	return *this;
}
//перевантаж. оператори
bool operator== (Week_Operations& var1, Week_Operations& var2)
{

	return (var1.number_operation == var2.number_operation &&
		var1.total_sum == var2.total_sum &&
		var1.list == var2.list);
}
bool operator!= (Week_Operations& var1, Week_Operations& var2)
{
	return !(var1 == var2);
}
Sale_Operation& Week_Operations::operator[](int i)
{
	return list[i];
}