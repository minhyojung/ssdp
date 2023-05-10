// 7_싱글톤1 - 123 page
#include <iostream>
#include <thread>
#include <chrono>
using namespace std::literals;

class Cursor
{
private:
	Cursor() 
	{
		std::cout << "start Cursor() " << std::this_thread::get_id() << std::endl;
		std::this_thread::sleep_for(5s); // 5초 지연
		std::cout << "finish Cursor()" << std::endl;
	}



	Cursor(const Cursor&) = delete; // C++11 함수 삭제 문법
	Cursor& operator=(const Cursor&) = delete;

public:
	static Cursor& get_instance()
	{
		std::cout << "start " << std::this_thread::get_id() << std::endl;
		static Cursor instance;
		std::cout << "finish " << std::this_thread::get_id() << std::endl;

		return instance;
	}
};
int main()
{
	std::thread t1(&Cursor::get_instance);
	std::thread t2(&Cursor::get_instance);

	t1.join();
	t2.join();
}



// 디자인 패턴 : 모든 객체지향 언어로 구현 가능한 디자인 기술
// IDioms     : 특정 언어에 대한 코딩 기술
// ( C++ IDioms, Java IDioms 등)

// 구글에서 "C++ IDioms" 검색후 1번째 링크




