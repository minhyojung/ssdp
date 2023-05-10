#include <iostream>

// 방법 3. 변하는 것을 다른 클래스로!!
// => 그런데, 인터페이스 기반의 교체가 아닌
// => 템플릿 인자로 교체!

// 정책 클래스를 교체하는 2가지 방법
// 1. 인터페이스 설계해서 교체
// => 실행시간 정책 교체 가능..
// => 하지만, 가상함수 기반이므로 느리다.
// => strategy pattern ( 23개 패턴에 포함)

// 2. 템플릿 인자로 교체가능
// => 인라인 치환도 가능. 빠르다.
// => 실행시간 교체 안됨.
// => "policy base design"



template<typename T, typename ThreadModel = nolock> class list
{
	ThreadModel tm; // 동기화 정책을 담당할 정책 클래스
public:
	void push_front(const T& a)
	{
		tm.lock();
		// .... 앞에 삽입하는 코드
		tm.unlock();
	}
};

// 동기화 정책을 담은 정책 클래스
class nolock
{
public:
	inline void lock() {}
	inline void nolock() {}
};
class mutex_lock
{
	// pthread_mutex_t mtx;
public:
	inline void lock()   { std::cout << "mutex lock" << std::endl; }
	inline void nolock() { std::cout << "mutex unlock" << std::endl; }
};
//---------------------------------------
//list<int, mutex_lock> s;
list<int, nolock> s;

int main()
{
	s.push_front(10);
}
