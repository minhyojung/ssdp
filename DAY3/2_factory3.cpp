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
			p = ret->second();
		}
		return p;
	}
};

class AutoRegister
{
public:
	AutoRegister(int type, Shape*(*f)())
	{
		Factory::get_instance().register_shape(type, f);
	}
};

// 전역변수 생성자가 호출되는 시점을 생각해 보세요
//AutoRegister ar(1, &Rect::create);


class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }

	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::create);




class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
	static AutoRegister ar;
};
AutoRegister Circle::ar(2, &Circle::create);



int main()
{
	std::vector<Shape*> v;

	Factory& factory = Factory::get_instance();

	// 공장에 제품을 등록하고 사용합니다.
	//factory.register_shape(1, &Rect::create);
	//factory.register_shape(2, &Circle::create);


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




