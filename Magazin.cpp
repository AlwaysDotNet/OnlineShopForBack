#include "Magazin.h"

bool OnlineMarket::findProductbyName(const string& key)
{
    for (int i = 0; i < sizePr; i++)
        if (prods[i] == key && prods[i].getCnt() > 0)
            return true;
    return false;//Иначе нет в базе
}
//Метод возврашает количество товара -сколько осталось товар
int OnlineMarket::getCountProduct(const string& nameP)
{
    for (int i = 0; i < sizePr; i++)
        if (prods[i] == nameP)
            return prods[i].getCnt();
    return -1;
}

int OnlineMarket::posClient(string n, string s, string m)
{
    Client c(n, s, m);
    for (int i = 0; i < sizeFav; i++)
    {
        if (this->favClient[i] == c)
            return i;
    }
    return -1;
}

OnlineMarket::OnlineMarket(const string& name)
{

    //Так как мы используем динамического массива заранее резервируем памят
    const int MAX_SIZE = 65555;
    this->nameMarket = name;
    this->doxod = 0;//Пока что 0
    this->favClient = new Client[MAX_SIZE];
    this->prods = new Product[MAX_SIZE];
    this->sizeFav = 0;//Еше не добавлено 
    this->sizePr = 0;//еше 0
}

void OnlineMarket::AddProduct()
{
    //Добавление просто
    //Один тип товара может быт добавлено только один раз это нужно учитивать
    Product pr;
    pr.readData();
    for (int i = 0; i < sizePr; i++)
    {
        if (prods[i] == pr)
        {
            cout << "product has been since in Online Market:\n";
            return;
        }
    }
    this->prods[sizePr++] = pr;
    cout << "Product Added succifuly\n";
}

string OnlineMarket::getNameMag() const
{
    return nameMarket;
}

void OnlineMarket::RemoveProduct()
{
    ///Удаленеи производится по имени введем имя товара
    cout << "Please input name of product for deleting: ";
    string str;
    cin >> str;
    //Сначало найдем индекс по массив
    int pos = -1;
    for (int i = 0; i < sizePr; i++)
    {
        if (this->prods[i] == str)
            pos = -1;
    }
    //Теперь удаляем это элемент
    if (pos == -1)
    {
        cout << "We didn\'t find this product\n";
        return;//Если не был найдено
    }
    for (int i = pos; i < sizePr-1; i++)
    {
        prods[i] = prods[i + 1];
    }
    cout << "Deleted succesfuly\n";
    sizePr--;//Не зубдем уменшит количество товара магазина
}

void OnlineMarket::sellProduct()
{
    this->printProduct();
    cout << "\n\n";
    cout << "Please choose the product and write name for selling:";//нужно ввести название товара что бы продать
    string name;
    //С начало проверим есть ли такой товар или осталос ли на склад количество 
    cin >> name;
    cout << "How many(much) do you buy: ";
    int cn;
    cin >> cn;
    int pos = -1;
    //Найдем товар 
    for (int i = 0; i < sizePr; i++)
    {
        if (prods[i] == name)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        cout << "Sorry we didn\'t find thats product:\n";//Товар не найдено
        return;
    }

    //Хватит или нет количество
    if (prods[pos].getCnt() >= cn)
    {
        cout << "Please your name: ";
        string nm,snm,mnm;
        cin >> nm;
        cout << "Please your surname: ";
        cin >> snm;
        cout << "Please your middlename:";
        cin >> mnm;
        //Находим это наш постоянный клиент или нет что бы сделать скидку
        double comSum = prods[pos].getMarks() * cn;//Это обшая цена
        int pcl = posClient(nm, snm, mnm);
        double skid = 0;//Пока что скида нет
        if (pcl!=-1)
        {
            //Если клиент наш постояный
            skid = comSum * favClient[pcl].getSkidka();
            skid /= 100.0;
        }
        comSum -= skid;//Вычтим 
        //Тепер это записиваем  в файл продаж
        ofstream out("prodaja.csv", ios::app);//Добавим
        Prodaja pr(name, comSum, nm, snm, mnm);
        pr.WriteToFile(out);
        out.close();
        //Теперь вычислим чистый доход
        comSum -= (prods[pos].getCost() * cn);//От цена вычтим стоимость само товара
        doxod += comSum;//Добавим в доход
        cout << "Sellt succesfuly\n";
    }
    else
    {
        cout << "Sorry we haven\'t much(many) products\n";//Если не хватает товара
    }
}

void OnlineMarket::printProduct()
{
    //Вывод товаров
    cout <<"|"<<"  ID  " << "|" << std::setw(20) << "NAME" << "|" << setw(12) << "Measurment" << "|";
    cout << setw(8) << fixed << setprecision(2) <<" Cost " << "|" << setw(8) << " Price " << "|";
    cout << setw(8) << "SHELF" << "|" << setw(10) << "Quantity" << "|\n";
    cout << "|++++++|++++++++++++++++++++|++++++++++++|++++++++|++++++++|++++++++|++++++++++|\n";
    for (int i = 0; i < sizePr; i++)
    {
        cout << "|" << setw(6) << i + 1;
        cout << prods[i] << endl;
    }
    cout << "|++++++|++++++++++++++++++++|++++++++++++|++++++++|++++++++|++++++++|++++++++++|\n";
}

