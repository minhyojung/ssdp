#include <iostream>

// 아래 코드에서 에러를 찾아 보세요

class Base
{
public:
	// 핵심 1. Base  에 디폴트 생성자가 없습니다
	Base(int a) { }
	~Base() {  }
};

class Derived : public Base
{
public:
	// 핵심 2. 기반 클래스에 디폴트 생성자 없을때
	// =>  사용자가 반드시 명시적으로 기반 클래스 디폴트 생성자 호출해야 합니다.
//	Derived() {}		// Derived()      : Base() {}
//	Derived(int a) { }  // Derived(int a) : Base() { }
	~Derived() {  }

	// 기반 클래스 생성자를 사용자가 명시적으로 호출!!
	Derived()      : Base(0) {}
	Derived(int n) : Base(n) {}
};

int main()
{

}









