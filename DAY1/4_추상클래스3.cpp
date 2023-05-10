#include <iostream>


// 강한결합(tightly coupling)
// => 하나의 클래스가 다른 클래스 사용시 이름을 직접 사용하는 것
// => 확장성 없는 경직된 디자인


// 약한결합(loosely coupling)
// => 하나의 클래스가 다른 클래스 사용시 규칙(인터페이스)를 통해서 사용
// => 확장성 있는 유연한 디자인


// 추상클래스 : 규칙(순수가상함수) + 다른 멤버
// 인터페이스 : 규칙(순수가상함수) 만 가진 경우

// java, C# : abstract, interface 키워드 제공
// C++은 "추상클래스" 문법만 존재

//----------------------------------------------------------

// 카메라와 카메라 사용자 사이에 지켜야 하는 규칙을 먼저 설계 합니다.

// 규칙 : "모든 카메라는 아래 클래스로 부터 파생되어야 한다."  라고 하지말고!!
//        "모든 카메라는 아래 인터페이스를 구현해야 한다." 라고 표현합니다.

struct ICamera    // 접근지정자 생략시 public 이 기본
//class ICamera
{
//public:
	virtual void take() = 0;

	virtual ~ICamera() {}   // 인터페이스도 문법적으로는 결국 기반 클래스.
						    // C++에서 모든 기반 클래스는 소멸자를 가상으로
							// 해야 합니다. - C++기본 서적 "가상소멸자" 참고
};





// 실제 카메라가 없어도 규칙이 있다
// 사용자는 규칙대로만 사용하면 된다.
class People
{
public:
	void useCamera(ICamera* c) { c->take(); }
};


class Camera : public ICamera
{
public:
	void take() { std::cout << "Camera take" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() { std::cout << "HDCamera take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void take() { std::cout << "UHDCamera take UHD Picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.useCamera(&c);

	HDCamera hc;
	p.useCamera(&hc);

	UHDCamera uhc;
	p.useCamera(&uhc);

}

