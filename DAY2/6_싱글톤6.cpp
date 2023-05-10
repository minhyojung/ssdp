#include <iostream>
#include <mutex>


// CRTP( Curiosly Recurring Template Pattern )
// => 기반 클래스에서 파생 클래스 이름을 사용할수 있게 하는 기술
// => 파생 클래스 만들때 자신의 이름을 기반 클래스 템플릿 인자로 전달하는 원리


// github.com/aosp-mirror       "Android Open Source Project"

// platform system core  "레포지토리 선택"

// libutils/include/utils   에서 "Singleton.h" 열어 보세요


template<typename T>
class Singleton
{
protected:
	Singleton() {}

private:
	
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	inline static T* instance;    // <===
	inline static std::mutex mtx;
public:
	static T& get_instance()  // <===
	{
		std::lock_guard<std::mutex> g(mtx);
		if (instance == nullptr)
		{
			instance = new T; // <<===
		}
		return *instance;
	}
};

// Mouse 도 위와 같은 싱글톤으로 하고 싶다
class Mouse : public Singleton< Mouse >
{

};

int main()
{
	Mouse& c1 = Mouse::get_instance();
}








