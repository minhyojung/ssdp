#include <iostream>
#include <vector>


class not_implemented {};

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	void draw()
	{
		std::cout << "mutex lock" << std::endl;
		draw_imp();
		std::cout << "mutex unlock" << std::endl;
	}




private:

	// 가상함수     : 파생클래스가 재정의 하지 않으면 기본 구현 제공한다는 의도
	// 순수가상함수 : 파생 클래스가 반드시 만들라고 시키는 것

	virtual void draw_imp()  = 0;

public:

	// clone 도 순수 가상함수로!!
	// virtual Shape* clone() = 0;

	// 아래처럼 하는 방법도 있습니다.
	// => clone() 이 자주 사용되는 함수가 아니면 아래 처럼 만들기도 합니다
	// 1. 반드시 재정의해야 하는 것은 아니다!
	// 2. 재정의 하지 않고 사용도 하지 않으면 ok!
	// 3. 재정의 하지 않고 사용하면 예외 발생
	// 4. 재정의 하고 사용하면 ok
	// => 필요한 경우만 반드시 만들라는 의도
	virtual Shape* clone()
	{
		throw not_implemented();
	}

	// 미리 약속된 잘못된 값을 반환해서
	// "해당 도형은 면적을 구할수 없음" 이라는 의미 전달.
	virtual int get_area() { return -1; }
};



class Rect : public Shape
{
public:
	// 가상함수 재정의시
	// 1. virtual 은 있어도 되고 없어도 됩니다. -없어도 가상함수!
	// 2. C++11 이후에는 override 붙이는 것을 권장
	void draw_imp() override 
	{
		std::cout << "draw Rect" << std::endl; 
	}

	// 3. 가상함수 재정의시 반환 타입 변경 가능 합니다.
	// => 단, 상속 계층의 타입만 가능
	Rect* clone() override 
	{
		return new Rect(*this);
	}
};

class Circle : public Shape
{
public:
	void draw_imp() override { std::cout << "draw Circle" << std::endl; }

	Circle* clone() override 
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






