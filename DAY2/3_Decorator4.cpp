#include <iostream>


struct Component
{
	virtual void Fire() = 0;
	virtual ~Component() {}
};

class SpaceShip : public Component
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};


//-------------------------------------

// 기능을 추가하는 클래스들은 공통의 특징이 있습니다.
// 기반 클래스를 설계해서  공통의 특징을 제공합니다.

class Decorator : public Component
{
	Component* ship;
public:
	Decorator(Component* c) : ship(c) {}

	void Fire() { ship->Fire(); }
};

class LeftMissile : public Decorator
{
public:
	LeftMissile(Component* s) : Decorator(s) {}

	void Fire()
	{
		Decorator::Fire();
		std::cout << "Fire Left Missile" << std::endl;
	}
};

class RightMissile : public Decorator
{
	Component* ship;
public:
	RightMissile(Component* s) : Decorator(s) {}

	void Fire()
	{
		Decorator::Fire();
		std::cout << "Fire Right Missile" << std::endl;
	}
};

int main()
{
	SpaceShip ss;
	
	LeftMissile lm(&ss);

	RightMissile rm(&lm);
	rm.Fire();
}

// Composite 와 Decorator  패턴은 Diagram 이 유사합니다.
// 재귀적 포함(A가 B를 포함하지만 A 자신도 포함)
// 의도에 따라 패턴이 다릅니다.

// 재귀적 포함을 사용한 복합 객체 만들기 : Composite
// 재귀적 포함을 사용한 객체에 기능 추가 : Decorator
