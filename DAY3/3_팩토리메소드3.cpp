// 5_팩토리메소드
#include <iostream>

// 모든 종류의 컨트롤은 공통의 기반 클래스 필요
struct IButton
{
	virtual void Draw() = 0;
	virtual ~IButton() {}
};
struct IEdit
{
	virtual void Draw() = 0;
	virtual ~IEdit() {}
};


struct WinButton : public IButton
{
	void Draw() { std::cout << "Draw WinButton" << std::endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { std::cout << "Draw WinEdit" << std::endl; }
};

struct OSXButton : public IButton
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
//--------------------------------------

// C++ 에서는 factory method 대신 template 을 많이 사용합니다.

// 컨트롤의 이름만 가진 구조체
struct Windows
{
	using Button = WinButton; // typedef WinButton Button 과 동일
	using Edit   = WinEdit;
};

struct OSX
{
	using Button = OSXButton;
	using Edit = OSXEdit;
};

// cppcon
template<typename T>
class Dialog
{
public:
	void init()
	{
		IButton* btn = new typename T::Button;
		IEdit*  edit = new typename T::Edit;
		btn->Draw();
		edit->Draw();
	}	
};

int main(int argc, char** argv)
{
	Dialog<OSX>     dlg1;
	Dialog<Windows> dlg2;
	dlg2.init();
}








