#include <iostream>
#include <vector>


class Shape
{
	int color;
public:

	void set_color(int c) { color = c; }

	virtual int get_area() { return 1; }


private: 
	virtual void draw_imp()
	{
		std::cout << "draw Shape" << std::endl;
	}

public:
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

		// 생각해 볼 문제 1. 객체의 생성을 OCP를 만족하게 할수 없을까 ?
		// => 추상 팩토리 패턴을 사용!! (수요일)

		// 2. Undo/Redo 기능을 넣으려면 어떻게 할까 ?
		// => Command 패턴을 알면 됩니다.(수요일)
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






