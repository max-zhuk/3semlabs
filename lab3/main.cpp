#include "Header.h"

Massive& operator--(Massive& a)
{
	for (int i = 0; i < a.n; i++) a.arr[i] -= 1;
	return a;
}

int main()
{
	int n, n2;
	Massive* d;
	std::cout << "Enter a size of the first array" << endl;
	std::cin >> n;
	Massive ms(n);
	
	std::cout << "Enter a size of the second array" << endl;
	std::cin >> n2;
	Massive mas(n2);

	std::cout <<"Enter the first array ( "<<n<<" elem.)"<< endl;
	ms.setMassive();

	Massive ms_copy(ms);

	std::cout << "Enter the second array( " << n2 << " elem.)" << endl;
	mas.setMassive();

	Massive merge = ms + mas;
	std::cout << "Merge of this arrays: ";
	merge.show();
	std::cout << endl;

	Massive ring(n + n2);
	ring = merge;
	std::cout << "Overloaded '=' work ( merge swap): ";
	ring.show(); std::cout << endl;


	merge.ShellSort();
	std::cout << "Sorted merge(Shell) ";
	merge.show();
	std::cout << endl;
	

	--ms_copy;
	std::cout << "Changed copy of the first massive using '--': ";
	ms_copy.show();
	std::cout << endl;

	int c = 2;
	d = new Massive[c];
	for (int i = 0; i < c; i++)
	{
		d[i].setSize(c);
		d[i].setMassive();
		d[i].ShellSort();
	}
	for (int i = 0; i < c; i++) { std::cout << endl; d[i].show(); }

	

	


	
	




}