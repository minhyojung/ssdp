#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

// 객체지향 프로그래밍 세계에서 프로그램은
// => 객체의 집합
// => 모든 것은 객체이다.

// 모든 것을 타입(클래스)으로 설계
class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id)
		: title(title), id(id) {}

	std::string get_title() { return title; }

	// 메뉴 선택시 호출되는 함수
	void command()
	{
		std::cout << get_title() << " 메뉴 선택\n";
		_getch();
	}
};
int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);
	m1.command();
}
