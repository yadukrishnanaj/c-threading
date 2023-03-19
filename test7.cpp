#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

class App {

	private:
		int count =0;
		mutex mt;
        public:
		void operator()() {
			for(int i=0;i<1000;++i) {

		lock_guard<mutex> guard(mt);
		++count;
			}
		
		}
		void display() {
			cout<<count;
		}
};


int main() {

        App app;
	thread t1(ref(app));
	thread t2(ref(app));
	t1.join();
	t2.join();
	app.display();
	return 0;
}
