#include <iostream>
#include<thread>
#include "A.h"
#include "B.h"	
using namespace std;
B genTransferMerge(int x) {
	vector<A> generator;
	vector<B> transformer;
	B res;
	for (int i = 0; i < x; i++) {
		A a(7);
		a.generate();
		generator.push_back(a);
	}
	for (int i = 0; i < x; i++) {
		B b(7);
		b.transform(generator.at(i));

		transformer.push_back(b);
	}
	res = res.merge(transformer, x);
	return res;

}
int main()
{
	int lengthOfArray = 0;
	unsigned int numberOfThreads = thread::hardware_concurrency();//determines effective number of concurrent threads posible
	//cout << numberOfThreads << endl;
	char threadAnswer;
	cout << 17 / 4;
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
	vector<thread> threads;
	while (lengthOfArray < 1) {
		cout << "how many As shall we generate(can't be less than 1)";
		cin >> lengthOfArray;
		if (lengthOfArray < 1) {
			cout << "wrong input" << endl;
		}
	}
	cout<<genTransferMerge(lengthOfArray).a.x;
	
    std::cout << "Hello World!\n";
	
}