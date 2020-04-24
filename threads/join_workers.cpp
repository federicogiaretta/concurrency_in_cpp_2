#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>

class Worker_thread
{
public:
	void operator()() 
	{
		std::cout << "Worker Thread " << std::this_thread::get_id() << " is Executing" << std::endl;
	}
};

int main()  
{
	std::vector<std::thread> threads;
	for(int i=0; i<10; i++)	{
		threads.push_back( std::thread{Worker_thread{}} );
	}
    // Now wait for all the worker thread to finish i.e.
    // Call join() function on each of the std::thread object
	std::cout<<"wait for all the worker thread to finish"<<std::endl;
	std::vector<std::thread>::iterator worker;
	for (worker=threads.begin(); worker != threads.end(); ++worker)
		worker->join();
	std::cout<<"Exiting from Main Thread"<<std::endl;
	return 0;
}
