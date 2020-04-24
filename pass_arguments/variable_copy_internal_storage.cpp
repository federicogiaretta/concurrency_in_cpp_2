// variable_copy_internal_storage.cpp

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <thread>
using std::thread;

void thread_callback(int x, string str) 
{
	cout << "Passed number = " << x << endl;
	cout << "Passed string = " << str << endl;
}

int main()
{
	int x{10};
	string str{"sample string"};
	thread tread_obj{thread_callback, x, str};
	tread_obj.join();
	return 0;
}