#define USING_GUI
#include "cppmaster.h"


// Proxy 는 교체 가능해야 한다.
// 인터페이스를 먼저 설계
struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

class CalcProxy : public ICalc
{
	int server;
public:
	CalcProxy() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

int main()
{
	// Proxy 는 서버 제작자가 만들어서 배포하게 됩니다.

	// Client 제작시 아래 처럼 사용하면 "강한 결합" 이 됩니다.
	// Proxy 가 새롭게 배포되면 아래 코드는 수정되어야 합니다.
	// CalcProxy* c = new CalcProxy();


	// Client 가 Proxy 사용시 "약한 결합" 이어야 합니다.
	ICalc* c = new ? ? ? ;


	int n1 = c->Add(10, 20);
	int n2 = c->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





