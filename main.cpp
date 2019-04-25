#include<iostream>

#include "smartSharedPointer.h"

int main()
{
	smartSharedPointer<double> sptr_1(new double(7.7));
	std::cout << "===== Creating sptr_1(smart Pointer).\n";
	std::cout << "sptr_1 value = " << *sptr_1 << '\n';
	std::cout << "sptr_1's counter = " << sptr_1.getCounter() << "\n\n";

	std::cout << "===== Creating sptr_2(smart Pointer).\n";
	smartSharedPointer<double> sptr_2(new double(2.2));
	std::cout << "sptr_2 value = " << *sptr_2 << '\n';
	std::cout << "sptr_2's counter = " << sptr_2.getCounter() << "\n\n";

	std::cout << "===== Copying sptr_1 to sptr_3.\n";
	smartSharedPointer<double> sptr_3(sptr_1);
	std::cout << "sptr_1 value = " << *sptr_1 << '\n';
	std::cout << "sptr_2 value = " << *sptr_2 << '\n';
	std::cout << "sptr_3 value = " << *sptr_3 << '\n';
	std::cout << "sptr_1's counter = " << sptr_1.getCounter() << '\n';
	std::cout << "sptr_2's counter = " << sptr_2.getCounter() << '\n';
	std::cout << "sptr_3's counter = " << sptr_3.getCounter() << "\n\n";

	std::cout << "===== Assigning sptr_2 to sptr_3.\n";
	sptr_3 = sptr_2;
	std::cout << "sptr_1 value = " << *sptr_1 << '\n';
	std::cout << "sptr_2 value = " << *sptr_2 << '\n';
	std::cout << "sptr_3 value = " << *sptr_3 << '\n';
	std::cout << "sptr_1's counter = " << sptr_1.getCounter() << '\n';
	std::cout << "sptr_2's counter = " << sptr_2.getCounter() << '\n';
	std::cout << "sptr_3's counter = " << sptr_3.getCounter() << std::endl;

	return 0;
}