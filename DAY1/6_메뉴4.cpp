#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

// 모든 메뉴의 공통의 기반 클래스
class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}

	virtual ~BaseMenu() {}

	std::string get_title() { return title; }

	virtual void command() = 0;
};



class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id)
		: BaseMenu(title), id(id) {}

	void command()
	{
		std::cout << get_title() << " 메뉴 선택\n";
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add_menu(BaseMenu* m) { v.push_back(m); }

	void command()
	{
		while (1)
		{
			system("cls");

			int sz = v.size();
			int i = 0;

			for (BaseMenu* p : v)
			{
				std::cout << ++i << ". " << p->get_title() << "\n";
			}
			std::cout << i + 1 << ". 종료\n";
			std::cout << "메뉴를 선택해 주세요 >> ";

			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1) 
				break;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			v[cmd - 1]->command(); 
		}
	}
};

int main()
{
	MenuItem m1("참치김밥", 11);
	MenuItem m2("소고기 김밥", 12);
	   	 
	PopupMenu kimbab("김밥류");
	kimbab.add_menu(&m1);
	kimbab.add_menu(&m2);

	MenuItem m5("라면", 21);

	PopupMenu pm("오늘의 메뉴");
	pm.add_menu(&kimbab);  // 핵심 : 팝업메뉴가 다시 팝업을 보관
	pm.add_menu(&m5);

	pm.command();
}
