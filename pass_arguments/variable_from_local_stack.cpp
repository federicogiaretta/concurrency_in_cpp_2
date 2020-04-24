// variable_from_local_stack.cpp

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

void start_new_thread()
{
	int i{10};
	cout << "Inside main thread i = " << i << endl;
	thread t(new_thread_callback, &i);
	t.detach();
	cout << "Inside main thread i = " << i << endl;
}

int main()
{
	start_new_thread();
	std::chrono::milliseconds duration{2000};
	std::this_thread::sleep_for(duration);
	return 0;
}
