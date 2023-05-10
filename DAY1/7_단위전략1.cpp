// 7_단위전략1 - 36page

#include <iostream>

template<typename T> class list
{
	// member data....
public:
	void push_front(const T& a)
	{
		// mutex.lock()
		//....
		// mutex.unlock()
	}
};

list<int> s; // 전역변수.. 멀티 스레드에 안전하지 않습니다.

int main()
{
	s.push_front(10);
}
