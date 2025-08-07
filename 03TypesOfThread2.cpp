// TOPIC: Types Of Thread Creation In C++ll.
// There are 5 different types we can create threads in C++11 using callable objects.

// NOTE:
// If we create multiple threads at the sane time it doesn't guarantee which one will start first.

// 1. Function Pointer
// This is the very basic form of thread creation.

void fin(int x){
while (x-- > 0){
cout << x << endl;
}
}

int main() {
std :: thread t(fun, 10);
t.join();
return 0;
}

// 2. Lambda Function
// Exanple:

int main() {
// we can directly inject lambda at thread creation time.
	auto fun = [](int x) {
		while (x-- > 0) {
			cout << x << endl;
		}

	};

	std :: thread t(fun, 10);
	t.join();
	return 0;

}


/*
9
8
7
6
5
4
3
2
1
0
*/

// after thread

// 2. Lambda Function
// Exanple:

int main() {
// we can directly inject lambda at thread creation time.

	std :: thread t([](int x) {
		while (x-- > 0) {
			cout << x << endl;
		}

	}, 10);
	t.join();
	return 0;

}


1// 3. Functor (Function Object)

class Base {
public:
	void operator () (int x) // callable object
	{
		while (x -- > 0) {
			cout << x << endl;
		}
	}
};
int main() {
	std :: thread t((Base()), 10);
	t.join();
	return 0;
}


// 4. Non-static member function

class Base
{
public:
	void run(int x) {
		while (x -- > 0) {
			cout << x << endl;
		}
	}
};
int main() {
	Base b;
	std :: thread t(&Base :: run, &b, 10);  // (address_of_function, Object, parameter)
	t.join();
	return 0;
}


//5. static member function

class Base
{
public:
	static void run(int x) {
		while (x -- > 0) {
			cout << x << endl;
		}
	}
};
int main() {
	Base b;
	std :: thread t(&Base :: run, 10);  // no object as static function
	t.join();
	return 0;
}
