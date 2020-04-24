// variable_from_heap.cpp

#include <iostream>
using std::cout;
using std::endl;
#include <thread>
using std::thread;

void new_thread_callback(int* p)
{
	cout << "Inside thread p = " << p << endl;
	std::chrono::milliseconds duration{1000};
	std::this_thread::sleep_for(duration);
	*p = 19;
}

int main()
{
	int *p = new int();
	*p = 10;
	cout << "Inside main thread *p =" << *p << endl;
	thread t{new_thread_callback,p};
	t.detach();
	delete p;
	p = NULL;
	std::chrono::milliseconds duration{2000};
	std::this_thread::sleep_for(duration);
	return 0;
}