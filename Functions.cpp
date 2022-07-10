#include "Functions.h"
#include <algorithm>//Некотое готовые алгоритмы
#include <sstream>//Поток строки
#include <stdlib.h>
string Functions::IntToStr(int num)
{
    string ans = "";
    while (num)
    {
        ans = ans+(char)(num % 10 + '0');
        num /= 10;
    }
    return ans;
}
//разделение строки на части например на слова
string* Functions::split(string& str, char delim, int& size)
{
    size = 0;
    string word;
    string* spl = new string[655];//Динамическый массив
    stringstream s(str);
    while (getline(s, word, delim))
    {
        spl[size++] = word;
    }
    return spl;
}
//
int Functions::StrToInt(string num)
{
    int ans = 0;
    for (int i = 0; i < num.length(); i++)
        ans = ans * 10 + (num[i] - '0');
    return ans;
}
