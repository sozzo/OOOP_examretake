#pragma once
#include<random>
class A
{
public:
	int x;

	A() : x(1) {}
	A(int x) : x(x) {}
	void generate()
	{
		this->x=(rand()%10+1);
	}

};

