// TOPIC: Use Of join(), detach() and joinable(] In Thread In C=+ (C++11)


// JOIN NOTES

// 0. Once a thread is started we wait for this thread to finish by calling join() function on thread object.

// 1. Double join will result into program termination.

// 2. If needed we should check thread is joinable before joining. (using joinable() function)



// DETACH NOTES

// 0. This is used to detach newly created thread from the parent thread.

// 1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and

// Double detach() will result Into program termination.

// 2. If we have detached thread and main function is returning then the detached thread execution is suspended.



// NOTES:

// Either joint() or detach() should be called on thread object, otherwise during thread object's destructor it will

// terminate the program, Because inside destructor it checks if thread is still joinable? If yes then it terminates the program.



The moment you create a thread that thread is marked as joinable and then later once either you apply join() or detach() on that thread then it automatically becomes non-joinable.

So always use join() or detach()
void run(int count) {
	while(count -- > 0)
		cout << "Abhisek" << endl;
	std::this_thread::sleep_for(seconds(5));
}
int main() {
	std :: thread t1(run, 10) ;
	cout<<"main() "<<endl;
	t1.join(); // waiting 5 sec to join
//t1.join(); // double join terminates the program : ERROR

	if(t1.joinable())  // will pass: always use joinable() before join()
		t1.join();
	cout<<"after main() "<<endl;
	return 0;
}

#############################

void run(int count) {
	while(count -- > 0)
		cout << "Abhisek" << endl;
	std::this_thread::sleep_for(seconds(5));
}
int main() {
	std :: thread t1(run, 10) ;
	cout<<"main() "<<endl;
    t1.detach(); //will not wait for 5 sec for thread to join()
	return 0;
}



void run(int count) {
	while(count -- > 0)
		cout << "Abhisek" << endl;

	cout << "Thread finish" << endl;
}
int main() {
	std :: thread t1(run, 10) ;
	cout<<"main() "<<endl;
	if(t1.joinable())
	    t1.detach(); //will not wait for 5 sec for thread to join()
	cout<<"main() after"<<endl;
	std::this_thread::sleep_for(seconds(5));
	return 0;
}

main() 
main() after
Abhisek
Abhisek
Abhisek
Abhisek
Abhisek
Abhisek
Abhisek
Abhisek
Abhisek
Abhisek
Thread finish
