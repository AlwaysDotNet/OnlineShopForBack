#pragma once
#include "Functions.h"
#include "Product.h"
#include "Profaja.h"
#include "Client.h"
//Основной класс который хранит все данные 
//Налог 12  процент от дохода а остальное чистое прибыл
//Магазин хранит клиентов в файлы и если клиент покупал более чем 10000 р то он повится в лист фаворит 
//Все данные храним в виде динамического массива
class OnlineMarket
{
private:
	double doxod;//Доход от продаж
	Client* favClient;//Клиенты  постоянные больше чем 10000 р заупок
	Product* prods;//Товары
	int sizePr;//количество товаров
	int sizeFav;//Количество постоянных клиентов
	string nameMarket;//Название маркета
	bool findProductbyName(const string& key);//Поиск товара по название возврашаеть истину если сушествует иимеется в складе иначе ложь
	int getCountProduct(const string& nameP);//Возврашает количество товара в склад
	int posClient(string n, string s, string m);//Возврашает позиция нашего постоянного клиента
public:
	OnlineMarket(const string& name="*-*-*- VALERI MARKET *-*-*-*-*-");//Конструктор по умолчание что бы инициализироват объектов массивов
	void AddProduct();//Добавлние товара
	string getNameMag()const;
	void RemoveProduct();//Удаление товара
	void sellProduct();//Продажа продукта
	void printProduct();//Вывод всех товаров
	double getProfit();//Чистый  доход
	void getTaxInto();//Оплатит налог
	void sortProdByMark();//Сортировка товаров по цены
	void sortProdByName();//Сортировка товаров по название
	void sortProdByCnt();//Сортировка товаров по количеству
	void printFavouriteClients();//Печать всех постоянных клиентов
	void printProdaj();//Печать всех продажи до сегодншный день
	~OnlineMarket();//Деструкторв
	void AddFavClient();//Добавление постоянных клиентов
	void RemoveFavClient();//Удаление постоянных клиентов

};

