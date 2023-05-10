#include <iostream>

class Animal
{
public:
	int age;

	// 다형적 타입(가상함수가 있는 타입)만 dynamic_cast 사용가능합니다.
	virtual ~Animal() {}
};

class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Dog    d;
//	Animal d; // d 객체가 Animal 입니다.

	Animal* p = &d;	 // upcasting


	// if ( 사용자 입력 == 1) p = &dog 객체;

	// 실행하다가 사용자 입력에 따라 p가 가리키는 객체가 변경될수 있습니다.
	// => 따라서 컴파일러는 컴파일 시간에는 p가 어느 객체를 가리키는지
	//    알수 없습니다.

	// down casting : 기반 클래스 포인터를 파생 클래스 타입으로 캐스팅 하는것
	// 장점 : 컴파일 시간 캐스팅, 실행시 오버헤드 없음
	// 단점 : p가 가리키는 객체가 정말 Dog인지 조사할수 없다.
	// Dog* pdog = static_cast<Dog*>(p);

	// dynamic_cast : 실행시간 캐스트
	//					Dog 가 아닌 경우, 0 반환
	Dog* pdog = dynamic_cast<Dog*>(p);

	std::cout << pdog << std::endl;
}








