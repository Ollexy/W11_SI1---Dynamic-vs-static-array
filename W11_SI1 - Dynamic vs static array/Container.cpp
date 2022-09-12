#include "Container.h"
#include <iostream>

Container::Container()
{

}

Container::~Container()
{
	delete[] arr;
}

void Container::pushBack()
{

	if (pos == size) {
		extendArray();
	}

	std::cout << "Enter item to add: ";
	int item{};
	std::cin >> item;

	arr[pos] = item;		
	pos++;
	
}

void Container::extendArray()
{
	int* previousArr = arr;
	std::cin.ignore();
	
	size = size * 2;
	arr = new int[size];
	
	for (size_t i{ 0 }; i < size/2; i++) {
		arr[i] = previousArr[i];
	}

	delete[] previousArr;
}

int Container::getIndex()
{
	int index{};
	std::cout << "Enter index number: ";
	std::cin >> index;

	std::cout << arr[index] << std::endl << std::endl;

	return arr[index];
}

void Container::setIndex()
{
	int index{}, value{};
	std::cout << "Enter index number: ";
	std::cin >> index;
	std::cout << "Enter new value for: ";
	std::cin >> value;

	arr[index] = value;
}

void Container::clear()
{
	pos = 0;
}

void Container::displayArr()
{
	int index{0};
	std::cout << "Size of arr: " << size << std::endl << std::endl;
	std::cout << std::endl;
	std::cout << "\t------------------------------\n";
	for (size_t i{ 0 }; i < pos; i++) {
		std::cout << "\t" << index << ". " << arr[i];
		index++;
	}
	std::cout << std::endl << std::endl;

}

void Container::menu()
{
	while (1) {
		std::cout << "\t\t--- Choose option ---\n\n";
		std::cout << "\t\t1. Display array\n";
		std::cout << "\t\t2. Add element to array\n";
		std::cout << "\t\t3. Clear array\n";
		std::cout << "\t\t4. Get index\n";
		std::cout << "\t\t5. Set index\n";
		std::cout << "\t\t6. Exit\n\n>> ";

		int choice{};
		std::cin >> choice;

		switch (choice) {
		case 1:
			displayArr();
			break;
		case 2:
			pushBack();
			break;
		case 3:
			clear();
			break;
		case 4:
			getIndex();
			break;
		case 5:
			setIndex();
			break;
		case 6:
			exit(0);
		default: std::cout << "There is no such option. Try another one\n\n";
		}
	}
	
}
