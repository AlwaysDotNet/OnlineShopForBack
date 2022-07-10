#include "Profaja.h"

Prodaja::Prodaja()
{
    this->summ = 1.0;
}

Prodaja::Prodaja(string nm, double sm, string clNm, string clSnm, string clM)
{
    this->name = nm;//Название товара
    this->summ = sm;
    this->clName = clNm;
    this->clSurName = clSnm;
    this->clMiddleName = clM;
    this->createDate = Date::curDate();
}

Prodaja::Prodaja(const Prodaja& p)
{
    this->name = p.getPrName();
    this->clName = p.getClName();
    this->clSurName = p.getClSurName();
    this->clMiddleName = p.getClMiddleName();
    this->summ = p.getSumma();
    this->createDate = Date::curDate();//Только время продажи не можем копироват 
}

string Prodaja::getPrName() const
{
    return this->name;
}

string Prodaja::getClName() const
{
    return this->clName;
}

string Prodaja::getClSurName() const
{
    return this->clSurName;
}

string Prodaja::getClMiddleName() const
{
    return this->clMiddleName;
}

double Prodaja::getSumma()const
{
    return summ;
}

Date Prodaja::getDate() const
{
    return createDate;
}
//Что бы записивать в файл 
void Prodaja::WriteToFile(ofstream& of)
{
    of << name << ";" << summ << ";" << clName << ";" << clSurName << ";" << clMiddleName << ";" << createDate << ";\n";
}

ostream& operator<<(ostream& out, const Prodaja& pr)
{
    cout << "|" << setw(20) << pr.getPrName() << "|" << setw(15) << fixed << setprecision(2) << pr.getSumma();
    cout << "|" << setw(15) << pr.getClName() << "|" << setw(15) << pr.getClSurName() << "|" << setw(15) << pr.getClMiddleName() << "|";
    cout << setw(12) << pr.getDate() << "|";
    return out;
}
