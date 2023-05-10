
// 2. 추상 클래스 : 순수 가상함수가 한개 이상 있는 클래스
// 3. 추상 클래스 특징 : 객체를 만들수 없다.
// 4. 추상 클래스 의도 : 파생 클래스에게 특정 멤버 함수를 반드시 만들라고
//						시키는 것!!!
class Shape
{
public:
	virtual void draw() = 0; // 1. 순수 가상함수(pure virtual function)
							 // 구현부가 없고 "= 0" 으로 표기
};
class Rect : public Shape
{
public:
	// 핵심 ; Rect 가 draw() 구현부를 제공하지 않으면 Rect 도 추상
	// draw() 구현부를 제공하는 추상 아님
	virtual void draw() {}
};

int main()
{ 
//	Shape s;  // error
	Rect  r;
}

