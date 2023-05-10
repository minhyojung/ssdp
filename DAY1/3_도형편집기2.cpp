#include <iostream>
#include <vector>


class Shape
{
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v; 

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if      (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto p : v) // Shape* 타입
				p->draw();	 // Shape 타입에는 draw 가 없다.
		}
	}
}
// 위 코드는 왜 에러일까요??
// 해결책은 뭘까요 ?
// 1. Shape* 타입인 p를 Rect 나 Circle 로 캐스팅 해서 사용하자
// 2. Shape 안에도 draw를 만들자.





