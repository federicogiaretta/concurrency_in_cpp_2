#include <iostream>
#include <thread>
#include <chrono>

void tick(int n)
{
	for (int i=0; i!=n; ++i) {
		std::this_thread::sleep_for(std::chrono::seconds{1});
		std::cout << "Alive!\n";
	}
}

int main()
{
	std::thread timer{tick, 10};
	timer.join();
}
