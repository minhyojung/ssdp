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

// 임의 타입의 멤버 함수를 호출하는 명령
template<typename T>
class MemberCallCommand : public ICommand
{
	T* target;		   // 대상 객체
	void(T::*action)();// 대상 멤버 함수 
public:
	MemberCallCommand(T* target, void(T::*action)() ) 
		: target(target), action(action) {}

	void execute() override
	{
		(target->*action)(); // "멤버 함수 포인터" 개념!
	}
};
// 위코드가 아이폰 개발에서 사용되는 "target-action패턴"
int main()
{
	Dialog dlg;
	Button btn;
	btn.set_command(new MemberCallCommand<Dialog>(&dlg, &Dialog::close));
	btn.click();
}
