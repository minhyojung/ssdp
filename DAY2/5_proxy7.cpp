#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

ICalc* load_proxy()
{
	void* addr = ec_load_module("CalcProxy.dll");
	typedef ICalc*(*F)();

	F f = (F)ec_get_function_address(addr, "create");

	std::cout << addr << ", " << f << std::endl;

	return f();
}


// raw pointer 를 대신하는 proxy 를 만들어 봅시다.
// "스마트 포인터" 도 결국 raw pointer 에 대한 대행자 proxy 입니다

template<typename T>
class sp
{
	T* obj;
public:
	sp(T* p = nullptr)  : obj(p)         { if (obj) obj->AddRef();  }
	sp(const sp& other) : obj(other.obj) { if (obj) obj->AddRef(); }

	~sp() { if (obj) obj->Release(); }

	// 스마트포인터의 핵심 : -> 와 * 연산자를 재정의해서 raw pointer 처럼 보이게
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

int main()
{
	sp<ICalc> c1 = load_proxy(); // sp<ICalc> c1( load_proxy() ) 처럼생각하세요
	sp<ICalc> c2 = c1;

	// c1, c2는 객체지만 포인터 역활을 할수 있어야 합니다.
	int n1 = c1->Add(10, 20);
	int n2 = (*c1).Add(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;
}

/*


int main()
{
	ICalc* c1 = load_proxy();


	c1->AddRef();  // 규칙 1. Proxy 를 처음 만들때 참조계수증가

	ICalc* c2 = c1;
	c2->AddRef();  // 규칙 2. Proxy 포인터 복사시 참조계수증가

	c2->Release(); // 규칙 3. 포인터가 더이상 필요없으면 참조계수 감사


	std::cout << "-----" << std::endl;
	c1->Release();
	std::cout << "-----" << std::endl;

}







*/

// shared_ptr 을 사용하면 안되나요 ?
#include <memory>

void foo()
{
	std::shared_ptr<int> sp1(new int); // sp1의 소멸자가 "delete" 합니다

	std::shared_ptr<ICalc> sp2(load_proxy() );
						// 버그.. 우리가 원하는 것은 delete가 아닙니다.
						// Release() 를 호출해서 DLL 내에서 delete 되어야합니다

	sp<ICalc> sp3(load_proxy()); // ok.. 소멸자에서 Release() 호출
}
