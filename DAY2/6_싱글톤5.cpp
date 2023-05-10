// 7_싱글톤1 - 123 page
#include <iostream>
#include <mutex>

// 자원 관리는 항상 생성자/소멸자에 의존해야 합니다.
template<typename T> class lock_guard
{
	T& m;
public:
	lock_guard(T& m) : m(m) { m.lock(); }
	~lock_guard()           { m.unlock(); }
};



class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	inline static Cursor* instance;
	inline static std::mutex mtx;
public:

	static Cursor& get_instance()
	{
		{
			std::lock_guard<std::mutex> g(mtx);
			//lock_guard<std::mutex> g(mtx); // 생성자에서 mtx.lock()
										   // 소멸자에서 mtx.unlock()
	//		mtx.lock();
			if (instance == nullptr)
			{
				instance = new Cursor;
			}
			//		mtx.unlock();
		}

		return *instance;
	}
};



int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

}








