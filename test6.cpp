#include<iostream>
#include<thread>
#include<chrono>

using namespace std;
void work(int &count, mutex &mt) {


	for(int i=0;i<1000;++i) {

		lock_guard<mutex> guard(mt);
		++count;

	}
}

int main() {

	int count =0;
	mutex mt;
        thread t1(work,ref(count),ref(mt));
	thread t2(work,ref(count),ref(mt));
	t1.join();
	t2.join();
	cout<<count<<endl;
	return 0;
}
