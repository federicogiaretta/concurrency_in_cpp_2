// Wallet.h
#ifndef Wallet_h
#define Wallet_h

#include <mutex>

class Wallet
{
public:
    Wallet();
    int get_money() const;
	void set_money(int value);
    void add_money(int money);
private:
    int money_;
    std::mutex mutex_;
};

#endif