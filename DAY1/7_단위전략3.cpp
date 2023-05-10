#include <iostream>

// 방법 2. 변하는 것을 다른 클래스로!!
// => strategy pattern
// => 동기화 정책을 담은 정책 클래스 설계
// => 동기화 정책을 다양한 컨테이너에서 모두 사용가능
//    앞의 template method 보다는 좋다...

// 그런데...

// 디자인 패턴의 장점 : 유연하고, 확장성있고, 유지보수가 쉽다
//              단점 : 메모리 사용량 증가하고, 느리다.
//						(가상함수가 주된 원인!!)

struct ILock
{
	virtual void lock() = 0;
	virtual void unlock() = 0;
	virtual ~ILock() {}
};

template<typename T> class list
{
	ILock* plock = nullptr;
public:
	void set_lock(ILock* p) { plock = p; }

	void push_front(const T& a)
	{
		if (plock) plock->lock();
		// .... 앞에 삽입하는 코드
		if (plock) plock->unlock();
	}
};

// 이제 ILock 으로 부터 파생된 다양한 동기화 정책을 만들면 됩니다


list<int> s;

int main()
{
	s.push_front(10);
}
