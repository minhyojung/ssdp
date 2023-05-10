#include <iostream>
#include <string>

class Person
{
	std::string name;
	int age;
public:
	Person(const std::string& n, int a) : name(n), age(a) {}
};
// Person으로 부터 파생된 Student 만들어 보세요
// "int id" 추가해 보세요
// main 에서 Student 객체 생성해 보세요
class Student : public Person
{
	int id;
public:
	// 아래 처럼 자신의 멤버만 초기화 하면 안됩니다.
	// Person안에 디폴트 생성자 없습니다.
	//Student(int id) : id(id) {} //Student(int id) :Person(),  id(id) {}

	Student(const std::string& name, int age, int id) 
		: Person(name, age ), id(id) {}
};
int main()
{
	Student s("kim", 10, 15);

	Person p("kim", 10); // 초기화된 객체 - 안전하다.!

//	Person p; // 초기화 되지 않은 객체 탄생 ?? - 안전하지 않다
}
