#include "Container.h"
#include <iostream>

Container::Container()
{

}

Container::~Container()
{
	delete[] dynamicArr;
	delete[] staticArr_ptr;
}

void Container::pushBack()
{
	std::cout << "Enter item to add: ";
	int item{};
	std::cin >> item;

	for (size_t i{ 0 }; i < size; i++) {
		if (staticArr_ptr[i] == NULL) {
			staticArr_ptr[i] = item;				//nie dziala tworzenie nowej tablicy, jeszcze nie doszedlem do tego dlaczego tak sie dzieje
			break;
		}
		else if (staticArr_ptr[size-1] != NULL) {
			createNewArray();
		}
	}
}

void Container::createNewArray()
{
	std::cout << "Enter size of new array: ";
	std::cin >> size;
	std::cin.ignore();
	
	dynamicArr = new int[size];
	staticArr_ptr = dynamicArr;

	for (size_t i{ 0 }; i <= size; i++) {
		staticArr_ptr[i] = NULL;
	}

	for (size_t i{ 0 }; i < 4; i++) {
		staticArr_ptr[i] = staticArr[i];
	}
}

int Container::getIndex()
{
	int index{};
	std::cout << "Enter index number: ";
	std::cin >> index;

	std::cout << staticArr[index] << std::endl << std::endl;

	return staticArr[index];
}

void Container::setIndex()
{
	int index{}, value{};
	std::cout << "Enter index number: ";
	std::cin >> index;
	std::cout << "Enter new value for: ";
	std::cin >> value;

	staticArr[index] = value;
}

void Container::clear()
{
	for (auto i : staticArr) {
		staticArr[i] = 0;
	}
	delete[] dynamicArr;
}

void Container::displayArr()
{
	int index{0};
	std::cout << std::endl;
	std::cout << "\t------------------------------\n";
	for (size_t i{ 0 }; i < 4; i++) {
		std::cout << "\t" << index << ". " << staticArr_ptr[i];
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
