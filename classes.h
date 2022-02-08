#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <string.h> 
#include <string>
using namespace std;


class Date // ���� ����
{
	int year, week, day; //���� �����

public:
	Date();				//����������� �� �������������
	Date(int, int, int); //����������� � �����������
	Date(const Date&);	//����������� ���������
	~Date();			//����������
	int GetDay();		//��� ������ ������ ������� �� ������� ��� ���� ����� 
	int GetWeek();
	int GetYear();
	void ScannerYear(char*); //������� ��� �������� ����������� ����� �����
	void SetYear(int);
	void ScannerWeek(char*);
	void SetWeek(int);
	void ScannerDay(char*);
	void SetDay(int);
	Date& operator= (const Date obj);					//�������������� ��������� ���������
	friend bool operator== (Date var1, Date var2);		//�������������� ��������� ��������� "=="
	friend bool operator!= (Date var1, Date var2);		//�������������� ��������� ��������� "!="
	friend ostream& operator<<(ostream&, Date);			//�������������� ��������� ������
	friend istream& operator>>(istream&, Date&);		//�������������� ��������� �����
};



class Flower //���� �����
{
	string name;	//���� �����
	string color;

public:
	Flower();					//����������� �� �������������
	Flower(string, string);		//����������� � �����������
	Flower(const Flower&);		//����������� ���������
	~Flower();					//����������
	string GetName();			//��� ������ ������ ������� �� ������� ��� ���� ����� 
	string GetColor();
	void SetName(string);
	void SetColor(string);
	void ScannerName(char*);	//������� ��� �������� ����������� ����� �����
	void ScannerColor(char*);
	Flower& operator= (Flower& obj);					//�������������� ��������� ���������
	friend bool operator== (Flower var1, Flower var2);	//�������������� ��������� ��������� "=="
	friend bool operator!= (Flower var1, Flower var2);	//�������������� ��������� ��������� "!="
	friend ostream& operator<<(ostream&, Flower);		//�������������� ��������� ������
	friend istream& operator>>(istream&, Flower&);		//�������������� ��������� �����
};



class Product : public Flower	//���� ������� ������, ����� � �������������� �� ����� �����
{
	int price;		//���� �����

public:
	Product();						//����������� �� �������������
	Product(string, string, int);	 //����������� � �����������
	Product(Product&);				//����������� ���������
	~Product();						//����������
	int GetPrice();					//��� ������ ������ ������� �� ������� ��� ���� �����
	void ScannerPrice(char*);		//������� ��� �������� ����������� ����� �����
	void SetPrice(int); 
	Product& operator= (Product obj);							//�������������� ��������� ���������
	friend bool operator== (Product& var1, Product& var2);		//�������������� ��������� ��������� "=="
	friend bool operator!= (Product& var1, Product& var2);		//�������������� ��������� ��������� "!="
	friend ostream& operator<<(ostream&, Product);				//�������������� ��������� ������
	friend istream& operator>>(istream&, Product&);				//�������������� ��������� �����
};


class List_Flower //���� ����������� �������
{
	Flower* list; //���� �����
	int number;

public:
	List_Flower();					//����������� �� �������������
	List_Flower(Flower*, int);		//����������� � �����������
	List_Flower(List_Flower&);		//����������� ���������
	~List_Flower();					//����������
	void SetNumber(int);			//������ ��� number
	void ScannerNumber(char*);		//������ ��� �������� ����������� ����� �����
	List_Flower& operator= (List_Flower& obj);							//�������������� ��������� ���������
	friend bool operator== (List_Flower& var1, List_Flower& var2);		//�������������� ��������� ��������� "=="
	friend bool operator!= (List_Flower& var1, List_Flower& var2);		//�������������� ��������� ��������� "!="
	Flower& operator [] (int);											//�������������� ��������� ������������
};



class Sale_Operation //���� �������� �������
{
	Product product;			//���� �����
	int number;
	int price_operation;
	Date date;

public:
	Sale_Operation();							//����������� �� �������������
	Sale_Operation(Product, int, Date);			//����������� � �����������
	Sale_Operation(Sale_Operation&);			//����������� ���������
	~Sale_Operation();							//����������
	Product GetProduct();						//��� ������ ������ ������� ��� ���� �����
	int GetPriceOperation();
	int GetNumber();
	Date GetDate();
	void ScannerNumber(char*);					//������ ��� �������� ����������� ����� �����
	Sale_Operation& operator= (Sale_Operation obj);								//�������������� ��������� ���������
	friend bool operator== (Sale_Operation& var1, Sale_Operation& var2);		//�������������� ��������� ��������� "=="
	friend bool operator!= (Sale_Operation& var1, Sale_Operation& var2);		//�������������� ��������� ��������� "!="
	friend ostream& operator<<(ostream&, Sale_Operation);						//�������������� ��������� ������
	friend istream& operator>>(istream&, Sale_Operation&);						//�������������� ��������� �����
};



class Week_Operations  //���� �������� ������
{
	Sale_Operation* list; //���� �����
	int number_operation;
	int total_sum;

public:
	Week_Operations();							//����������� �� �������������
	Week_Operations(Sale_Operation*, int);		//����������� � �����������
	Week_Operations(const Week_Operations&);	//����������� ���������
	~Week_Operations();							//����������
	Sale_Operation* GetList();					//��� ������ ������ ������� �� ������� ��� ���� �����
	int GetNumberOperation();
	int GetTotalSum();
	void SetList(Sale_Operation*, int);
	void SetNumberOperation(int);
	void ScannerNumberOperation(char*);			//������ ��� �������� ����������� ����� �����
	Week_Operations& operator= (Week_Operations obj);							//�������������� ��������� ���������
	friend bool operator== (Week_Operations& var1, Week_Operations& var2);		//�������������� ��������� ��������� "=="
	friend bool operator!= (Week_Operations& var1, Week_Operations& var2);		//�������������� ��������� ��������� "!="
	Sale_Operation& operator[] (int);											//�������������� ��������� ������������
};
