#include <iostream>
#include <list>
#include <vector>

// visitor 패턴
// 
// 반복자(iterator) : 복합객체의 모든 요소를 동일한 방식으로 열거
// 방문자(visitor)  : 복합객체의 모든 요소를 동일한 방식으로 연산수행

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// s의 모든 요소를 2배로 하고 싶다.
	// 방법 1. 사용자가 직접 연산(2배로) 한다.
	for (auto e : s)
		e *= 2;

	// 방법 2. 방문자 패턴을 사용한다.
	TwiceVisitor<int> tv; // 자신이 방문하는 모든 요소를 2배로 만드는 객체
	s.accept(&tv);        // 이 순간 s의 모든 요소가 2배가 된다.

	ShowVisitor<int> sv;
	s.accept(&sv);		 // 방문하는 모든 요소를 화면 출력

}





