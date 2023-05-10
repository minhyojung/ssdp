#include <iostream>
#include <vector>

// 1. 모든 도형을 타입으로 만들면 편리하다.

// 2. 기반 클래스가 있다면 모든 도형을 한개의 컨테이너에 묶어서 보관할수 있다.

class Shape
{
};

class Rect : public Shape
{
	// 멤버 데이타와 생성자는 생략
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
	// 생성되는 모든 도형을 보관
	//std::vector<Rect*> v1;	// Rect 만 보관 가능
	//std::vector<Circle*> v2; // Circle 만 보관 가능

	std::vector<Shape*> v; // 모든 도형(Shape 파생 클래스)을 보관 가능
}






