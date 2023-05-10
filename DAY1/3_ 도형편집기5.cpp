#include <iostream>
#include <vector>

// 6. 리팩토링에서 중요시하는 용어 입니다. 잘생각해 보세요

// "Replace Conditional With Polymorphism"
// "        제어문을 다형성(가상함수)으로 변경 하라.

// 7. 디자인 패턴이란 ?
// => 1994년 나온 4명의 저자(Gangs of Four, 4명의 강도)가 만든 책이름
// => 자주사용하는 코딩스타일에 부여된 이름 - 23가지

// 8. prototype 패턴 - 견본을 먼저 만들고, 견본의 복사를 통해서 객체생성
//						clone()가상함수


class Shape
{
	int color;
public:

	void set_color(int c) { color = c; }


	virtual int get_area() { return 1; }

	virtual void draw() { std::cout << "draw Shape" << std::endl; }

	virtual Shape* clone()
	{
		Shape* p = new Shape;

		p->color = this->color;
		// 그외 모든 멤버를 나(this)와 동일하게 설정하고
		return p;
	}
};



class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect" << std::endl; }

	virtual Shape* clone()
	{
		return new Rect(*this); // 복사 생성자 사용해서 생성
	}
};


class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle" << std::endl; }
	virtual Shape* clone()
	{
		return new Circle(*this); 
	}
};

class Triangle : public Shape
{
public:
	void draw() { std::cout << "draw Triangle" << std::endl; }

	virtual Shape* clone()
	{
		return new Triangle(*this);
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

			// k번째 만들었던 도형의 복사본을 만들어서 v에 추가합니다.
			// 어떻게 해야 할까요 ?
			// k번째 만든 도형은 뭘까요 ?
			// 아래 처럼 했다면 새로운 도형 추가시 아래 코드도 수정되어야 합니다.
			// OCP 만족 안함
			/*
			if (dynamic_cast<Rect*>(v[k]) != 0)
			{
				// Rect 생성
			}
			else if (dynamic_cast<Rect*>(v[k]) != 0)
			{
				// Circle 생성..
			}
			*/

			// 좋은 방법
			v.push_back(v[k]->clone()); // ok. 다형성
								// 어떤 도형인지 조사할필요 없다.
								// 새로운 도형이 추가되어도 코드 수정 안됨.
		}
	}
}






