#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}

	virtual Shape* clone() = 0;
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }

	Shape* clone() override { return new Rect(*this); }
};



class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }

	Shape* clone() override { return new Circle(*this); }
};



class Factory
{
	MAKE_SINGLETON(Factory)

	std::map<int, Shape*> prototype_map;

public:
	void register_shape(int type, Shape* sample)
	{
		prototype_map[type] = sample;
	}

	Shape* create(int type)
	{
		Shape* p = nullptr;

		auto ret = prototype_map.find(type);

		if (ret != prototype_map.end())
		{
			p = ret->second->clone(); // prototype 패턴의 핵심
										// 견본을 보관했다가
										// 복사를 통한 객체의 생성
		}
		return p;
	}
};

int main()
{
	std::vector<Shape*> v;

	Factory& factory = Factory::get_instance();
		
	// 아래 코드는 공장에 "클래스" 를 등록하는 의미 입니다.
	//factory.register_shape(1, &Rect::create);
	//factory.register_shape(2, &Circle::create);

	// 공장에 자주 사용하는 "객체의 견본"을 등록해 봅시다.
	Rect* redRect = new Rect; // 빨간색 크기 10이라고 가정
	Rect* blueRect = new Rect;
	Circle* blueCircle = new Circle;
	
	factory.register_shape(1, redRect);
	factory.register_shape(2, blueRect);
	factory.register_shape(3, blueCircle);

	// 아래 함수도 구현해 보세요
//	factory.show_sample(); // 등록된 모든 견본을 화면에 보여준다


	while (1)
	{
		int cmd;
		std::cin >> cmd;


		if (cmd > 0 && cmd < 8)
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




