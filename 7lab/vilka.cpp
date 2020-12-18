#include "Header.h"
int main() {

	Wear object;
	string userName;
	ListWear  container;
	int number = 117;
	int chk = 1;
	int s = 4;
	while (chk != 2) {
		std::cout << "Enter a name of the wear " << '\n';
		cin >> userName;
		object.nameSetter(userName);
		std::cout << "Enter the id of the wear" << '\n';
		number = getValue_int();
		object.idSetter(number);
		std::cout << "Do you want to continue?"<<endl<<"1-yes"<<endl<<"2-no";
		std::cout << '\n';
		container.add(object);
		try {
			cin >> chk;
			if (!chk)
				throw "Input error!";
			if (chk != 1 && chk != 2)
				throw "Input error!";
		}
		catch (const char* str_exception) {
			return 4;
		}
		if (chk == 2) {
			break;
		}
		std::cout << '\n';
	}

	ListWear::Iterator it(container.begin());
	
	int key = 0;
	int length = s;
	while (1) {
		int j = 0;
		cout <<"--------------------"<<endl<< "1 - Output " << endl << "2 - Add " << endl <<"3 - Delete" << endl <<"4 - Find" <<  endl << "5 - Sort"<<endl << "--------------------" <<endl;
		try {
			cin >> key;
			if (!key)
				throw "Input error!";
			if (key < 1 && key > 7)
				throw "Input error!";
		}
		catch (const char* str_exception) {
			return 4;
		}
		if (key == 1) {
			ListWear::Iterator it(container.begin());
			
			for (int i = 0; i < container.getLength() - j; i++) {
				std::cout << *(it) << '\n';
				it++;
			}
		}
		if (key == 2) {
			std::cout << "Enter a name of the wear " << '\n';
			cin >> userName;
			object.nameSetter(userName);
			std::cout << '\n';
			std::cout << "Enter the id of the wear" << '\n';
			std::cin >> number;
			std::cout << '\n';
			object.idSetter(number);
			std::cout << "Do you want to continue? y/n" << '\n';
			std::cout << '\n';
			container.add(object);
		}
		if (key == 3) {
			std::cout << "Enter the id of the wear" << '\n';
			std::cin >> number;
			std::cout << '\n';
			ListWear::Iterator it(container.begin());
			while (it != container.end()) {
				if (it.cur->getId() == number) {
					std::cout << *(it) << '\n';
					break;
				};
				it++;
			}
			container.detailDelete(it);
			j++;
		}

		if (key == 4) {
			std::cout << "Enter the id of the wear" << '\n';
			std::cin >> number;
			std::cout << '\n';
			ListWear::Iterator it(container.begin());
			while (it != container.end()) {
				if (it.cur->getId() == number) {
					std::cout << *(it) << '\n';
					break;
				};
				it++;
			}
		}
		if (key == 5) {	//SHELL SORT
			
			int d = length / 2;  //STEP
			while (d)
			{
				for (int i = 0; i < container.length; i++) {

					ListWear::Iterator it(container.begin());

					for (int j = 0; j < container.length - 1; j++) {

						ListWear::Iterator it(container.begin() + j);

						ListWear::Iterator it1(container.begin() + j + 1);

						if (it > it1) {
							container.swap(it);
							d/=2;						//Step 
							
						}
					}
				}
			}
		}
		if (key == 6) {
			ListWear::Iterator it2(container.begin());
			int h = container.length - 1;
			it2 = it2 + h;
			for (int i = 0; i < container.getLength(); i++) {
				std::cout << *(it2) << '\n';
				it2 = it2 - 1;
			}
		}
		if (key == 7) {
			ListWear::Iterator it3(container.begin());
			ListWear::Iterator it4(container.begin());
			int h = (container.length - 1) / 2;
			it3 = it3 + h;
			if (h % 2 == 1) h++;
			it4 = it4 + h;
			for (int i = 0; i < container.getLength() / 2; i++) {
				std::cout << *(it3) << '\n';
				it3 = it3 - 1;
				std::cout << *(it4) << '\n';

				it4 = it4 + 1;
			}
		}
	}
	Wear object2;
	int a;
	std::cin >> a;
}
