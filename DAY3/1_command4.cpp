// command4.cpp 추가해 보세요. 
// git 에 소스 있습니다. 복사해 오세요


#include <iostream>

class Dialog
{
public:
	void close() { std::cout << "Dialog close" << std::endl; }
};

// 아래 코드는 버튼을 눌렀을때 항상 "Dialog 를 닫는 일"만 합니다.
// => 다른 작업을 하려면 코드를 수정해야 합니다.
class Button
{
	Dialog* dlg;
public:
	void set_dialog(Dialog* p) { dlg = p; }
	void click() { dlg->close(); }
};

int main()
{
	Dialog dlg;
	Button btn;
	btn.set_dialog(&dlg);
	btn.click();
}
