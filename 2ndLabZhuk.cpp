
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
