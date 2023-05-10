#include <iostream>

class Base
{
public:
	Base()      { std::cout << "Base()" << std::endl; }
	Base(int a) { std::cout << "Base(int)" << std::endl; }
	~Base()     { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:
	// 사용자 코드		// 컴파일러가 변경한 코드
	Derived() 			// Derived() : Base()		
	{ 
		std::cout << "Derived()" << std::endl; 
	}
	Derived(int a)		// Derived(int a) : Base()
	{
		std::cout << "Derived(int)" << std::endl; 
	}
	~Derived()		
	{
		std::cout << "~Derived()" << std::endl; 

		// ~Base(); // 컴파일러가 추가한 코드
	}
};
int main()
{
//	Derived d1;
	Derived d2(5); // call Derived::Derived(int)
}










// 컴파일 + 실행 : Ctrl + F5





