#pragma once
//Реализуем класс клиентов магазина
#include "Functions.h"
class Client
{
private:
	string name;//Имя
	string surname;//Фамилия
	string middlename;//Отчество
	int skidka;//Имеет ли скидку  в процентах от 1-100
public:
	Client();//Конструктор по умолчание
	Client(string nm, string snm, string mnm, int sk = 0);//Конструктор с параметрами
	Client(const Client& cp);//Конструктор копирование
	Client operator=(const Client& cl);//Перегружим оператор присваивание
	//Получение значение свойства
	string getName()const;
	string getSurname()const;
	string getMiddleName()const;
	int getSkidka()const;
	//Вот 
	void setFIO(string nm, string snm, string mnm);
	void setSkidka(int percent);//Установка значение скидки
	bool operator==(const Client& cl);
	friend ostream& operator<<(ostream& out, const Client& cl);//Вывод
	friend istream& operator>>(istream& inp, Client& cl);//Получение с потока
	//Чтение с консоли
	void readData();

};

