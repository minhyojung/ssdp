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







