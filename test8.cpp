#include<iostream>
#include<thread>
#include<queue>
using namespace std;
template<typename T>
class blocking_queue
{

	private:
		int _max_size;
		queue<T> _queue;
		mutex _mtx;
		conditional_variable _cond;
	public:
		blocking_queue(int max_size) {
			_max_size = max_size;
		}
		void push (T e) 
			{
				unique_lock<mutex> lock(_mtx);
				cout<<"push"<<endl;
				_queue.push(e);
			}


		void pop() {
			unique_lock<mutex> lock(_mtx);
			cout<<"pop"<<endl;
			_queue.pop();

		}

};

int main() {
	blocking_queue<int> qu(3);;
	   thread t1([&](){
        for(int i = 0; i < 10; i++)
        {
            cout << "pushing " << i << endl;
            qu.push(i);
        }
    });

    thread t2([&](){
        for(int i = 0; i < 10; i++)
        {
            qu.pop();
        }
    });
	t1.join();
	t2.join();
	return 0;
}

  

