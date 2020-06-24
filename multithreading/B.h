#pragma once
#include "A.h"
#include <vector>
class B
{
private:
	double b;
public:
	double getB() {
		return this->b;
	}
	void setB(double x) {
		this->b = x;
	}
	B AintoB(A a) {
		setB((double)a.getA());
	}
	
};

