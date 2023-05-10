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
	ICalc* c = load_proxy(); // DLL 의 create() 호출
							 // create 에서 "new" 로 proxy 생성
							// delete 해야 하지 않을까요 ?

	int n1 = c->Add(10, 20);
	
	delete c; // 이렇게 해도 될까요 ?

}





