#pragma once
#include<iostream>
#include<iostream>
#include<fstream>
#include<string>
#include <list>
using namespace std;

class Exception
{
protected:
    int error;
public:
    Exception()
    {
        error = 0;
    }
    Exception(int m_error)
    {
        error = m_error;
    }
    ~Exception()
    {

    };
    void view()
    {
        if (this->error == 0)
        {
            cout << "Enter int!" << endl;
        }
        if (this->error == 1)
        {
            cout << "Can't open the file!" << endl;
        }
    }
};


class Employee
{
private:
    int m_num;

    string m_dolz;
public:
    string m_fio;
    Employee() : m_fio("employee"), m_num(0), m_dolz("dolzhnost") {}
    Employee(string fio, int num, string dolz) : m_fio(fio), m_num(num), m_dolz(dolz) {}
    void setFio(string fio)
    {
        m_fio = fio;
    }
    void setNum(int num)
    {
        m_num = num;
    }
    void setDolz(string dolz)
    {
        m_dolz = dolz;
    }
    string getFio()
    {
        return m_fio;
    }
    int getNum()
    {
        return m_num;
    }
    string getDolz()
    {
        return m_dolz;
    }

    friend ostream& operator<<(ostream& out, const Employee t)
    {
        out << "\nfio = " << t.m_fio << "\nNum = " << t.m_num << "\nDolz =" << t.m_dolz << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Employee& t)
    {
        in >> t.m_fio;
        in >> t.m_num;
        in >> t.m_dolz;
        return in;
    }

    friend bool operator==(Employee em, Employee ep) {
        if (em.m_num == ep.m_num && em.m_dolz == ep.m_dolz && em.m_fio == ep.m_fio)
            return true;
        else
            return false;
    }

    friend bool operator<(const Employee em, const Employee ep)
    {
        if (em.m_num < ep.m_num)
            return true;
        else
            return false;
    }

    friend bool operator>(const Employee em, const Employee ep)
    {
        if (em.m_num > ep.m_num)
            return true;
        else
            return false;
    }
};

using namespace std;

enum Key {
    nokey = 0,
    txt,
    bin
};

class File
{
private:
    fstream file;
    string name;
    Key key;
    int size;
public:
    File() : name(""), key(nokey), size(0) {}
    File(string n, Key k) : name(n), key(k), size(0) {}
    friend File& operator<<(File& file, const char* s)
    {
        try {
            if (!file.file.is_open())
            {
                throw 1;
            }
        }
        catch (int i)
        {
            Exception ex(i);
            ex.view();
        }

        string str = s;
        file.file << str;
        return file;
    }
    friend fstream& operator<<(fstream& out, Employee& t) {

        try {
            if (!out.is_open())
            {
                throw 1;
            }
        }
        catch (int i)
        {
            Exception ex(i);
            ex.view();
        }

        int a = out.tellg();
        string m_fio = t.getFio();

        size_t len1 = m_fio.length() + 1;

        int m_num = t.getNum();

        string m_dolz = t.getDolz();

        size_t len2 = m_dolz.length() + 1;

        out.write((char*)(&len1), sizeof(len1));

        out.write((char*)(m_fio.c_str()), len1);

        out.write((char*)(&m_num), sizeof(m_num));

        out.write((char*)(&len2), sizeof(len2));

        out.write((char*)(m_dolz.c_str()), len2);


        return out;
    }
    friend File& operator<<(File& file, Employee& t)
    {
        int pos = 0, a = 0, size = 0;

        if (!file.file.is_open())
        {
            cout << "1";
        }

        if (file.key == txt) {
            file.file << t.getFio() << " " << t.getNum() << " " << t.getDolz() << endl;
        }
        else if (file.key == bin) {
            string m_fio = t.getFio();

            size_t len1 = m_fio.length() + 1;

            int m_num = t.getNum();

            string m_dolz = t.getDolz();

            size_t len2 = m_dolz.length() + 1;

            file.file.write((char*)(&len1), sizeof(len1));

            file.file.write((char*)(m_fio.c_str()), len1);

            file.file.write((char*)(&m_num), sizeof(m_num));

            file.file.write((char*)(&len2), sizeof(len2));

            file.file.write((char*)(m_dolz.c_str()), len2);
        }
        return file;
    }
    friend ostream& operator<<(ostream& out, File& file)
    {
        int a = 0;

        if (!file.file.is_open())
        {
            throw 1;
        }

        if (file.key == txt) {
            string str;
            while (!file.file.eof()) {
                getline(file.file, str);
                a = file.file.tellg();
                cout << str << endl;
            }
        }
        else if (file.key == bin) {
            int i = 0;
            int size = 0, step = 0;
            while (i < file.size) {
                int m_num = 0;

                size_t len = 0;

                file.file.read((char*)(&len), sizeof(len));
                char* f = new char[len];

                file.file.read((char*)(f), len);

                f[len - 1] = '\0';

                file.file.read((char*)(&m_num), sizeof(int));

                file.file.read((char*)(&len), sizeof(len));
                char* s = new char[len];

                file.file.read((char*)(s), len);
                s[len - 1] = '\0';

                cout << f << " " << m_num << " " << s << " " << endl;

                delete[] f;

                delete[] s;
                i++;

            }
        }
        return out;
    }

