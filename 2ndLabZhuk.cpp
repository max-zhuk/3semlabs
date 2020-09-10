
#include <iostream>
#include <stack>
#include <string>

class Wear
{   
private:
    
    int m_id;
    std::string m_wearname;
	double  m_cost;
public:
    friend class Tovarov;
	Wear() {  };
    Wear (int id,std::string name)
    {
        
		m_id = id;
		m_wearname = name;
		m_cost = 0;
    }
    void show()
    {
		std::cout << std::endl;
		std::cout << "Wear data:  " <<std::endl;
		std::cout <<"id:  "<<m_id<<std::endl;
		std::cout << "name:  " << m_wearname << std::endl;
		std::cout << "cost:  " << m_cost << std::endl;
			        
    }
	~Wear() {};
};
class Tovarov
{
private:
	int m_tovarovid;
	std::string m_tovarovname;
	std::string m_tovarovfam;
public:
	Tovarov();
	Tovarov(int id, std::string name, std::string fam)
	{
		m_tovarovid = id;
		m_tovarovname = name;
		m_tovarovfam = fam;
	}
	void showTov()
	{
		std::cout << std::endl;
		std::cout << "Tovarov data:  " << std::endl;
		std::cout <<"id: "<< m_tovarovid << std::endl;
		std::cout <<"name: "<< m_tovarovname << std::endl;
		std::cout <<"fam: "<< m_tovarovfam << std::endl;

	}
    void setCost(Wear &name,double cost)
    {	
		name.m_cost = cost;
	
    }

	~Tovarov() {};
};
int main()
{	
	bool fid = true;
	bool fname = true;
	bool ffam = true;
	bool fcost= true;
	
	setlocale(LC_ALL, "rus");
	int id;
	std::string name,fam;
	double cost;
	std::cout << "Wear info: ";
	
	do
	{
		std::cout << "id: ";
		std::cin >> id;
		if (std::cin.fail())
			std::cout << "error" << std::endl;
		else
			fid = false;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
	} while (fid);

	do
	{
			std::cout << "name: ";
			std::cin >> name;
		if (std::cin.fail())
			std::cout << "error" << std::endl;
		else
			fname = false;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
	} while (fname);

	Wear w1(id, name);
	w1.show();
	std::cout << "Tovarov info: ";
	do
	{
		std::cout << "id: ";
		std::cin >> id;
		if (std::cin.fail())
			std::cout << "error" << std::endl;
		else
			fid = false;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
	} while (fid);
	do
	{
		std::cout << "name: ";
		std::cin >> name;
		if (std::cin.fail())
			std::cout << "error" << std::endl;
		else
			fname = false;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
	} while (fname);
	do
	{
		std::cout << "fam: ";
		std::cin >> fam;
		if (std::cin.fail())
			std::cout << "error" << std::endl;
		else
			ffam = false;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
	} while (ffam);
	Tovarov t1(id, name, fam);
	t1.showTov();
	std::cout << "Set cost:  ";
	std::cin >> cost;
	t1.setCost(w1, cost);
	w1.show();
	Wear mas[3] =
		{
			Wear(14,"blouse"),
				Wear(18,"hat"),
				Wear(77,"dress"),
		};
	Tovarov ms[3] =
	{
		Tovarov(50,"Тима","Белорусских"),
		Tovarov(51,"Михаил","Круг"),
		Tovarov(52,"Игорь","Лосик")
	};
	
	for (int i = 0; i < 3; i++)
	{
		std::cout << std::endl;
		ms[i].showTov();
		ms[i].setCost(mas[i], rand() % 20);

	}
	for (int i = 0; i < 3; i++)
	{
		mas[i].show();
	}
    return 0;
}
//--------------------------------------------------------------
//#include <iostream>
//#include <cstdlib>
//#include <string>
//using namespace std;
//
//class Cars
//{
//private:
//	string m_name;
//	string m_fam;
//	string m_ot;
//	int m_id;
//	int m_mileage;
//
//public:
//	Cars() {};
//	Cars(string name, int id, string fam, string ot)
//	{
//		m_id = id;
//		m_name = name;
//		m_mileage = 0;
//		m_fam = fam;
//		m_ot = ot;
//	}
//	~Cars() {};
//	friend void print(Cars& cars);
//	friend class STO;
//};
//void print(Cars& cars)
//{
//	cout << "Id: \t" << cars.m_id << endl;
//	cout << "Name: \t" << cars.m_name << endl;
//	cout << "Fam: \t" << cars.m_fam << endl;
//	cout << "Ot: \t" << cars.m_ot << endl;
//	cout << "Mileage: \t" << cars.m_mileage << endl;
//}
//
//class STO
//{
//private:
//	int m_mileage1;
//public:
//	STO() {};
//	STO(int mileage1) :m_mileage1(mileage1)
//	{
//
//	}
//	~STO()
//	{
//
//	}
//	void setMileage(Cars& cars)
//	{
//		cars.m_mileage = m_mileage1;
//	}
//};
//int main()
//{
//	system("color 5F");
//	bool fid = true;
//	bool fname = true;
//	bool ffam = true;
//	bool fot = true;
//	bool fmileage = true;
//	int id, mileage;
//	string name, fam, ot;
//	do
//	{
//		cout << "Vvod id: ";
//		cin >> id;
//		if (cin.fail())
//			cout << "error" << endl;
//		else
//			fid = false;
//		cin.clear();
//		cin.ignore(cin.rdbuf()->in_avail());
//	} while (fid);
//	do
//	{
//		cout << "Vvod name: ";
//		cin >> name;
//		if (cin.fail())
//			cout << "error" << endl;
//		else
//			fname = false;
//		cin.clear();
//		cin.ignore(cin.rdbuf()->in_avail());
//	} while (fname);
//	do
//	{
//		cout << "Vvod fam: ";
//		cin >> fam;
//		if (cin.fail())
//			cout << "error" << endl;
//		else
//			ffam = false;
//		cin.clear();
//		cin.ignore(cin.rdbuf()->in_avail());
//	} while (ffam);
//	do
//	{
//		cout << "Vvod ot: ";
//		cin >> ot;
//		if (cin.fail())
//			cout << "error" << endl;
//		else
//			fot = false;
//		cin.clear();
//		cin.ignore(cin.rdbuf()->in_avail());
//	} while (fot);
//	Cars cars(name, id, fam, ot);
//	print(cars);
//	do
//	{
//		cout << "Vvod mileage: ";
//		cin >> mileage;
//		if (cin.fail())
//			cout << "error" << endl;
//		else
//			fmileage = false;
//		cin.clear();
//		cin.ignore(cin.rdbuf()->in_avail());
//	} while (fmileage);
//	STO sto(mileage);
//	sto.setMileage(cars);
//	print(cars);
//	Cars mas[3] =
//	{
//		Cars("Petr",14,"Ivanov","Semenovich"),
//		Cars("Anton",856,"Petrov","Ivanovich"),
//		Cars("Andrey",777,"Semenov","Petrovich"),
//	};
//	for (int i = 0; i < 3; i++)
//	{
//		print(mas[i]);
//	}
//	STO ms[3] =
//	{
//		STO(120000),
//		STO(300000),
//		STO(10000),
//	};
//	for (int i = 0; i < 3; i++)
//	{
//		ms[i].setMileage(mas[i]);
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		print(mas[i]);
//	}
//	return 0;
//}