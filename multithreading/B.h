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
	B transform(A a)
	{
		return B(a);
	}
	B merge(B* bArray, size_t N)
	{
		int k = 0;
		for (size_t i = 0; i < N; i++)
			k += bArray[i].a.x;

		return B(k);
	}

};