    ~File() {
        file.close();
    }
    void open(string mode)
    {
        switch (key)
        {
        case txt: {
            if (mode == "r") {
                file.open(name, ios_base::in);
            }
            else if (mode == "add") {
                file.open(name, ios_base::app);
            }
            else if (mode == "w") {
                file.open(name, ios_base::out);
            }
            else if (mode == "wr") {
                file.open(name, ios_base::in | ios_base::out);
            }
            break;
        }
        case bin: {
            if (mode == "r") {
                file.open(name, ios_base::binary | ios_base::in);
            }
            else if (mode == "add") {
                file.open(name, ios_base::binary | ios_base::app);
            }
            else if (mode == "w") {
                file.open(name, ios_base::binary | ios_base::out);
            }
            else if (mode == "wr") {
                file.open(name, ios_base::binary | ios_base::in | ios_base::out);
            }
            break;
        }

        }
        if (!file.is_open())
        {
            throw;
        }

    }
    void close()
    {
        file.close();
    }
    void begin()
    {
        file.seekg(0, ios_base::beg);
    }
    void setSize(int s) {
        size = s;
    }
    int getSize() {
        return	size;
    }
    Employee read()
    {
        string str;
        Employee empl;

        getline(this->file, str, ' ');
        empl.setFio(str);

        getline(this->file, str, ' ');
        empl.setNum(stoi(str));

        getline(this->file, str);
        empl.setDolz(str);

        return empl;
    }

    void editEmployee(int line, Employee ms[], string change) {
        this->open("wr");

        int a, b;

        try {
            if (!file.is_open())
            {
                throw 1;
            }
        }
        catch (int i)
        {
            Exception ex(i);
            ex.view();
            return;
        }
        Employee temp;
        if (this->key == txt) {
            string str;
            for (int i = 0; i < line - 1; i++)
                getline(this->file, str);

            getline(this->file, str, ' ');
            temp.setFio(str);

            getline(this->file, str, ' ');
            temp.setNum(stoi(str));

            getline(this->file, str, ' ');
            temp.setDolz(str);
        }
        else if (this->key == bin) {
            size_t len = 0;
            for (int i = 0; i < line; i++) {
                this->file.read((char*)(&len), sizeof(len));
                char* n = new char[len];
                string m_fio;
                string m_dolz;
                int m_num = 0;

                this->file.read((char*)(n), len);
                m_fio = n;
                m_fio[len - 1] = '\0';
                this->file.read((char*)(&m_num), sizeof(int));

                this->file.read((char*)(&len), sizeof(len));
                this->file.read((char*)(n), len);
                m_dolz = n;
                m_dolz[len - 1] = '\0';

                temp.setFio(m_fio);
                temp.setNum(m_num);
                temp.setDolz(m_dolz);
                delete[]n;
            }
            a = file.tellg();
        }

        cout << change << ": changed!" << endl;

        string fstr = change;

        rewind(stdin);
        temp.setFio(fstr);

        int yn = 9;
        temp.setNum(yn);
        rewind(stdin);

        string pn = "  bloger";
        rewind(stdin);

        temp.setDolz(pn);

        a = file.tellg();
        file.seekg(0, ios_base::end);
        b = file.tellg();
        this->file.seekg(0, ios_base::beg);
        if (this->key == txt) {
            string tmp;
            for (int i = 0; i < line - 1; i++)
                getline(this->file, tmp);
            int pos = this->file.tellg();
            this->file.seekg(pos, ios_base::beg);
            this->file << tmp;
            return;
        }
        else if (this->key == bin) {
            for (int i = 0; i < line - 1; i++)
            {
                size_t len = 0;
                this->file.read((char*)(&len), sizeof(len));
                char* n = new char[len];

                string m_fio;
                string m_dolz;
                int m_num = 0;

                this->file.read((char*)(n), len);

                m_fio = n;

                m_fio[len - 1] = '\0';

                this->file.read((char*)(&m_num), sizeof(int));

                this->file.read((char*)(&len), sizeof(len));

                this->file.read((char*)(n), len);
                delete[] n;
            }
            int pos = this->file.tellg();

            char* last = new char[b - a];
            this->file.read((char*)last, static_cast<std::streamsize>(b) - a);

            this->close();
            this->open("w");
            pos = this->file.tellg();

            for (int i = 0; i < getSize(); i++) {
                if (i != line - 1)
                    file << ms[i];
                else {
                    file << temp;
                    ms[i].setFio(temp.getFio());
                    ms[i].setNum(temp.getNum());
                    ms[i].setDolz(temp.getDolz());
                }
            }
        }

        this->close();
    }

