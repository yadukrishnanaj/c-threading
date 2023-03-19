#include<iostream>
#include<thread>
#include<chrono>

using namespace std;
/*void work() {


	for(int i=0;i<10;++i) {

	        this_thread::sleep_for(chrono::milliseconds(500));
		cout<<"loop"<<i<<endl;
	}
}*/

int main() {

	int count =0;
	const int iterations = 1000;
	mutex mtx;
	auto func = [&](){
			for(int i =0;i<iterations;++i) {
	                mtx.lock();
			++count;
			mtx.unlock();
			}
			};
        thread t1(func);
	thread t2(func);
	t1.join();
	t2.join();
	cout<<count<<endl;
	return 0;
}
