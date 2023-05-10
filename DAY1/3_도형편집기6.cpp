#include <iostream>
#include <vector>

// 9. template method 패턴
// => 변하지 않은 전체 흐름을 가진 함수 내부에
// => 변하는 것만 가상함수로 분리하는 디자인 기술




class Shape
{
	int color;
public:

	void set_color(int c) { color = c; }


	virtual int get_area() { return 1; }

	// 공통성과 가변성의 분리
	// => 변하지 않은 전체 흐름속에 숨은 변해야 하는코드를 찾는다.
	// => 변하는 것은 가상함수로 분리한다.

private: // 또는 protected
	virtual void draw_imp()
	{
		std::cout << "draw Shape" << std::endl;
	}

public:
	// 아래 함수를 "template method(틀을 가진 멤버함수)"라고 합니다.
	void draw() 
	{
		std::cout << "mutex lock" << std::endl;
		draw_imp();
		std::cout << "mutex unlock" << std::endl;
	}





	virtual Shape* clone()
	{
		Shape* p = new Shape;

		p->color = this->color;
		return p;
	}
};



class Rect : public Shape
{
public:
	void draw_imp() { std::cout << "draw Rect" << std::endl; }

	virtual Shape* clone()
	{
		return new Rect(*this); 
	}
};


class Circle : public Shape
{
public:
	void draw_imp() { std::cout << "draw Circle" << std::endl; }

	virtual Shape* clone()
	{
		return new Circle(*this);
	}
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
				p->draw();
		}

		else if (cmd == 8)
		{
			std::cout << "몇번째 만들었던 도형을 복사 할까요?";

			int k;
			std::cin >> k;

			v.push_back(v[k]->clone()); 
		}
	}
}






