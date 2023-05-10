#include <iostream>
#include <list>
#include <vector>

// 1. 모든 방문자의 공통의 인터페이스가 필요 하다
template<typename T> struct IVisitor
{
	virtual void visit(T& e) = 0;
	virtual ~IVisitor() {}
};

// 2. 결국 방문자는 한개의 요소에 대한 연산을 정의하는 객체 입니다.
template<typename T> 
class TwiceVisitor : public IVisitor<T>
{
public:
	void visit(T& e) override { e *= 2; }
};

template<typename T>
class ShowVisitor : public IVisitor<T>
{
public:
	void visit(T& e) override { std::cout << e << ", "; }
};

template<typename T>
class ZeroVisitor : public IVisitor<T>
{
public:
	void visit(T& e) override { e = 0; }
};

//--------------------------------------
// 모든 복합객체는 accept 가 있어야 한다.
template<typename T> 
struct IAcceptor
{
	virtual void accept(IVisitor<T>* visitor) = 0;
	virtual ~IAcceptor() {}
};
//----------------
template<typename T>
class MyList : public std::list<T>, public IAcceptor<T>
{
public:
	using std::list<T>::list; // 기반 클래스의 생성자를 상속해 달라	
							  // list 에 생성자가 5개 라면 
							  // MyList가 모두 물려 받게 됩니다.
							  // "생성자 상속" 이라는 문법

	// 아래 코드가 방문자 패턴의 핵심입니다.
	void accept(IVisitor<T>* visitor)
	{
		for (auto& e : *this) // *this 는 자신, 즉, list 입니다.
			visitor->visit(e);
	}
};

int main()
{
//	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv; 
	s.accept(&tv);        

	ShowVisitor<int> sv;
	s.accept(&sv);	

	ZeroVisitor<int> zv;
	s.accept(&zv);
	s.accept(&sv);
}





