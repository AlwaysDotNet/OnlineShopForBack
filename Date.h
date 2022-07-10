#define _CRT_SECURE_NO_WARNINGS //Что бы компилятоор не ругался на стил Язык СИ
#pragma once
#include <ctime>
#include "Functions.h"
//Реализуес класс Даты который хранит день месяц и год
class Date
{
private:
	int day;//День от 1-31
	int month;//Месяц от 1 до 12
	int year;//Год 
public:
	Date();//Конструктор по умолчание
	Date(int d, int m, int y);//Конструктор с параметрами
	Date(const Date& d);//Конструктор копирвование
	int getDay()const;//Вернет дату
	int getMonth()const;//Вернет месяца
	int getYear()const;//Вернет год
	static Date fromString(std::string& s);//переобразование строку в виде dd-mm-yyyy где dd-ден mm -месяй а yyyy-год
	static std::string readStream();//Правильное ввод даты  
	friend istream& operator>>(istream& inp, Date& d);//Ввод через поток например через консоли
	friend ostream& operator<<(ostream& out, const Date& d);//Вывод в поток данных
	Date operator=(const Date& d);
	static Date curDate();

};

