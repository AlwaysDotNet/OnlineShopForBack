#pragma once
#include "Functions.h"
#include "Date.h"
//Класс что бы сохранит данные о продаже 
//мы таким образом сможем определит постоянных клиентов если они покупали больше 10000р то они ..
//Мы сохраним только название продукта имя фамилия отчество клиента и сумму
class Prodaja
{
private:
	string name;//Название продукта
	double summ;//Сумма
	string clName;//Имя клиента
	string clSurName;//Фамилия клиента
	string clMiddleName;//Отчество
	Date createDate;//Дата продажи устанвится авто в время продажа
public:
	Prodaja();
	Prodaja(string nm, double sm, string clNm, string clSnm, string clM);
	Prodaja(const Prodaja& p);
	string getPrName()const;//Возврашает название продукта
	string getClName()const;
	string getClSurName()const;
	string getClMiddleName()const;//Возврашаеть  отчество клиента
	double getSumma()const;//Сумма
	Date getDate()const;//дата создание
	friend ostream& operator<<(ostream& out, const Prodaja& pr);
	//Все продажи сохраниться в файлы
	void WriteToFile(ofstream& of);
	
};

