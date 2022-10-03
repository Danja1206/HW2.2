#include <iostream>
#include <fstream>
#include "Task1.h"
#include "Task 2.h"
#include "Task 3.h"
#include "Time.h"

using namespace std;

void Task1()
{
	int x = 5, y = 15;
	int* x_ptr = &x, * y_ptr = &y;

	cout << x << " " << *x_ptr << " " << y << " " << *y_ptr << endl;
	Swap<int>(x_ptr, y_ptr);
	cout << x << " " << *x_ptr << " " << y << " " << *y_ptr << endl;

	string a_s = "abc", b_s = "def";
	string* a_s_ptr = &a_s, * b_s_ptr = &b_s;

	cout << "a = " << *a_s_ptr << " b = " << *b_s_ptr << endl;
	Swap<string>(a_s_ptr, b_s_ptr);
	cout << "a = " << *a_s_ptr << " b = " << *b_s_ptr << endl;
}

void Task2()
{
	const size_t size = 25;
	vector<int*> Array;
	Array.reserve(size);
	for (int i = 0; i < size; i++)
	{
		int* element = new int(rand() % 50);
		Array.push_back(element);
	}
	auto printArray = [&Array]()
	{
		for (auto i : Array)
		{
			cout << *i << " ";
		}
		cout << std::endl;
	};
	printArray();
	SortPointers<int>(Array);
	printArray();

	for (auto i : Array)
		delete i;
}

void Task3()
{
	ifstream File("../Input.txt");
	File.seekg(0, ios::end);
	size_t size = File.tellg();
	File.seekg(0);
	string s(size, ' ');
	File.read(&s[0], size);

	string vowels = "АОИЕЁЭЫУЮЯаоиеёэыуюя";

	uint16_t count;
	RunTimer timer;
	timer.start("Count_if_find");
	count = Count_if_find(s, vowels);
	timer.print();
	cout << count << " Гласных" << endl;

	timer.start("Count_if_for");
	count = Count_if_for(s, vowels);
	timer.print();
	cout << count << " Гласных" << endl;

	timer.start("For_find");
	count = For_find(s, vowels);
	timer.print();
	cout << count << " Гласных" << endl;

	timer.start("For_For");
	count = For_for(s, vowels);
	timer.print();
	cout << count << " Гласных" << endl;
}

int main()
{
	Task1();
	Task2();
	Task3();
	return 0;
}

