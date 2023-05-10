#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


// list 복합객체 : 모든 요소의 타입이 동일하다.
// PopupMenu    : 모든 요소의 타입이 동일하지는 않다.
//				  요소가 다시 복합객체일수도 있다.

// 메뉴 방문자의 인터페이스
class MenuItem;
class PopupMenu;

struct IMenuVisitor
{
	virtual void visit(MenuItem* e) = 0;
	virtual void visit(PopupMenu* e) = 0;
//	virtual void visit(SpecialMenu* e) = 0;
	virtual ~IMenuVisitor() {}
};

struct IAcceptor
{
	virtual void accept(IMenuVisitor* visitor) = 0;
	virtual ~IAcceptor() {}
};
//----------------------------
// 모든 메뉴는 방문자를 받을수 있어야 한다.
class BaseMenu : public IAcceptor
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	void set_title(const std::string& t) { title = t; }

	std::string get_title() const { return title; }

	virtual void command() = 0;
};


class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void accept(IMenuVisitor* visitor) override
	{
		visitor->visit(this); 
	}



	void command() override
	{
		std::cout << get_title() << " 메뉴가 선택됨" << std::endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	// 방문자가 팝업메뉴에 도착했을때
	void accept(IMenuVisitor* visitor) override
	{
		visitor->visit(this); // 자신을 먼저 방문자에게 전달..

		for (auto e : v)
			//	visitor->visit(e);
			e->accept(visitor); // 이렇게 해야 e의 하위까지 다시 전달됩니다
	}







	void add_menu(BaseMenu* p) { v.push_back(p); }

	void command() override
	{
		while (1)
		{
			system("cls");

			int sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}

			std::cout << sz + 1 << ". 종료" << std::endl;

			int cmd;
			std::cout << "메뉴를 선택하세요 >> ";
			std::cin >> cmd;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			if (cmd == sz + 1)
				break;

			v[cmd - 1]->command(); 
		}

	}

};

// 이제 메뉴 시스템은 "다양한 방문자"를 받을수 있습니다.
// 다양한 기능의 방문자를 제공하면 됩니다.

class PopupMenuTitleChangeVisitor : public IMenuVisitor
{
public:
	void visit(MenuItem* m)  override
	{
		auto s = m->get_title();
		s = "**" + s + "**";
		m->set_title(s);
	}
	void visit(PopupMenu* m) override
	{
		auto s = m->get_title();

		s = "[ " + s + " ]";

		m->set_title(s);		
	}
};





int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("해상도 변경");
	PopupMenu* pm2 = new PopupMenu("색상 변경");

	root->add_menu(pm1);
	root->add_menu(pm2);

	pm1->add_menu(new MenuItem("HD", 11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));

	pm2->add_menu(new MenuItem("RED", 21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE", 23));

	
	// 팝업메뉴의 타이틀만 변경하는 방문자
	PopupMenuTitleChangeVisitor pmtcv;
	root->accept(&pmtcv); 


	root->command();

}




