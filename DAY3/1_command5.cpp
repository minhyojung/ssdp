// command4.cpp 추가해 보세요. 
// git 에 소스 있습니다. 복사해 오세요

#include <iostream>

struct ICommand
{
	virtual void execute() = 0;
	virtual bool can_undo() { return false; }
	virtual void undo() {}
	virtual ~ICommand() {}
};


class Dialog
{
public:
	void close() { std::cout << "Dialog close" << std::endl; }
};

// 전통적인 디자인 패턴에서 command 예제는 아래 코드 입니다.
class Button
{
	ICommand* cmd = nullptr;
public:
	void set_command(ICommand* p) { cmd = p; }

	void click() { cmd->execute(); }
};

// Dialog 를 닫는 명령
class DialogCloseCommand : public ICommand
{
	Dialog* dlg;
public:
	DialogCloseCommand(Dialog* dlg) : dlg(dlg) {}
	void execute() override { dlg->close(); }
};

int main()
{
	Dialog dlg;
	Button btn;
	btn.set_command( new DialogCloseCommand(&dlg));
	btn.click();
}
