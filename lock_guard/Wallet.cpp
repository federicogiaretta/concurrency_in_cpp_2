// Wallet.cpp
#include <thread>
#include <mutex>
using std::mutex;
#include "Wallet.h"


Wallet::Wallet() 
:money_(0)
{}

int Wallet::get_money() const
{ 
	return money_; 
}

void Wallet::set_money(int value) 
{ 
	money_ = value; 
}

void Wallet::add_money(int money)
{
	// we create a lock_guard and when
	// the constructor is called, it is also
	// locked
	std::lock_guard<mutex> lock_guard_money(mutex_);

    for(int i = 0; i < money; ++i) {
		// if some error occurs at this
		// point then destructor of lock_guard_money
		// will be called that will unlock the mutex
    	++money_;
	}

	// once function exits, then destructor
	// of lock_guard_money will be called
	// in destructor it unlocks the mutex
	
}