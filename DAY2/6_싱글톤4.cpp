// 7_싱글톤1 - 123 page
#include <iostream>
#include <mutex>

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	inline static Cursor* instance;
	inline static std::mutex mtx;
public:
	// 아래 함수가 100번 호출된다고 생각해 보세요
	// 최초 호출 : 객체 생성
	// 이후 99번 : 객체 생성 안함. 만들어진 것을 반환만
	//			  하지만 이경우도 lock/unlock 하므로 성능저하
	/*
	static Cursor& get_instance()
	{
		mtx.lock();
		if (instance == nullptr)
		{
			instance = new Cursor;
		}
		mtx.unlock();

		return *instance;
	}
	*/
	static Cursor& get_instance()
	{
		// 최초 호출 : if 문을 2번 사용하는 오버헤드 있습니다.
		// 나머지 99번 : lock/unlock 안함..

		// 아래 코드를 "DCLP(Double Check Locking Pattern)" 입니다.
		// => 2004 년에 절대 사용하지말라는 논문이 나옵니다.
		// => C++ 뿐 아니라 java도 사용하지 마세요.
		if (instance == nullptr)
		{
			mtx.lock();
			if (instance == nullptr)
			{
				instance = new Cursor;

				// 위 한줄은 아래 3줄처럼 동작
				// 1. Cursor 메모리 할당 : temp = malloc(sizeof(Cursor))
				// 2. 생성자 호출        : Cursor::Cursor()

				// 3. (1)의 메모리 주소를 instance 에 넣기 : instance = temp

				// 위 코드가 컴파일러 최적화에 의해서 아래 코드로 변경
				// 1. instance = malloc(sizeof(Cursor))
				// 2. Cursor::Cursor()
			}
			mtx.unlock();
		}

		return *instance;
	}
};



int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

}








