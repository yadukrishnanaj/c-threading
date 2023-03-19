#include<iostream>
#include<thread>
#include<chrono>
void work() {

	for(int i=0;i<10;++i) {
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::cout<<"value::"<<i;
	}
}
int main() {

	std::thread t1(work);
	t1.join();

	return 0;
}



