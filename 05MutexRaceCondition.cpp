// TOPIC: Mutex In C++ Threading | Why Use Mutex | What Is Race Condition And How To Solve It? | What Is Critical Section


// Mutex: Mutual Exclusion



// RACE CONDITION

7/ 8. Race condition is a situation where two or more threads/process happened to change a common data at the same time.

// 1. If there is a race condition then we have to protect it and the protected section is called critical section/region.



// MUTEX:

// 8. Mutex is used to avoid race condition.

// 1. We use lock() , unlock() on mutex to avoid race condition.

#include <iostrean>
#include <thread>
using namespace std;

int myAmount = 0;

void addMoney() {  //RACE condition
	++myAmount;     //Critical section
}
int main() {
	std :: thread t1(addMoney);
	std :: thread t2(addMoney);

	t1.join();
	t2.join();

	cout << myAmount << endl;
	return 0;
}


mutex~~~~

#include <iostream>
#include <thread>
#include <mutex>
#include <algorithm>
using namespace std;

int myAmount = 0;
std::mutex m;

void addMoney() {
    m.lock();		//first t1 will lock then after t1 unlock then only t2 can lock or viceversa, so no RACE condition  Funny E.g. Toilet
	++myAmount;
	m.unlock();
}
int main() {
	std :: thread t1(addMoney);
	std :: thread t2(addMoney);

	t1.join();
	t2.join();

	cout << myAmount << endl;
	return 0;
}