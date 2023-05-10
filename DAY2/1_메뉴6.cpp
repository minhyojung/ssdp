#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class unsupportedOperation {};

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	virtual void command() = 0;

	// 아래 2개 메뉴는 팝업인 경우만 유효합니다.
	// => 기본 구현은 예외 발생.
	virtual void add_menu(BaseMenu* p) { throw unsupportedOperation(); }
	virtual BaseMenu* submenu(int idx) { throw unsupportedOperation(); }
};




class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id)
		: BaseMenu(title), id(id) {}

	void command()
	{
		std::cout << get_title() << " 메뉴 선택됨" << std::endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add_menu(BaseMenu* p)
	{
		v.push_back(p);
	}


	void command()
	{
		while (1)
		{
			system("cls");

			std::size_t sz = v.size();

			for (std::size_t i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}
			std::cout << sz + 1 << ". 종료" << std::endl;

			std::cout << "메뉴를 선택하세요 >> ";
			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1)
				continue;


			v[cmd - 1]->command();
		}

	}

	BaseMenu* submenu(int idx) { return v[idx]; }
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");

	root->add_menu(new PopupMenu("색상 변경"));
	root->add_menu(new MenuItem("절전모드", 11));

	root->submenu(0)->add_menu(new MenuItem("RED", 11)); // ok

	try
	{
		root->submenu(1)->add_menu(new MenuItem("RED", 11)); // 예외 발생
	}
	catch (...)
	{
		std::cout << "예외 발생" << std::endl;
	}

//	root->command(); 
}






// 출석부 서명해 주세요.

// github.com/codenuri/ssdp 에서

// DAY2.zip 과 server.zip 받아 두세요
