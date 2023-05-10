#include <iostream>
#include <string>
#include <conio.h>

// 참고 : 클래스 대신 함수 포인터로 하면 안되나요 ??
// 
// 클래스로 설계
// => validate 와 isComplete 를 묶어서 관리
// => 멤버 데이타도 사용가능(int limit)

// 함수 포인터
// => 등록할 함수가 2개라면 따로 관리된다.
// => 멤버 데이타등이 없다

class Edit
{
	std::string data;
	//----------------------------------------------------
	typedef bool(*VALIDATOR)(const std::string&, char);

	VALIDATOR val = nullptr;
public:
	void setValidator(VALIDATOR v) { val = v; }
	//----------------------------------------------------

	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break; // enter 키

			if (isdigit(c))
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
};



int main()
{
	Edit edit;
	while (1)
	{
		std::string s = edit.getData();
		std::cout << s << std::endl;
	}
}
