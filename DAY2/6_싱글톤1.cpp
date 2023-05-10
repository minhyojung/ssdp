// 7_싱글톤1 - 123 page
#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하는 것.
//         어디서든지 동일한 방법으로 접근 가능한것

// => 결국 전역변수와 동일
// => 전역변수는 나쁜 코드로 취급되므로...
// => 싱글톤도 비판이 많습니다.


// Meyer's Singleton 
// => effective c++의 저자인 scott meyer 가 처음으로 제안한 코드
// => 유일한 한개의 객체가 static 지역변수인 모델
// => C++ 권장하는 모델

class Cursor
{
	// 규칙 1. private 생성자
private:
	Cursor() {}

	// 규칙 2. 복사 생성자와 대입연산자를 삭제 한다.
	Cursor(const Cursor&) = delete; // C++11 함수 삭제 문법
	Cursor& operator=(const Cursor&) = delete;

	// 규칙 3. 오직 한개의 객체를 만들어서 반환하는 static 멤버함수
public:
	static Cursor& get_instance()
	{
		static Cursor instance;

		return instance;
	}
};
int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();
	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

	Cursor c3 = c1; // 복사 생성도 막아야 합니다. 
//	Cursor c1, c2;
}








