#include <iostream>
#include<thread>
#include "A.h"
#include "B.h"	
using namespace std;

int main()
{
	int lengthOfArray = 0;
	int numberOfThreads = 2;

	cout << "numberOfThreads = ";
	cin >> numberOfThreads;
	vector<thread> threads;

	cout << "length of array = ";
	cin >> lengthOfArray;
	
    std::cout << "Hello World!\n";
	
}