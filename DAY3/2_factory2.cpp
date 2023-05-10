#include <iostream>
#include <vector>
#include <map>
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

	// 자신을 만들수 있는 static 멤버 함수는 아주 유용합니다.
	static Shape* create() { return new Rect; }
};

// Rect 를 만드는 2가지 방법
// 1. Rect* p = new Rect;
// 2. Rect* p = Rect::create();

// C++ 은 "클래스"을 컨테이너(vector, map등)에 보관할수 없습니다.
// v.push_back("Rect"); 클래스 보관이 아닌 문자열 보관입니다.
//						"Rect" 문자열로 Rect 객체 생성안됩니다.

// 하지만, 객체를 만드는 함수는 등록할수 있습니다.
// v.push_back(&Rect::create)	이정보로 Rect 만들수 있습니다.



class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
};


class Factory
{
	MAKE_SINGLETON(Factory)

	typedef Shape*(*F)();

	std::map<int, F> create_map;

public:
	void register_shape(int type, F f)
	{
		create_map[type] = f;
	}
	
	Shape* create(int type)
	{
		Shape* p = nullptr;

		auto ret = create_map.find(type);

		if (ret != create_map.end())
		{
			p = ret->second(); // ret->second 가 등록된 함수
		}
		return p;
	}
};

int main()
{
	std::vector<Shape*> v;

	Factory& factory = Factory::get_instance();

	// 공장에 제품을 등록하고 사용합니다.
	factory.register_shape(1, &Rect::create);
	factory.register_shape(2, &Circle::create);


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




