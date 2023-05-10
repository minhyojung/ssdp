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

// 새로운 도형이 추가되면 "공장의 코드"는 수정되어야 합니다.
// => 하지만, 공장 한곳만 수정하면 되므로
// => 코드 수정을 최소화 할수 있습니다.
class Factory
{
	MAKE_SINGLETON(Factory)
public:
	Shape* create(int type)
	{
		Shape* p = nullptr;

		switch (type)
		{
		case 1: p = new Rect; break;
		case 2: p = new Circle; break;
		}
		return p;
	}
};

int main()
{
	std::vector<Shape*> v;

	Factory& factory = Factory::get_instance();

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		
		if (cmd > 0 && cmd < 8) // 1 ~ 7 을 도형 번호로 예약
		{
			Shape* p = factory.create(cmd);

			if (p)
				v.push_back(p);
		}


		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();
			}
		}
	}
}




