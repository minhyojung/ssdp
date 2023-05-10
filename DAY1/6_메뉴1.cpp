// 6_메뉴1.cpp
#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

// C언어가 바라보는 프로그램이란 ?

// => main 함수의 1번째 줄부터 차례대로 실행되는 실행흐름이다.

// => 실행순서를 변경하려면 제어문, 반복하려면 반복문

// => 기능별로 분리하려면 함수
// 절차적 프로그래밍(procedural programming)

// 장점 1. CPU의 해석 방식과 동일하다. 가장 빠르다
//     2. 메모리 사용량도 작다

// 단점 : 확장성이 부족하다.
//       변화에 유연하지 않다.
//		 유지보수가 어렵다.

// 아래 코드에서 "메뉴를 추가하면 ? "
//             "하위 메뉴가 있다면 ?"

int main()
{
	printf("1. 김밥\n");
	printf("2. 라면\n");

	int n;
	scanf_s("%d", &n);

	switch (n)
	{
	case 1: break;
	case 2: break;
	}
}
