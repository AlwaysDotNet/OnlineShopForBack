#include "Date.h"
Date::Date()
{
    //Установим текушую дату
    time_t cur = time(0);
    tm lc = *(localtime(&cur));
    this->day = lc.tm_mday;
    this->month = lc.tm_mon + 1;
    this->year = lc.tm_year + 1900;
}

Date::Date(int d, int m, int y)
{
    //Установим все данные
    this->day = d;
    this->month = m;
    this->year = y;
}

Date::Date(const Date& d)
{
    this->day = d.getDay();
    this->month = d.getMonth();
    this->year = d.getYear();
}

int Date::getDay() const
{
    
    return day;//Возврашает день
}

int Date::getMonth() const
{
    return month;//Возвраает месяц
}

int Date::getYear() const
{
    return year;
}

Date Date::fromString(std::string& s)
{
    int size = 0;
    string* spl = Functions::split(s, '-', size);//05-05-2000 типа таких слов разделим на части
    if(size!=3)//Если некоретный строка
    return Date(-1,-1,-1);
    int d = Functions::StrToInt(spl[0]);
    int m = Functions::StrToInt(spl[1]);
    int y = Functions::StrToInt(spl[2]);
    delete[]spl;//Освобождение памяти
    return Date(d, m, y);
}

std::string Date::readStream()
{
    string line;
    cout << "Please input local Date(dd-mm-yyyy): ";
    cin >> line;
    Date d = Date::fromString(line);
    while (d.getDay() < 0)
    {
        cout << "Please input local Date(dd-mm-yyyy): ";
        cin >> line;
        Date d = Date::fromString(line);
    }
    return line;
}

Date Date::operator=(const Date& d)
{
    this->day = d.getDay();
    this->month = d.getMonth();
    this->year = d.getYear();
    return (*this);
}

Date Date::curDate()
{

    //Установим текушую дату
    time_t cur = time(0);
    tm lc = *(localtime(&cur));
    int day = lc.tm_mday;
    int month = lc.tm_mon + 1;
    int year = lc.tm_year + 1900;
    return Date(day,month,year);
}

istream& operator>>(istream& inp, Date& d)
{
    string line;
    inp >> line;
    d = Date::fromString(line);
    return inp;
}

ostream& operator<<(ostream& out, const Date& d)
{
    out << d.getDay() / 10 << d.getDay() % 10 << "-" << d.getMonth() / 10 << d.getMonth() % 10 << "-" << d.getYear();//Возврашаем дату
    return out; 
}
