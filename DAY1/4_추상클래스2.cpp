#include <iostream>

class Camera
{
public:
	void take() { std::cout << "Camera take" << std::endl; }
};

class HDCamera
{
public:
	void take() { std::cout << "HDCamera take HD Picture" << std::endl; }
};

class People
{
public:
	void useCamera(Camera* p) { p->take(); }
	void useCamera(HDCamera* p) { p->take(); }
};

int main()
{
	People p;
	Camera c;
	p.useCamera(&c);

	HDCamera hc;
	p.useCamera(&hc);

}

