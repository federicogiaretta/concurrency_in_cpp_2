#include <iostream>
#include <thread>
#include <chrono>

void ops(int* var)
{
    std::this_thread::sleep_for(std::chrono::seconds{1});
    ++(*var);	
}

int main()
{
	        int var=0;
		std::thread timer{ops, &var};
		timer.join();
		std::cout << var << std::endl;
}
