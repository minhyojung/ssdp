#include <iostream>
#include <vector>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};

// UNDO/REDO 기능을 만들어 봅시다.
// C언어 : 주어진 기능을 수행하는 함수를 작성
// C++언어 : 주어진 기능을 수행하는 객체로 작성
// => 명령의 캡슐화

struct ICommand
{
	virtual void execute() = 0;
	virtual bool can_undo() { return false; }
	virtual void undo() {}
	virtual ~ICommand() {}
};

// 사각형을 추가하는 명령
class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}
	void execute() override { v.push_back(new Rect); }
	bool can_undo() override { return true; }

	void undo() override
	{
		Shape* p = v.back();
		v.pop_back();
		delete p;
	}
};

class AddCircleCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCircleCommand(std::vector<Shape*>& v) : v(v) {}
	void execute() override { v.push_back(new Circle); }
	bool can_undo() override { return true; }

	void undo() override
	{
		Shape* p = v.back();
		v.pop_back();
		delete p;
	}
};
class DrawCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}
	void execute() override 
	{ 
		for (auto p : v) p->draw();
	}
	bool can_undo() override { return true; }

	void undo() override
	{
		system("cls");
	}
};

#include <stack>

int main()
{
	std::vector<Shape*> v;

	std::stack<ICommand*> cmd_stack;
	ICommand* pcmd = nullptr;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			pcmd = new AddRectCommand(v);
			pcmd->execute();
			cmd_stack.push(pcmd);
		}
		else if (cmd == 2)
		{
			pcmd = new AddCircleCommand(v);
			pcmd->execute();
			cmd_stack.push(pcmd);
		}
		else if (cmd == 9)
		{
			pcmd = new DrawCommand(v);
			pcmd->execute();
			cmd_stack.push(pcmd);
		}
		else if (cmd == 0)
		{
			if (!cmd_stack.empty())
			{
				pcmd = cmd_stack.top();
				cmd_stack.pop();

				if (pcmd->can_undo())
				{
					pcmd->undo();
				}

				delete pcmd; // REDO 도 지원 하려면
							 // delete 하지 말고, redo_stack.push(pcmd)
			}
		}
	}
}




