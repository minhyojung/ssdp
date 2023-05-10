#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id)
		: title(title), id(id) {}

	std::string get_title() { return title; }

	void command()
	{
		std::cout << get_title() << " 메뉴 선택\n";
		_getch();
	}
};

class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& title) : title(title) {}

	void add_menu(MenuItem* m) { v.push_back(m); }

	// 아래 함수가 핵심 입니다.
	void command()
	{
		while (1)
		{
			system("cls");

			int sz = v.size();
			int i = 0;

			for (MenuItem* p : v)
			{
				std::cout << ++i << ". " << p->get_title() << "\n";
			}
			std::cout << i + 1 << ". 종료\n";
			std::cout << "메뉴를 선택해 주세요 >> ";

			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1) // 종료 선택
				break;

			if (cmd < 1 || cmd > sz + 1) // 잘못된 입력
				continue;

			v[cmd - 1]->command(); // 선택된 메뉴 실행
		}
	}
};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);
	
	PopupMenu pm("오늘의 메뉴");
	pm.add_menu(&m1);
	pm.add_menu(&m2);

	pm.command(); // 팝업메뉴 선택시 해야할 일을 생각해보세요.
				// 1. 김밥
				// 2. 라면
				// 3. 종료
				// 메뉴를 선택하세요 >> 
}
