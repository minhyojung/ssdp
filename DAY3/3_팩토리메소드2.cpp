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

class Dialog
{
public:
	void init()
	{
		IButton* btn = create_button();
		IEdit*  edit = create_edit();

		// btn->Move(); edit->Move();
		btn->Draw();
		edit->Draw();
	}
	// factory method
	virtual IButton* create_button() = 0;
	virtual IEdit*   create_edit() = 0;
};


// Style 옵션과 상관없이 항상 Windows 모양의 Dialog

class WinDialog : public Dialog
{
public:
	IButton* create_button() override { return new WinButton; }
	IEdit*   create_edit()   override { return new WinEdit; }
};
class OSXDialog : public Dialog
{
public:
	IButton* create_button() override { return new OSXButton; }
	IEdit*   create_edit()   override { return new OSXEdit; }
};

int main(int argc, char** argv)
{

}








