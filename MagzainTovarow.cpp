
#include <iostream>
#include <iomanip>
#include "Magazin.h"
using namespace std;

int main()
{
	//некоторое ОС не рботает с русскимы символамы поэтому все лучше написать на Латиниц -английском
	OnlineMarket mymark;//Создаем объект магазина
	bool quit = false;
	while (!quit)
	{
		//меню
		cout << "----Welcome to my " << mymark.getNameMag() << "  ------------\n";
		cout << "1 -Add product:\n";//Добавление товара
		cout << "2 -Remove product\n";//Удаление товара
		cout << "3 -Sell product: \n";//Продать товара
		cout << "4 -Get out Tax\n";//Оплатит налог
		cout << "5 -Get Profit\n";//Чистый доход
		cout << "6 -Out All products:\n";//Вывод всех товаров
		cout << "7 -Sort  Products\n";
		cout << "8 -Out Sells History\n";//Вывод история продажа
		cout << "9 -Add new favourite client\n";//Вывод история продажа
		cout << "10 -Remove favourite client\n";//Вывод история продажа
		cout << "11 -Out My Favourite clients list\n";//Вывод история продажа
		cout << "12 -Exit\n";
		int cmd;
		cin >> cmd;
		//Теперь просто введем номер меню и сделаем что хотим
		switch (cmd)
		{
		case 1:
		{
			mymark.AddProduct();
			//add pr
			break;
		}
		case 2:
		{
			mymark.RemoveProduct();
			//remove pr
			break;
		}
		case 3:
		{
			mymark.sellProduct();
			//remove pr
			break;
		}
		case 4:
		{
			mymark.getTaxInto();
			break;
		}
		case 5:
		{
			cout << "Lent proffit : " << mymark.getProfit() << endl;//Чистый прибыл
			break;
		}
		case 6:
		{
			mymark.printProduct();
			break;
		}
		case 7:
		{
			cout << "1 -Sort By Cout:\n";
			cout << "2 -Sort by Name:\n";
			cout << "3 -Sort by Price\n";
			int icm;
			cin >> icm;
			switch (icm)
			{
			case 1:
			{
				mymark.sortProdByCnt();
				break;
			}
			case 2:
			{
				mymark.sortProdByName();
				break;
			}
			case 3:
			{
				mymark.sortProdByMark();
				break;
			}
			default:cout << "Incorrect command\n";
				break;
			}
			break;
		}
		case 8:
		{
			mymark.printProdaj();
			break;//8
		}
		case 9:
		{
			mymark.AddFavClient();
			break;//9
		}
		case 10:
		{
			mymark.RemoveFavClient();
			break;//10
		}
		case 11:
		{
			mymark.printFavouriteClients();
			break;
		}
		case 12:
		{
			cout << "\t\t\t\tByeeeeeee\n";

			quit = true;
			break;
		}
		default:
			break;
		}
	}
	return 0;
}
