#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int getValue_int()
{
	while (true)
	{
		int a;
		std::cin >> a;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Enter int!\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return a;
		}
	}
}
class Wear {
private:

public:
	string name;
	int id = 0, tmp = 0;
	Wear* next;
	Wear* prev;
	friend class Controller;
	Wear() {
		int defaultId = 1111111;
		id = defaultId;
	}
	void init(const Wear& data) {
		this->id = data.id;
		this->name = data.name;
	}

	int idSetter(int number) {
		id = number;
		return 0;
	}
	void nameSetter(string userName) {
		name = userName;
		return;
	}

	void printWearInfo() {
		cout << "Id:" << id << endl;
		cout << name;
	}
	int getId() {
		return id;
	}
	friend std::ostream& operator<<(std::ostream& out, const Wear& detail);
};

class Controller {
public:
	int ControllerIdSetter(Wear& object) {
		object.id = object.tmp;
		return 0;
	}
};

class ListWear {
private:
	Wear* tail, * head;
public:
	int length = 0;
	class Iterator;
	ListWear() :length(0), tail(nullptr), head(nullptr) {

	}
	bool ifUncommon(string name1, int id1) {
		ListWear::Iterator it(begin());
		for (int j = 0; j < length; j++) {
			ListWear::Iterator it(begin() + j);
			if (name1 == it.cur->name && id1 == it.cur->id) {
				cout << '\n' << "There is the element with sames id and name" << '\n';
				return false;
			}
			else if (name1 == it.cur->name && id1 != it.cur->id) {
				cout << '\n' << "There is the element with same name" << '\n';
				return false;
			}
			else if (name1 != it.cur->name && id1 == it.cur->id) {
				cout << '\n' << "There is the element with same id" << '\n';
				return false;
			}
		}
		return true;
	}
	void add(Wear data) {
		if (length != 0)
			if (!ifUncommon(data.name, data.id))
				return;
		Wear* temp = new Wear;
		temp->next = NULL;
		temp->init(data);
		if (head != NULL)
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
			temp->next = NULL;
		}
		else
		{
			temp->prev = NULL;
			head = tail = temp;
		}
		length++;
	}
	void detailDelete(Iterator it) {
		ListWear::Iterator tmp2(it.cur);
		if (tmp2.cur->prev == NULL) {
			tmp2.cur->next->prev = NULL;
			head = tmp2.cur->next;
			delete(tmp2.cur);
			length--;
			return;
		}
		if (tmp2.cur->next == NULL) {
			tmp2.cur->prev->next = NULL;
			tail = tmp2.cur->prev;
			delete(tmp2.cur);
			length--;
			return;
		}
		ListWear::Iterator tmp1(it.cur->prev);
		cout << *tmp1;
		cout << *tmp2;
		ListWear::Iterator tmp3(it.cur);
		tmp1 = tmp3;
		tmp1.cur->prev->next = tmp3.cur->next;
		tmp1.cur->next->prev = tmp3.cur->prev;
		length--;
	}

	void swap(Iterator it) {
		ListWear::Iterator tmp1(it.cur);
		cout << *it;
		ListWear::Iterator tmp2(it.cur->next);

		ListWear::Iterator tmp(it.cur->prev);
		if (tmp.cur != NULL)
			tmp.cur->next = tmp2.cur;
		tmp2.cur->prev = tmp.cur;

		tmp1.cur->prev = tmp2.cur;
		tmp1.cur->next = tmp2.cur->next;
		tmp2.cur->next = tmp1.cur;
		if (tmp1.cur->next != NULL)
			tmp1.cur->next->prev = tmp1.cur;
		if (tmp.cur == NULL)
			head = tmp2.cur;
		if (tmp1.cur->next == NULL)
			tail = tmp1.cur;
	}



	~ListWear() {

	}

	Iterator begin() { return head; }
	Iterator end() { return tail->next; }
	Iterator end1() { ListWear::Iterator tmp1(begin() + getLength() - 1); return tmp1.cur; }
	Wear& operator[](int index)
	{

	}
	int lengthDic() {
		length--;
		cout << length;
		return length;
	}
	int getLength() { return length; }

	class Iterator {
	public:
		Wear* cur;
		Iterator(Wear* first) :cur(first) {
		}
		Iterator operator+ (int n) {
			for (int i = 0; i < n; i++) {
				cur = cur->next;
			}
			return Iterator(cur);
		}
		Iterator operator- (int n) {
			for (int i = 0; i < n; i++) {
				cur = cur->prev;
			}
			return Iterator(cur);
		}

		Iterator operator++ (int) {
			cur = cur->next;
			return Iterator(cur);
		}
		Iterator operator--(int) {
			cur = cur->prev;
			return Iterator(cur);
		}
		Iterator operator++ () {
			cur = cur->next;
			return Iterator(cur->next);
		}
		Iterator operator--() {
			cur = cur->prev;
			return Iterator(cur);
		}


		bool operator>(Iterator a) {
			return(cur->id > a.cur->id);
		}
		bool operator<(Iterator a) {
			return(cur->id < a.cur->id);
		}

		bool operator!= (const Iterator& it) {
			return cur != it.cur;
		}
		bool operator== (const Iterator& it) {
			return cur == it.cur;
		}

		Wear& operator*() { return *cur; }
	};

}; //----------------//

ostream& operator<<(ostream& out, const Wear& detail) {
	out << "Name: ";
	out << detail.name << '\n';
	out << "Id: ";
	out << detail.id << '\n';
	return out;
}
