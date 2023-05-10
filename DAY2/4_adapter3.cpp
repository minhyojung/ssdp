#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter

// list 의 인터페이스(함수이름)을 변경해서 stack을 만들어 봅시다

/*
// 방법 1. public 상속
// => 구현과 인터페이스를 모두 물려 받겠다
template<typename T> class stack : public std::list<T>
{
public:
	inline void push(const T& a) { std::list<T>::push_back(a); }
	inline void pop()			 { std::list<T>::pop_back(); }
	inline T&   top()            { return std::list<T>::back(); }
};
*/

// 방법 2. private 상속
// => 구현은 물려 받지만 ( stack 이 내부적으로 list 함수는 사용)
// => 인터페이스는 물려 받지 않겠다( list 함수를 외부 노출 안함)
/*
template<typename T> class stack : private std::list<T>
{
public:
	inline void push(const T& a) { std::list<T>::push_back(a); }
	inline void pop() { std::list<T>::pop_back(); }
	inline T&   top() { return std::list<T>::back(); }
};
*/
// 방법 3. list 의 기능을 stack 내부적으로만 사용한다면
// 상속보다 포함이 좋다.
// 단,
// private 상속 : list 에 가상함수가 있다면 override 할 기회가 있다.
// 포함         : list 에 가상함수를 override 할 기회가 없다
template<typename T> class stack 
{
//	std::list<T>* c; // 이렇게 있어야 "객체 어답터" 입니다.
	std::list<T> c;  // 이렇게 있다면 "클래스 어답터"로 보아야 합니다.
public:
	inline void push(const T& a) { c.push_back(a); }
	inline void pop()			{ c.pop_back(); }
	inline T&   top()			{ return c.back(); }
};

int main()
{
//	std::list<int> st; // list 만들고
//	st.push_back(10); // 사용하다가
	
//	objectAdapter a(&st);// st 를 스택처럼 변경할수 있다면 object adapter

	stack<int> s;
	s.push(10);

//	s.push_front(20); // 사용자가 실수했다
						// private 상속이라면 에러
}
