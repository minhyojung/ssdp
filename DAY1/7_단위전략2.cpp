#include <iostream>

// 방법 1. 변하는 것을 가상함수로!! -- template method
// => 동기화 코드의 재사용성이 없다.
// => vector, set, map 등도 모두 아래처럼 하면 코드의 중복이 너무 많다

template<typename T> class list
{
public:
	void push_front(const T& a)
	{
		lock();
		// .... 앞에 삽입하는 코드
		unlock();
	}
	virtual void lock() {}
	virtual void unlock() {}
};
// 동기화 하고 싶다면 list 파생 클래스를 만들어서 lock()/unlock()재정의!



list<int> s; 

int main()
{
	s.push_front(10);
}
