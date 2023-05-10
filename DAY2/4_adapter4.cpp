#include <iostream>
#include <list>
#include <vector>
#include <deque>

template<typename T, typename C = std::deque<T> > class stack
{
	C c; 
public:
	inline void push(const T& a) { c.push_back(a); }
	inline void pop() { c.pop_back(); }
	inline T&   top() { return c.back(); }
};
#include <stack> // C++ 표준 stack 이 위 코드처럼 만들었습니다.
				 // 흔히 "stack adapter" 라고 부릅니다.
int main()
{
//	std::stack<int> st;

	stack<int> s; // std::deque 를 stack으로 변경 해서 사용
	s.push(10);

	stack<int, std::list<int>> s2;
	stack<int, std::vector<int>> s3;
}
