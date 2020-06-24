#pragma once
#include<random>
class A
{
private: int a;
public: 
	int getA() {
		return this->a;
	}
	void setA(int x) {
		this->a = x;
	}
	void generate() {
		this->setA(rand() % 100);
	}
};