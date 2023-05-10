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

//---------------------------
// 어답터의 종류
// 1. 클래스 어답터 : 클래스의 인터페이스 변경
// 2. 객체  어답터  : 객체의 인터페이스 변경
class Text : public TextView, public Shape     
{
public:
	Text(const std::string& s) : TextView(s) {}

	void draw() override { TextView::show(); }
};

// 객체 어답터
class ObjectAdapter : public Shape  // 요구조건을 위해서 Shape 만 상속
{
	TextView* tview; // 핵심 : 기존에 이미 존재하던 객체를 가리킬수있는
					//			포인터 또는 참조 
public:
	ObjectAdapter(TextView* tv) : tview(tv) {}

	void draw() override { tview->show(); }
};


int main()
{
	std::vector<Shape*> v;

	TextView tv("hello"); // TextView : 클래스
						  // tv       : 객체

	// 이미 생성된 tv 라는 객체를 v에 넣을수 있을까요 ?
	// v.push_back(&tv); // error. tv는 Shape 에서 파생되지 않았다

	v.push_back(new ObjectAdapter(&tv)); // ok
									// 인터페이스를 변경하는 어답터를 사용해서
									// 기존 시스템의 요구조건 만족
}

// Decorator 와 Adapter 는 코드가 유사해 보일수있습니다.
// => 의도에 따라 구분합니다.

// Decorator : 기존 객체에 기능을 추가 ( 함수 이름은 변경되지 않음)
//			   FileStream 에 ZipDecorator 를 적용해도 동일이름인 write() 사용

// Adapter : 기존 객체(클래스)의 인터페이스(함수이름) 변경

// 상속  vs 포함
// 상속 : 클래스에 기능 추가, 함수 이름 변경
// 포함 : 객체에   기능 추가, 함수 이름 변경






