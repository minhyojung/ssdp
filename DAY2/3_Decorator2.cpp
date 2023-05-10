// Decorator - 65 page
#include <iostream>

class SpaceShip // 우주 비행선
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};
//-------------------------------------
// 상속을 사용한 기능의 추가 : 클래스에 기능 추가
// 포함을 사용한 기능의 추가 : 객체에 기능 추가
// (값이 아닌 포인터 또는 참조 멤버로 포함)
class LeftMissile   
{
	SpaceShip* ship; // 핵심 : 우주선을 가리키는 포인터나 참조를 멤버데이타로
					//  => 이미 생성되어 있는 우주선 객체를 가리키겠다는 의미
public:
	LeftMissile(SpaceShip* s) : ship(s) {}

	void Fire()
	{
		ship->Fire(); // 기존 객체의 기능 사용
		std::cout << "Fire Left Missile" << std::endl;  // 새로운 기능추가
	}
};
int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm(&ss); // lm 은 ss 객체에 기능을 추가하는 객체입니다. 
	lm.Fire(); // ss의 기능을 사용
			   // 추가된 기능 제공
}

