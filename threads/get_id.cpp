#include <thread>
#include <iostream>

int main() 
{
	std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
}
	
