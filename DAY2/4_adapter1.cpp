#include <iostream>
#include <string>
#include <vector>

// 아래 클래스가 이미 있었다가 가정해 봅시다.

// TextView : 문자열을 보관하고 있다가 화면에 이쁘게 출력하는 클래스
class TextView
{
	// font 종류, 크기, 기울기등의 다양한 정보가 있다고 가정
	std::string data;
public:
	TextView(const std::string& s) : data(s) {}

	void show() { std::cout << data << std::endl; }
};
//-------------------------------------------------------



class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};
class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};

// 도형편집기에서 "문자열" 도 관리하고 싶다.
// 기존에 있던 "TextView" 를 도형편집기 시스템에서 사용할수 있을까 ?
// => 안된다, 인터페이스(함수이름)가 다르다.

// 어답터 패턴 : 기존 클래스의 인터페이스를 변경해서 요구 조건을 만족하는 클래스 만들기
class Text : public TextView, // 기존 클래스 기능을 물려 받고
	         public Shape     // 도형편집기 요구조건을 만족
{
public:
	Text(const std::string& s) : TextView(s) {}

	// 인터페이스(함수이름)의 변경
	// "show" 를 "draw"로 변경
	void draw() override { TextView::show(); }
};

int main()
{
	std::vector<Shape*> v;

	v.push_back(new Text("hello"));
	v[0]->draw();
}







