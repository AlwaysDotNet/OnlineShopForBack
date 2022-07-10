#pragma once
//Описим некоторое функционал который нам нужно 
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;
class Functions
{
public:
	static string IntToStr(int num);
	static string* split(string& str, char delim,int&size);//Разделит строку на части по некоторму символу 
	static int StrToInt(string num);
};