double OnlineMarket::getProfit()
{
    //Даход 
    return doxod;
}

void OnlineMarket::getTaxInto()
{
    //12% налога платим
    doxod -= ((doxod * 12.0) / 100.0);
}

void OnlineMarket::sortProdByMark()
{
    //Сортировка товаров
    Product temp;
    for (int i = 0; i < sizePr-1; i++)
    {
        int key = i + 1;
        temp = prods[key];
        for (int j = i + 1; j > 0; j--)
        {
            if (temp.getMarks() < prods[j - 1].getMarks())
            {
                prods[j] = prods[j - 1];
                key = j - 1;
            }
        }
        prods[key] = temp;
    }
}

void OnlineMarket::sortProdByName()
{
    Product temp;
    for (int i = 0; i < sizePr - 1; i++)
    {
        int key = i + 1;
        temp = prods[key];
        for (int j = i + 1; j > 0; j--)
        {
            if (temp.getName().compare(prods[j - 1].getName())<0)
            {
                prods[j] = prods[j - 1];
                key = j - 1;
            }
        }
        prods[key] = temp;
    }
}

void OnlineMarket::sortProdByCnt()
{
    Product temp;
    for (int i = 0; i < sizePr - 1; i++)
    {
        int key = i + 1;
        temp = prods[key];
        for (int j = i + 1; j > 0; j--)
        {
            if (temp.getCnt() < prods[j - 1].getCnt())
            {
                prods[j] = prods[j - 1];
                key = j - 1;
            }
        }
        prods[key] = temp;
    }
}

void OnlineMarket::printFavouriteClients()
{
    cout <<"|"<<setw(6)<<" ID " << "|" << setw(15) << "ClSurName" << "|" << setw(15) << "ClName" << "|" << setw(15) << "ClMiddleName";
    cout << "|" << setw(15) << " skidka%" << "|\n";
    cout << "|++++++|+++++++++++++++|+++++++++++++++|+++++++++++++++|+++++++++++++++|\n";
    for (int i = 0; i < sizeFav; i++)
    {
        cout << "|" << setw(6) << i + 1;
        cout << favClient[i] << endl;
    }
    cout << "|++++++|+++++++++++++++|+++++++++++++++|+++++++++++++++|+++++++++++++++|\n";
}

void OnlineMarket::printProdaj()
{
    ifstream inp("prodaja.csv");
    string line;
    cout << "|" << setw(20) << "NamePR" << "|" << setw(15) << "CommonSumm";
    cout << "|" << setw(15) << "ClientName" << "|" << setw(15) << "ClienSur." << "|" << setw(15) << "ClientMiddle" << "|";
    cout << setw(12) << " Date " << "|\n";
    cout << "|++++++++++++++++++++|+++++++++++++++|+++++++++++++++|+++++++++++++++|+++++++++++++++|+++++++++++++|\n";
    while (getline(inp, line))
    {
        int sz;
        //Вывадим данные
        string* spl = Functions::split(line, ';', sz);
        cout << "|" << setw(20) << spl[0] << "|" << setw(15)<< spl[1];
        cout << "|" << setw(15) << spl[2] << "|" << setw(15) << spl[3] << "|" << setw(15) << spl[4] << "|";
        cout << setw(12) << spl[5] << "|\n";
        delete[]spl;
    }
    cout << "|++++++++++++++++++++|+++++++++++++++|+++++++++++++++|+++++++++++++++|+++++++++++++++|+++++++++++++|\n";
    inp.close();
}

OnlineMarket::~OnlineMarket()
{
    //Освобождаем все
    delete[] this->favClient;
    delete[]this->prods;
}

void OnlineMarket::AddFavClient()
{
    Client cl;
    cl.readData();
    int ps = posClient(cl.getName(), cl.getSurname(), cl.getMiddleName());
    if (ps != -1)
    {
        cout << "Thats client has been already\n";//Уже есть в базе
    }
    else
    {
        this->favClient[sizeFav++] = cl;
        cout << "Succesfully aded your favourite client!!1\n";
    }
}

void OnlineMarket::RemoveFavClient()
{
    printFavouriteClients();
    cout << "Please choose and write data for remove client :\n";
    string nm, snm, mnm;
    cout << "Name:";
    cin >> nm;
    cout << "Surname: ";
    cin >> snm;
    cout << "MiddleName: ";
    cin >> mnm;
    int pos = posClient(nm, snm, mnm);
    if (pos == -1)
    {
        cout << "We didn\'t find that client\n";
    }
    else
    {
        //Просто сдвиним что бы удалит
        for (int i = pos; i < sizeFav - 1; i++)
            this->favClient[i] = this->favClient[i + 1];
        sizeFav--;//Уменшим количество
        cout << "Deleted this client \n";
    }

}
