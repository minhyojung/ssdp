#include <iostream>

// 우주선과 우주선에 기능을 추가하는 클래스는 공통의 기반 클래스가 필요하다

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
class LeftMissile : public Component
{
	Component* ship;
public:
	LeftMissile(Component* s) : ship(s) {}

	void Fire()
	{
		ship->Fire(); 
		std::cout << "Fire Left Missile" << std::endl;  
	}
};

class RightMissile : public Component
{
	Component* ship;
public:
	RightMissile(Component* s) : ship(s) {}

	void Fire()
	{
		ship->Fire();
		std::cout << "Fire Right Missile" << std::endl;
	}
};

int main()
{
	SpaceShip ss;
//	ss.Fire();

	LeftMissile lm(&ss); 
//	lm.Fire(); 

	RightMissile rm(&lm); // 기능을 추가한 후에 다시 기능 추가
	rm.Fire();
}

