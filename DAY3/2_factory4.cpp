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


#define REGISTER( classname )							\
	static Shape* create() { return new classname; }	\
	static AutoRegister ar;

#define REGISTER_IMPL(key, classname)	\
AutoRegister classname::ar(key, &classname::create);

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	REGISTER(Rect)
};
REGISTER_IMPL(1, Rect)


class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	REGISTER(Circle)
};
REGISTER_IMPL(2, Circle)

class Triangle : public Shape
{
public:
	void draw() override { std::cout << "draw Triangle" << std::endl; }

	REGISTER(Triangle)
};
REGISTER_IMPL(3, Triangle)


int main()
{
	std::vector<Shape*> v;

	Factory& factory = Factory::get_instance();



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




