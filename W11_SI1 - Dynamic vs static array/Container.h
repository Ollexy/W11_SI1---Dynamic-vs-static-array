#pragma once
class Container
{

	int size = 4;
	int* arr = new int[size];
	int pos = 0;

public:
	Container();
	~Container();
	void pushBack();
	void extendArray();
	int getIndex();
	void setIndex();
	void clear();
	void displayArr();
	void menu();
};

