// race_condition.cpp

#include <iostream>
using std::cout;
using std::endl;
#include <thread>
using std::thread;
#include <vector>
using std::vector;

#include "Wallet.h"

Wallet my_wallet;

void workers_work(int amount)
{
   my_wallet.add_money(amount); 
}
 
int test_multithreaded_wallet(int no_of_workers, int amount)  
{
   my_wallet.set_money(0);

	std::vector<std::thread> threads;
	for(int i=0; i<no_of_workers; i++)
		threads.push_back( std::thread{workers_work, amount });
   
	vector<thread>::iterator worker;
	for (worker=threads.begin(); worker != threads.end(); ++worker)
		worker->join();

      
   return my_wallet.get_money();
}

int main()  
{
   const int no_of_workers{10};
   const int amount{5000};
   const int no_of_test{1000};

   int val{0};
   for(int k = 0; k < no_of_test; k++)
      if((val = test_multithreaded_wallet(no_of_workers, amount)) != (no_of_workers*amount) )
         cout << "Error at test no.:" << k << " Money in Wallet = " << val << endl;


   cout << "Exiting from Main Thread" << endl;
   return 0;
}


 