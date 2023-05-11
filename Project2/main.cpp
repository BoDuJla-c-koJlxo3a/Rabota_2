#include "dynarr.h"
#include "linlist.h"
#include "interaction.h"
#include <iostream>

int test1() {
	DynamicArray<int> a = DynamicArray<int>(5);
	a.Set(0, 1);
	a.Set(1, 2);
	a.Set(2, 3);
	a.Set(3, 4);
	a.Set(4, 5);
	a.Resize(3);
	std::cout << a.GetSize();
	for (int i = 0; i < 3; i++) {
		std::cout << a.Get(i) << "\n";
	}
	try {
		a.Get(8);
	}
	catch (int w) {
		std::cout << "Index out of range(" << w << ")\n";
	}
	std::cout << "//////////////////////\n";
	char st[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
	LinkedList<char> b = LinkedList<char>(st, 6);
	std::cout << "First " << b.GetFirst() << "\n";
	std::cout << "Last " << b.GetLast() << "\n";
	std::cout << "First " << b.GetFirst() << "\n";
	std::cout << "Treci " << b.Get(2) << "\n";
	std::cout << "Len " << b.GetLength() << "\n";
	LinkedList<char>* d = new LinkedList<char>(b);
	LinkedList<char>* c = d->GetSubList(0, 3);
	c->Prepend('x');
	c->Append('z');
	c->Append('u');
	c->InsertAt('e', 7);
	std::cout << 1 << c->Get(0) << "\n";
	std::cout << 2 << c->Get(1) << "\n";
	std::cout << 3 << c->Get(2) << "\n";
	std::cout << 4 << c->Get(3) << "\n";
	std::cout << 5 << c->Get(4) << "\n";
	std::cout << 6 << c->Get(5) << "\n";
	std::cout << 7 << c->Get(6) << "\n";
	std::cout << 8 << c->Get(7) << "\n";
	try {
		std::cout << 11 << c->Get(10) << "\n";
	}
	catch (int q) {
		std::cout << "Index out of range(" << q << ")\n";
	}
	LinkedList<char>* m = c->Concat(&b);
	int siz = m->GetLength();
	for (int i = 0; i < siz; i++) {
		std::cout << i+1 << m->Get(i) << '\n';
	}
	return 0;
}

int main() {
	testingInterface();
	return 0;
}