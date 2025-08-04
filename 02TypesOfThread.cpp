// using thread



#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std :: chrono;

typedef unsigned long long ull;

ull OddSum = 0;
ull EvenSum = 0;

void findEven(ull start, ull end) {
	for (ull i = start; i <= end; ++i) {
		if ((i & 1) == 0) {
			EvenSum += i;
		}
	}
}

void findOdd(ull start, ull end) {
	for (ull i = start; i <= end; ++i) {
		if ((i & 1) == 1) {
			OddSum += i;
		}
	}

}

// Main is the single main thread.
int main() {

	ull start = 0, end = 1900000068;
	auto startTime = high_resolution_clock::now();
    
    // std::thread thread_Name(Function Pointers, parameter);
	//Both thread will run parallelly will take time/2 
    std::thread t1(findEven, start, end);
    std::thread t2(findOdd, start, end);
    
    // Thtread t1, t2 will join the main thread after complition
    t1.join();
    t2.join();
    
// 	findOdd(start, end);
// 	findEven(start, end);

	auto stopTime = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stopTime-startTime);



	cout << "OddSum : " << OddSum << endl;
	cout << "EvenSum : " << EvenSum << endl;

	cout<< "Time taken to run in sec: "<< duration.count()/1000000<< endl;

	return 0;
}

/* output
OddSum : 902500064600001156
EvenSum : 902500065550001190
taken to run in sec: 8
*/