    void deleteEmployee(int line, Employee mas[]) {
        this->open("wr");

        int a, b;

        try {
            if (!file.is_open())
            {
                throw 1;
            }
        }
        catch (int i)
        {
            Exception ex(i);
            ex.view();
            return;
        }
        Employee temp;
        if (this->key == txt) {
            string str;
            for (int i = 0; i < line - 1; i++)
                getline(this->file, str);

            getline(this->file, str, ' ');
            temp.setFio(str);

            getline(this->file, str, ' ');
            temp.setNum(stoi(str));

            getline(this->file, str, ' ');
            temp.setDolz(str);
        }
        else if (this->key == bin) {
            size_t len = 0;
            for (int i = 0; i < line; i++) {
                this->file.read((char*)(&len), sizeof(len));
                char* n = new char[len];
                string m_fio;
                string m_dolz;
                int m_num = 0;

                this->file.read((char*)(n), len);
                m_fio = n;
                m_fio[len - 1] = '\0';
                this->file.read((char*)(&m_num), sizeof(int));

                this->file.read((char*)(&len), sizeof(len));
                this->file.read((char*)(n), len);
                m_dolz = n;
                m_dolz[len - 1] = '\0';

                temp.setFio(m_fio);
                temp.setNum(m_num);
                temp.setDolz(m_dolz);
                delete[]n;
            }
            a = file.tellg();
        }

        string fi = "";
        rewind(stdin);
        temp.setFio(fi);

        int yn = NULL;
        temp.setNum(yn);
        rewind(stdin);

        string pn = "";
        rewind(stdin);

        temp.setDolz(pn);

        a = file.tellg();
        file.seekg(0, ios_base::end);
        b = file.tellg();
        this->file.seekg(0, ios_base::beg);
        if (this->key == txt) {
            string tmp;
            for (int i = 0; i < line - 1; i++)
                getline(this->file, tmp);
            int pos = this->file.tellg();
            this->file.seekg(pos, ios_base::beg);
            this->file << tmp;
            return;
        }
        else if (this->key == bin) {
            for (int i = 0; i < line - 1; i++)
            {
                size_t len = 0;

                this->file.read((char*)(&len), sizeof(len));

                char* n = new char[len];

                string m_fio;
                string m_dolz;
                int m_num = 0;

                this->file.read((char*)(n), len);
                m_fio = n;

                m_fio[len - 1] = '\0';

                this->file.read((char*)(&m_num), sizeof(int));

                this->file.read((char*)(&len), sizeof(len));

                this->file.read((char*)(n), len);

                delete[] n;
            }
            int position = this->file.tellg();

            char* last = new char[b - a];
            this->file.read((char*)last, static_cast<std::streamsize>(b) - a);

            this->close();
            this->open("w");
            position = this->file.tellg();

            for (int i = 0; i < getSize(); i++) {
                if (i != line - 1)
                    file << mas[i];
            }
        }

        this->close();
    }

    void sortFio()
    {
        string temp;
        string str1, str2;
        int position;
        this->open("wr");
        try {
            if (!file.is_open())
            {
                throw 1;
            }
        }
        catch (int i)
        {
            Exception ex(i);
            ex.view();
            return;
        }
        for (int i = 0; i < this->size - 1; i++) {
            for (int j = 0; j < this->size - i - 1; j++)
            {
                this->file.seekg(0, ios_base::beg);
                for (int k = 0; k < j; k++)
                    getline(this->file, str1);

                getline(this->file, str1, ' ');

                getline(this->file, str2);

                getline(this->file, str2, ' ');

                if (str1 > str2)
                {
                    this->file.seekg(0, ios_base::beg);
                    position = this->file.tellg();
                    for (int k = 0; k <= j; k++)
                    {
                        getline(this->file, str1);
                        position = this->file.tellg();
                    }
                    temp = str1;
                    getline(this->file, str2);
                    this->file.seekg(0, ios_base::beg);
                    for (int k = 0; k < j; k++)
                    {
                        getline(this->file, str1);
                    }
                    position = this->file.tellg();
                    this->file.seekg(position, ios_base::beg);
                    this->file << str2 << '\n';
                    this->file << temp << '\n';
                }
            }
        }
        this->close();
    }

