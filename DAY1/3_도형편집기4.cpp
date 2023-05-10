#include <iostream>
#include <vector>

// 5. OCP 원칙
// 기능 확장에 열려 있고(Open, 나중에 클래스가 추가되어도)
// 코드 수정에는 닫혀 있어야(Close, 기존 코드는 수정되지 않도록)
// 한다는 원칙(Principle)
// Open-Close Principle

// 객체지향 설계의 5대 원칙 : SRP, OCP, LSP, ISP, DIP
//							=> "SOLID" 라고 합니다.
// 다형성(가상함수)은 OCP 를 만족하는 좋은 코드 입니다.


class Shape
{
	int color;
public:

	void set_color(int c) { color = c; }


	virtual int get_area() { return 1; }

	virtual void draw() { std::cout << "draw Shape" << std::endl; }
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

class Triangle : public Shape
{
public:
	void draw() { std::cout << "draw Triangle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();	// 다형성(polymorphism)
						// 동일한 표현식이 상황(실제객체)에 따라
						// 다르게 동작하는 것

			// 객체지향 언어의 3대 특징 : 캡슐화, 상속, 다형성
		}
	}
}






