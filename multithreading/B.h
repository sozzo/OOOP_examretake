#pragma once
#include "A.h"
#include <vector>
class B
{
public:
	A a;

	B() : a(A()) {}
	B(int k) : a(A(k)) {}
	B(A a) : a(a) {}
	void transform(A a)
	{
		this->a.x= a.x;
	}
	B merge(std::vector<B> bArray, int N)
	{
		int k = 1;
		for (int i = 0; i < N; i++){
			k = k * bArray.at(i).a.x;
	}
		return B(k);
	}

};