    void sortNumToHigh() {
        string temp;
        string str1, str2;
        int i1, i2;
        int position;
        this->open("wr");
        try {
            if (!file.is_open())
            {
                throw 1;
            }
        }
        catch (int i)
        {
            Exception ex(i);
            ex.view();
            return;
        }
        for (int i = 0; i < this->size - 1; i++) {
            for (int j = 0; j < this->size - i - 1; j++)
            {
                this->file.seekg(0, ios_base::beg);
                for (int k = 0; k < j; k++)
                    getline(this->file, str1);
                for (int t = 0; t < 2; t++)
                    getline(this->file, str1, ' ');
                getline(this->file, str2);
                for (int t = 0; t < 2; t++)
                    getline(this->file, str2, ' ');
                i1 = stoi(str1);
                i2 = stoi(str2);
                if (i1 > i2)
                {
                    this->file.seekg(0, ios_base::beg);
                    position = this->file.tellg();
                    for (int k = 0; k <= j; k++) {
                        getline(this->file, str1);
                        position = this->file.tellg();
                    }
                    temp = str1;
                    getline(this->file, str2);
                    this->file.seekg(0, ios_base::beg);
                    for (int k = 0; k < j; k++) {
                        getline(this->file, str1);
                    }
                    position = this->file.tellg();
                    this->file.seekg(position, ios_base::beg);
                    this->file << str2 << '\n';
                    this->file << temp << '\n';
                }
            }
        }
        this->close();
    }
    void sortNumToLow() {
        string temp;
        string str1, str2;
        int i1, i2;
        int position;
        this->open("wr");
        try {
            if (!file.is_open())
            {
                throw 1;
            }
        }
        catch (int i)
        {
            Exception ex(i);
            ex.view();
            return;
        }
        for (int i = 0; i < this->size - 1; i++) {
            for (int j = 0; j < this->size - i - 1; j++)
            {
                this->file.seekg(0, ios_base::beg);
                for (int k = 0; k < j; k++)
                    getline(this->file, str1);
                for (int t = 0; t < 2; t++)
                    getline(this->file, str1, ' ');
                getline(this->file, str2);
                for (int t = 0; t < 2; t++)
                    getline(this->file, str2, ' ');
                i1 = stoi(str1);
                i2 = stoi(str2);
                if (i1 < i2)
                {
                    this->file.seekg(0, ios_base::beg);
                    position = this->file.tellg();
                    for (int k = 0; k <= j; k++) {
                        getline(this->file, str1);
                        position = this->file.tellg();
                    }
                    temp = str1;
                    getline(this->file, str2);
                    this->file.seekg(0, ios_base::beg);
                    for (int k = 0; k < j; k++) {
                        getline(this->file, str1);
                    }
                    position = this->file.tellg();
                    this->file.seekg(position, ios_base::beg);
                    this->file << str2 << '\n';
                    this->file << temp << '\n';
                }
            }
        }
        this->close();
    }
    void sortDolz()
    {
        string temp;
        string str1, str2;
        int i1, i2;
        int position;
        this->open("wr");
        try {
            if (!file.is_open())
            {
                throw 1;
            }
        }
        catch (int i)
        {
            Exception ex(i);
            ex.view();
            return;
        }
        for (int i = 0; i < this->size - 1; i++) {
            for (int j = 0; j < this->size - i - 1; j++) {
                this->file.seekg(0, ios_base::beg);
                for (int k = 0; k < j; k++) {
                    getline(this->file, str1);
                }
                for (int t = 0; t < 4; t++)
                    getline(this->file, str1, ' ');
                getline(this->file, str1);
                for (int t = 0; t < 4; t++)
                    getline(this->file, str2, ' ');
                getline(this->file, str2);

                if (str1 > str2) {
                    this->file.seekg(0, ios_base::beg);
                    position = this->file.tellg();
                    for (int k = 0; k <= j; k++) {
                        getline(this->file, str1);
                        position = this->file.tellg();
                    }
                    temp = str1;
                    getline(this->file, str2);
                    this->file.seekg(0, ios_base::beg);
                    for (int k = 0; k < j; k++) {
                        getline(this->file, str1);
                    }
                    position = this->file.tellg();
                    this->file.seekg(position, ios_base::beg);
                    this->file << str2 << '\n';
                    this->file << temp << '\n';
                }
            }
        }
        this->close();
    }
};

using namespace std;
