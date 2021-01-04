#include "Header.h"

#include <iostream>
using namespace myClass;
void menu()
{
    std::cout << " Выберите алгоритм: \n  1 - Подсчет слов в строке\n  2 - Проверка\n  3 - Копирование множества элементов\n";
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int x;
    list<Wear>mylist;
    menu();
    Wear a("B1ouse 2 3 red co11lor", 1, 30.31);
    Wear b("Shorts", 2, 20);
    Wear c("Gucci ", 3, 300000);
    Wear d("Do1ce Gabana", 4, 32.1);
    Wear e("Sneakers Adidas", 5, 300);
    Wear f("Chineese Abibas", 6, 3);

    mylist.push_front(a);
    mylist.push_back(b);
    mylist.push_back(c);
    mylist.push_back(d);
    mylist.push_back(e);
    mylist.push_back(f);
   
    try
    {
        cin >> x;
        if (x < 0 || x>3)
            throw ExceptionStack("Invalid x,input correct\n");
    }
    catch (ExceptionStack exception)
    {
        cerr << exception.getError();
    }
    if (x == 1)
    {
        int num,count=0;
        char symb1, symb2;
        string line;

        auto it = mylist.begin();

        std::cout << "Номер элемента в списке для подсчёта слов:" << endl;

        try
        {
            cin >> num;
            if (num < 0 || num > 6)
                throw ExceptionStack("Out of list\n");

        }
        catch (ExceptionStack exception)
        {
            cerr << exception.getError();
        }
       std::cout << "Символы для проверки" << endl;
        cin >> symb1;
        cin >> symb2;
        for (int i = 1; i < num; i++) it++;
        line = it->m_name;
        cout << line<<endl;
      
        auto it_str = line.begin();

        bool flag = false;
        while (it_str != line.end())
        {
             //тру если слово уже учлось

            if (*it_str == ' ') flag = false;
            if (flag == false)
            if (*it_str == symb1 || *it_str == symb2)
            {
                count++;
                flag = true;

            }
            it_str++;
            
        }
        std::cout << count;
    }
    if (x == 2)
    {
        auto it = mylist.begin();

        while (it != mylist.end())
        {
            if (it->m_cost > 30) cout << "У элемента с id: " << it->m_id << " цена больше 30.00 ("<<it->m_cost<<")"<<endl;
            it++;
        }
    }
    if (x == 3)
    {   
       
        ofstream fout;
       
        fout.open("file.txt");

        try
        {

            if (!fout.is_open())
            {
                throw ExceptionStack("Can`t open file\n");
            }
        }
        catch (ExceptionStack exception)
        {
            cerr << exception.getError();
        }

        auto it = mylist.begin();
        while (it != mylist.end())
        {
            if(it->m_id%2==0) fout << it->m_name << '\n';
            it++;
        }
        
    }
}

