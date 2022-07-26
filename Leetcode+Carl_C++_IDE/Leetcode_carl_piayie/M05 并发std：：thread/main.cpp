#include<iostream>
#include<thread>

using namespace std;

void threadproc() {//线程函数
	while (1) {
		cout << "threadproc speaking! " << endl;
	}
}

void func() {
	thread t(threadproc);//t是线程对象，func结束时局部变量会被销毁
	t.detach();//detach⽅法，通过这个⽅法可以让线程对象与线程函数脱离关系，这样即使线程对象被销毁，也不影响线程函数的运⾏
}


int main() {
	func();
	while(1) {}
	return 0;
}