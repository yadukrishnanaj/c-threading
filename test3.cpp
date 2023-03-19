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

	atomic<int> count =0;
	const int iterations = 1000;
	thread t1([&count](){
			for(int i =0;i<iterations;++i) {
			++count;
			}
			});
        thread t2([&count](){
			for(int i =0;i<iterations;++i) {
			++count;
			}
			});

	t1.join();
	t2.join();
	cout<<count<<endl;
	return 0;
}
