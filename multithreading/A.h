#pragma once
#include<random>
class A
{
public:
	int x;

	A() : x(0) {}
	A(int x) : x(x) {}
	void generate()
	{
		this->x=(rand()%100);
	}

};

