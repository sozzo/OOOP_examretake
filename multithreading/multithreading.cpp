#include <iostream>
#include<thread>
#include <future>
#include "A.h"
#include "B.h"	
using namespace std;
void genTransferMerge(int x, B &toMerge) {//toMerge is the variable that we merge into
	vector<A> generator;
	vector<B> transformer;
	B res;
	for (int i = 0; i < x; i++) {
		A a(1);
		a.generate();
		generator.push_back(a);
	}
	for (int i = 0; i < x; i++) {
		B b(1);
		b.transform(generator.at(i));

		transformer.push_back(b);
	}
	res = res.merge(transformer, x);
	toMerge.a.x = res.a.x;
}
int main()
{
	int amountOfVariables = 0;// must be redefined to 1 or greater by the user
	unsigned int numberOfThreads = thread::hardware_concurrency();//determines effective number of concurrent threads posible
	//cout << numberOfThreads << endl;
	char threadAnswer;
	vector<thread> threads;//vector of threads
	vector<B>inBetweenRes;//results after closing each vector
	B res(1);
	res.a.x = 1;
	cout << "Do you want to change the amount of threads(set to the number of cores by default)? y/n" << endl;
	cin >> threadAnswer;
	if (threadAnswer == 'y') {
		cout << "new amount of threads = ";
		cin >> numberOfThreads;
	}
	else {
		if (threadAnswer == 'n') {
			cout << "amount of threads wasn't changed" << endl;
		}
		else {
			cout << "wrong input, amount of threads wasn't changed";
		}
	}
	for (int i = 0; i < numberOfThreads; i++) {
		inBetweenRes.push_back(B(1));
	}

	while (amountOfVariables < 1) {
		cout << "how many As shall we generate(can't be less than 1)";
		cin >> amountOfVariables;
		if (amountOfVariables < 1) {
			cout << "wrong input" << endl;
		}
	}


	if (amountOfVariables % numberOfThreads == 0) {
		for (int i = 0; i < numberOfThreads; i++) {
			threads.push_back(thread(genTransferMerge, amountOfVariables / numberOfThreads, ref(inBetweenRes.at(i))));//pushing same amount of elements to all threads
		
		}
	}else{
		for (int i = 0; i < numberOfThreads - 1; i++) {
			threads.push_back(thread(genTransferMerge, (amountOfVariables / numberOfThreads)+1, ref(inBetweenRes.at(i))));//pushing different amount of elements to last thread
		}
		threads.push_back(thread(genTransferMerge, (amountOfVariables - (amountOfVariables / numberOfThreads) + 1) * (numberOfThreads-1), ref(inBetweenRes.at(numberOfThreads-1))));//calculating number of leftover A variables
	}
	for (unsigned int i = 0; i < numberOfThreads; ++i)
	{
		if (threads.at(i).joinable())
			threads.at(i).join();
	}
	for (int i = 0; i < numberOfThreads; i++) {
		res.a.x = (res.a.x * inBetweenRes.at(i).a.x);
	}
	cout<<"result is " << res.a.x<<endl;
	
    std::cout << "Hello World!\n";
	
}