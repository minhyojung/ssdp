#include <iostream>
#include <vector>


// 핵심 3. 모든 도형의 공통의 특징은 반드시 기반클래스(Shape)에도
//        있어야한다.
//        그래야, Shape* 로 모든 도형을 묶었을때 해당 기능을 사용할수 있다

// 핵심 4. 기반 클래스 함수중 파생 클래스가 재정의 하게 되는 것은
//         가상함수로 해야 한다.
class Shape
{
	int color;
public:
	// 가상함수로 할까요?? 하지 말까요 ?
	// => 파생클래스가 재정의 할 필요 없습니다. 
	// => non virtual!
	void set_color(int c) { color = c; }

	// 모든 도형은 면적을 구하는 방법이 다릅니다.
	// => 각 도형에서 재정의 필요 합니다.
	// => virtual 로 하세요
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
	}
}






