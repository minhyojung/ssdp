#include <stdio.h>

int main()
{
	char s1[] = "aaaa"; // 문자열 배열. 문자열이 스택에
	const char* s2  = "aaaa"; // 문자열 포인터. 문자열이 어디에 있을까요??
	//*s = 'b';

	const char* p1 = "to be";
	const char* p2 = "to be";

	// 아래 결과를 예측해 보세요? 주소가 같을까요 ? 다를 까요 ?
	printf("%p\n", p1);
	printf("%p\n", p2);

}
