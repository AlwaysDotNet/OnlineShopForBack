#pragma once
#include <cstring>
#include <string>
#include "Functions.h"
//Реализуем класс который хранит данные о товаров магазина
/*
  Какие свойтства имеет Товары магазина
  ------------------
  |     Product    |
  ------------------
  |-Название       |
  |-Стоимость      |Это стоимость по какому то величену например кило или типа количество 
  |-Цена           |Это цена который магазин товаров вставит стоимость +сколько то суммов
  |-величина счета | Например килограмм или количество или может пачка это тип перечислмое
  |-Количество     |Количество по величены который храниться в склад магазин товаров
  |-срок хранеие   | Задаеться в месяцах сколько месяц можно хранит если вечно то значение равно 0
  -----------------
*/

using std::string;//Используем строку токого типа
class Product
{
private:
	string name;//Название
	double cost;//Стоимость
	double mark;//Цена
	int cnt;//Количество товара
	enum TypeWeight//Величина 
	{
		CNT=1,//Количество то есть один два и т д
		PACKGE,//Упаковка бутилка и типа 
		WEIGHT,//К кг
	};
	TypeWeight tp;
	int srok;//Срока хранение
	//Переобразование целое в перечесляемое тип который ранее создали
	TypeWeight setType(int ch = 1);
	TypeWeight getType()const;
	TypeWeight StrToTypeW(string tp);//Из характеристика измерение в строку
public:
	Product();//Простой конструктор
	Product(string name, double cs, double mark, int cnt = 1, int _tp = 1, int srok = 0);//Конструктор с параметрами
	Product(const Product& pr);//Копирование объекта
	//Геттеры
	string getName()const;//Название 
	string getRazdacha()const;//Возврашает единица хранение товара или раздача
	double getCost()const;//Получение стоимости
	double getMarks()const;//Получение цен
	int getSrokMonth()const;//Получение срока
	int getCnt()const;//Количество
	//Сеттеры методы установки данные свйоства
	void setName(const string& s);
	void setRazdacha(int tp);
	void setRazdacha(string tp);
	void setCost(double cn);
	void setMarks(double mr);
	void setSrok(int sr);
	void setCount(int cnt);
	//Перегружим оператор вывода
	Product operator--(int);//Постфиксный декремент уменишит количеству
	Product operator--();//Префиксный
	bool operator==(const Product& pr);
	bool operator==(const string& s);//Сравнение с именами строки
	friend ostream& operator<<(ostream& out, const Product& pr);
	friend istream& operator>>(istream& inp, Product& pr);
	void readData();
};