
#include <iostream>
#include <functional> // C++11 부터 사용가능한 std::function<>

class Dialog
{
public:
	void close() { std::cout << "Dialog close" << std::endl; }
};


class Button
{
	std::function<void()> cmd; // void() 모양의 모든 함수를 담는 범용적
								// 함수 포인터
public:
	void set_command(std::function<void()> p) { cmd = p; }

	void click() { cmd(); }
};
int main()
{
	Dialog dlg;
	Button btn;

	// 멤버 함수를 호출하려면 반드시 객체(dlg)가 있어야 합니다.
//	btn.set_command(&일반함수); // ok
//	btn.set_command(&Dialog::close); // error. 멤버 함수는 객체가 필요
	btn.set_command( std::bind(&Dialog::close, &dlg) );
	btn.click();
}
