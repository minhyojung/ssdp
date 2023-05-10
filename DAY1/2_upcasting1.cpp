class Animal
{
public:
	int age;
};

class Dog : public Animal 
{
public:
	int color;
};
int main()
{
	Dog    d;

	Dog* p1 = &d;	// ok
	int* p2 = &d;	// error

	// 핵심 1. 기반 클래스 포인터 타입으로 파생 클래스객체주소를 담을수있다
	Animal* p3 = &d;// ok. upcasting

	// 핵심 2. 기반 클래스 포인터로는 기반 클래스 멤버만 접근 가능
	// => C++ 은 컴파일 시간에 타입을 확인 하므로!!
	// => p3를 사용하면 Animal 멤버만 접근 가능하다.
	p3->age = 10;	// ok
	p3->color = 10; // error.

	// 핵심 3. p3로 Dog 가 추가한 멤버에 접근하려면 Dog* 로 캐스팅해야 한다
	//  단, 이 경우 p3가 가리키는 것이 반드시 Dog 타입 객체라는 확신이 있어야 합니다.
	static_cast<Dog*>(p3)->color = 10; // ok
}








