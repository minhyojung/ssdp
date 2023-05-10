#define USING_GUI
#include "cppmaster.h"


// Client 제작자는 Server 제작자에게 Proxy 관련 2개의 파일을 받아야합니다.
// ICalc.h       : 인터페이스가 담긴 헤더
// CalcProxy.dll : Proxy 가 담긴 동적 모듈

#include "ICalc.h"

ICalc* load_proxy()
{
	// 1. dll load
	// => 핵심 : 새로운  Proxy가 배포 되어도 "동적 모듈(DLL)이름"은 동일해야 합니다
	void* addr = ec_load_module("CalcProxy.dll"); // DLL load
						// Win   : LoadLibrary()
						// linux : dlopen()

	typedef ICalc*(*F)();

	// 2. dll에서 약속된 함수 찾기
	F f = (F)ec_get_function_address(addr, "create");
					// Win   : GetProcAddress()
					// linux : dlsym()

	std::cout << addr << ", " << f << std::endl;

	// 3. 약속된 함수로 proxy 객체 생성후 반환
	return f();
}

int main()
{
	ICalc* c = load_proxy();

	int n1 = c->Add(10, 20);
	int n2 = c->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





