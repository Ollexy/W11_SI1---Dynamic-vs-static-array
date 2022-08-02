#pragma once
class Container
{
	int size{4};
	int staticArr[4]{};
	int* staticArr_ptr{ staticArr };
	int* dynamicArr{};

public:
	Container();
	~Container();
	void pushBack();
	void createNewArray();
	int getIndex();
	void setIndex();
	void clear();
	void displayArr();
	void menu();
};

