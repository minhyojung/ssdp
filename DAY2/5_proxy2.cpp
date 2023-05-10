#define USING_GUI
#include "cppmaster.h"


// Proxy : 다양한 목적으로 기존 요소의 대행자를 만드는 패턴

// Remote Proxy : 원격지 객체에 대한 지역 객체

// 아래 proxy 는 서버 제작자가 만들어서 Client 제작자에게 배포하게 됩니다.
class CalcProxy
{
	int server;
public:
	CalcProxy() { server = ec_find_server("Calc");   }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b);}
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b);}
};

int main()
{
	CalcProxy* c = new CalcProxy();

	int n1 = c->Add(10, 20);
	int n2 = c->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





