class Animal {};
class Dog : public Animal {};



// LSP : Liskov Substitution Principle
// => 기반 클래스가 사용되는 곳을 파생 클래스로 대체 할수있어야한다.

void foo(Animal* p) {}

foo(Dog객체); // <== 이렇게 할수 있어야 한다.!!

//-----------------------
class list
{
public:
	void push_back() {}
	void push_front() {}
};
class stack : public list
{
	void push_front() { throw 1 }; // <== LSP 위배!
};

void goo(list* p) { p->push_front(); }

goo(stack 객체);
//==========================================
// 아래 인터페이스는 좋은 인터페이스 일까요 ?
// ISP ( Interface Surrogate Principle )
// => 인터페이스는 기능 별로 분리
// SRP 
// => 클래스는 한개의 책임만
struct IMP3
{
	virtual void Play() = 0;
	virtual void UploadSNS() = 0;
	virtual void VoiceRecord() = 0;
};

// DIP(Dependency Inversion Principle)
// => concrete 에 의존하지 말고 abstract 에 의존하라
class People
{
  public:
  void use(HDCamera* p) {} // bad
  void use(ICamera* p) {} // good
};


// SOLID : SRP, OCP, LSP, ISP, DIP
