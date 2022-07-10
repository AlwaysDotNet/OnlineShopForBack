#include "Client.h"

Client::Client()
{
	this->skidka = 0;//По умолчание не какого не имеет скидку
}

Client::Client(string nm, string snm, string mnm, int sk)
{
	this->name = nm;
	this->surname = snm;
	this->middlename = mnm;
	this->skidka = sk;
}

Client::Client(const Client& cp)
{
	this->name = cp.getName();
	this->surname = cp.getSurname();
	this->middlename = cp.getMiddleName();
	this->skidka = cp.getSkidka();
}

Client Client::operator=(const Client& cl)
{
	this->name = cl.getName();
	this->surname = cl.getSurname();
	this->middlename = cl.getMiddleName();
	this->skidka = cl.getSkidka();
	return (*this);
}

string Client::getName() const
{
	return this->name;
}

string Client::getSurname() const
{
	return this->surname;
}

string Client::getMiddleName() const
{
	return this->middlename;
}

int Client::getSkidka() const
{
	return skidka;
}

void Client::setFIO(string nm, string snm, string mnm)
{
	this->name = nm;
	this->surname = snm;
	this->middlename = mnm;
}

void Client::setSkidka(int percent)
{
	this->skidka = percent;
}

bool Client::operator==(const Client& cl)
{
	return ((this->getName()==cl.getName())&&(this->getSurname()==cl.getSurname())&&this->getMiddleName()==cl.getMiddleName());
}

void Client::readData()
{
	cout << "Client name: ";
	cin >> name;
	cout << "Client surname: ";
	cin >> surname;
	cout << "Client middlename:";
	cin >> middlename;
}

ostream& operator<<(ostream& out, const Client& cl)
{
	//Выводим аккуратно
	cout << "|" << setw(15) << cl.getSurname() << "|" << setw(15) << cl.getName() << "|" << setw(15) << cl.getMiddleName();
	cout << "|"<<setw(15) << cl.getSkidka() << "|";
	return out;
}

istream& operator>>(istream& inp, Client& cl)
{
	string line;//Прочтение с файла или потока
	if (getline(inp, line))
	{
		int sz=0;
		string* spl = Functions::split(line, ';', sz);
		cl.setFIO(spl[0],spl[1],spl[2]);
		cl.setSkidka(Functions::StrToInt(spl[3]));
		delete[]spl;
	}
	return inp;
}
