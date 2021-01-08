#include "Header.h"

#include <iostream>
using namespace myClass;

std::ostream& operator<< (std::ostream& out, const Wear& point)
{

    out << point.m_id << " " << point.m_name <<" "<<point.m_cost <<std::endl;


    return out;
}

void menu()
{
    std::cout << " Выберите алгоритм: \n  1 - Подсчет слов в строке\n  2 - Проверка\n  3 - Копирование множества элементов\n";
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int x;
    list<string>strlist;
    list<Wear>mylist;
    
    Wear a("Blouse ", 1, 30.31);
    Wear b("Shorts", 2, 20);
    Wear c("Gucci ", 3, 300000);
    Wear d("Dolce Gabana", 4, 32.1);
    Wear e("Sneakers Adidas", 5, 300);
    Wear f("Chineese Abibas", 6, 3);
    
    mylist.push_front(a);
    mylist.push_back(b);
    mylist.push_back(c);
    mylist.push_back(d);
    mylist.push_back(e);
    mylist.push_back(f);

    menu();
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

       std::cout << "Символы для проверки" << endl;
        cin >> symb1;
        cin >> symb2;
       
        ifstream fin;
        ofstream fout;
        fin.open("filein.txt");
      
            try
            {

                if (!fin.is_open())
                {
                    throw ExceptionStack("Can`t open filein.txt\n");
                }
                else 
                {
                    cout << "\nfilein.txt is opened" << endl;
                }
            }
            catch (ExceptionStack exception)
            {
                cerr << exception.getError();
            }
            string buf;

        while (getline(fin, buf))
        {
            
            strlist.push_back(buf);
            cout << buf << '\n';
        }

        cout << line<<endl;
        auto it_s = strlist.begin();
        fout.open("fileout.txt");
        try
        {

            if (!fout.is_open())
            {
                throw ExceptionStack("Can`t open file fileout.txt\n");
            }
            else
            {
                cout << "fileout.txt is opened" << endl;
            }
        }
        catch (ExceptionStack exception)
        {
            cerr << exception.getError();
        }
        
        int counter = 0;
        while (it_s != strlist.end())
        {
            counter++;
            count = 0;
            line = *it_s;
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
            fout << count << "\n";
            cout << "String #" << counter << " result: " << count << endl;
            it_s++;
        }
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

