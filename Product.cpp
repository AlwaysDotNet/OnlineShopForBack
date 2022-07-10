#include "Product.h"

Product::TypeWeight Product::setType(int ch)
{
    switch (ch)
    {
    case 1:
        return Product::TypeWeight::CNT;//Количество
    case 2:
        return Product::TypeWeight::PACKGE;//Упаковка
    case 3:
        return Product::TypeWeight::WEIGHT;
    default:return Product::TypeWeight::CNT;
        break;
    }
}

Product::TypeWeight Product::getType() const
{
    return this->tp;
}

Product::TypeWeight Product::StrToTypeW(string tp)
{
    if (tp == "cnt.")
        return Product::TypeWeight::CNT;
    else if (tp == "pack.")
        return Product::TypeWeight::PACKGE;
    else if (tp == "kg")
        return Product::TypeWeight::WEIGHT;
    else
        return Product::TypeWeight::CNT;
}



Product::Product()
{
    //По умолчание
    this->cnt = 1;
    this->cost = 1.0;
    this->name = "Apple";
    this->tp = Product::TypeWeight::CNT;
    this->srok = 0;
}

Product::Product(string name, double cs, double mark, int cnt, int _tp, int srok)
{
    this->name = name;
    this->cost = cs;
    this->mark = mark;
    this->cnt = cnt;
    this->tp = setType(_tp);
    this->srok = srok;
}

Product::Product(const Product& pr)
{
    this->name = pr.getName();
    this->cost = pr.getCost();
    this->mark = pr.getMarks();
    this->cnt = pr.getCnt();
    this->tp = setType(pr.getType());
    this->srok = srok;
}

string Product::getName() const
{
    return this->name;
}

string Product::getRazdacha() const
{
    switch (getType())
    {
    case Product::TypeWeight::CNT:
        return "cnt.";//Количество
    case Product::TypeWeight::PACKGE:
        return "pack.";
    case Product::TypeWeight::WEIGHT:
        return "kg.";
    default:return "cnt.";
        break;
    }
}

double Product::getCost() const
{
    return this->cost;
}

double Product::getMarks() const
{
    return this->mark;
}

int Product::getSrokMonth() const
{
    return this->srok;
}

int Product::getCnt() const
{
    return cnt;
}

void Product::setName(const string& s)
{
    this->name = s;
}

void Product::setRazdacha(int tp)
{
    this->tp = setType(tp);
}

void Product::setRazdacha(string tp)
{
    this->tp = StrToTypeW(tp);
}

void Product::setCost(double cn)
{
    this->cost = cn;
}

void Product::setMarks(double mr)
{
    this->mark = mr;
}

void Product::setSrok(int sr)
{
    this->srok = sr;
}

void Product::setCount(int cnt)
{
    this->cnt = cnt;
}

Product Product::operator--(int)
{
    if(this->cnt>0)
    this->cnt--;
    return (*this);
}

Product Product::operator--()
{
    if (this -> cnt > 0)
        this->cnt--;
    return (*this);
}
//Будем сравнивать только по название продукта
bool Product::operator==(const Product& pr)
{
    return (this->name==pr.getName());
}

bool Product::operator==(const string& s)
{
 return this->name==s;
}

void Product::readData()
{
    cout << "Name of product :";
    cin >> name;
    cout << "cost of product: ";
    cin >> cost;
    cout << "Marks of product: ";
    cin >> mark;
    cout << "Type of meuserment(\'cnt.\';\'pack.\'; \'kg.\': ";
    string tp;
    cin >> tp;
    setRazdacha(tp);
    cout << "Quntity product:";//Количество
    cin >> cnt;
    cout << "Shelf life in month(if forever then 0):";
    cin >> srok;
}

ostream& operator<<(ostream& out, const Product& pr)
{
    string srk = "";
    if (pr.getSrokMonth() == 0)
        srk += "-";
    else
        srk += Functions::IntToStr(pr.getSrokMonth());
    srk += "month.";
    out << "|" << std::setw(20) << pr.getName() << "|" << setw(12) << pr.getRazdacha() << "|";
    out << setw(8) << fixed << setprecision(2) << pr.getCost() << "|" << setw(8) << pr.getMarks() << "|";
    out << setw(8) << srk << "|" << setw(10) << pr.getCnt() << "|";
    return out;
}

istream& operator>>(istream& inp, Product& pr)
{
    //Ввод
    string line;
    if (getline(inp, line))//Прочитаем строку
    {
        int ns = 0;
        string* spl = Functions::split(line, ';', ns);
        if (ns != 6)
            return inp;
        pr.setName(spl[0]);
        pr.setRazdacha(spl[1]);
        pr.setCost(strtod(spl[2].c_str(), nullptr));
        pr.setMarks(strtod(spl[3].c_str(),nullptr));
        pr.setSrok(Functions::StrToInt(spl[4]));
        pr.setCount(Functions::StrToInt(spl[5]));
    }
    return inp;
}
