#include<iostream>
#include<thread>
#include<future>
#include<tbb/tbb.h>
using namespace std;
double work() {

	return 3.14;
}

int main() {

	promise<double> a;

	auto func= [&](){

	        auto result = work();
		a.set_value(result);
	};

	thread t1(func);

	t1.join();

	future<double> f = a.get_future();
	std::cout<<f.get();
        return 0;
}

