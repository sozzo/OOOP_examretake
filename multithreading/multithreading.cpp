#include <iostream>
#include<thread>
#include "A.h"
#include "B.h"	
using namespace std;
int step_i = 0;
/*B merge() {//reused code
	for (int h = 2; h <= max_threads; h++)
	{
		for (int i = 0; i < h; i++)
		{
			pthread_create(thr_id[i], NULL, multiplyMatrices, i);
		}

		for (int i = 0; i < h; i++)
		{
			pthread_join(thr_id[i], NULL);
		}
	}
}*/
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