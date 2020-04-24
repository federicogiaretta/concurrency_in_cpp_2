#include <iostream>  
#include <thread>  

void thread_function()  
{  
	std::cout << "Inside Thread :: ID  = " << std::this_thread::get_id() << std::endl;      
}

int main()    
{  
	std::thread thread_obj1{thread_function};  
	std::thread thread_obj2{thread_function};  
 
	if(thread_obj1.get_id() != thread_obj2.get_id())  
		std::cout << "Both Threads have different IDs" << std::endl;  

	std::cout << "From Main Thread :: ID of Thread 1 = "<< thread_obj1.get_id() << std::endl;      
	std::cout << "From Main Thread :: ID of Thread 2 = " << thread_obj2.get_id() << std::endl;      

	thread_obj1.join();      
	thread_obj2.join();      
	return 0; 
}
