// Decorator - 65 page
#include <iostream>

class SpaceShip // 우주 비행선
{
public:
	void Fire()	{ std::cout << "Fire Missile" << std::endl; }
};

// 상속을 사용한 기능의 추가
// => 객체에 기능의 추가가 아닌 클래스의 기능 추가
// => 동적 기능 추가가 아닌 정적(코드 만들때) 기능의 추가
class LeftMissile : public SpaceShip
{
public:
	void Fire()
	{
		SpaceShip::Fire(); // 기존 기능을 사용하고..
		std::cout << "Fire Left Missile" << std::endl; // 새로운 기능추가
	}
};
int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm; // ss 객체에 기능을 추가한 것이 아니라
					// 기능이 추가된 새로운 우주선 객체를 만든것
	lm.Fire();
}

