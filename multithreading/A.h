#pragma once
#include<random>
class A
{
public:
	int x;

	A() : x(0) {}
	A(int x) : x(x) {}
	A generate()
	{
		return A(rand()%100);
	}

};

