// Wallet.cpp
#include <mutex>

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
	mutex_.lock();
	for(int i = 0; i < money; ++i) 
		++money_;
	mutex_.unlock();
}