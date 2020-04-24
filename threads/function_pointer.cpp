#include <iostream>  
#include <thread>  
  
void thread_function()  
{  
	for(int i = 0; i < 100000; i++)  
		std::cout << "thread function executing" << std::endl;  
}  
  
int main()    
{
	std::thread thread_obj{thread_function};  
	for(int i = 0; i < 1000; i++)  
		std::cout << "Display from Main Thread" << std::endl;  
	thread_obj.join();      
	std::cout << "Exit of Main Thread" << std::endl;  
	return 0;  
}  

