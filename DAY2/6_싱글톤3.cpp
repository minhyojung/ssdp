// 7_싱글톤1 - 123 page
#include <iostream>
#include <mutex>

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	// C++17 inline static 문법 : static 멤버 데이타의 외부 선언 필요 없음
	inline static Cursor* instance;
	inline static std::mutex mtx;
public:
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
};



int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

}








