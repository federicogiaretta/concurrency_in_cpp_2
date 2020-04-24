// output.cpp

#include <iostream>
using std::cout;
using std::endl;
#include <thread>
using std::thread;
#include <mutex>
using std::mutex;
#include <vector>
using std::vector;


#include "Wallet.h"

mutex cout_mutex;

void workers_work(int i)
{
	thread::id name = std::this_thread::get_id();
	cout_mutex.lock();
	cout << "The id of thread " << i <<  endl;
	cout << "is: " << name << endl;
	cout_mutex.unlock();


}
 
int main()
{
	int no_of_workers{1000};

	std::vector<std::thread> threads;
	for(int i=0; i<no_of_workers; i++)
		threads.push_back( std::thread{workers_work, i});

	vector<thread>::iterator worker;
	for (worker=threads.begin(); worker != threads.end(); ++worker)
		worker->join();
	
	cout << "Exiting from Main Thread" << endl;
	return 0;
}


 