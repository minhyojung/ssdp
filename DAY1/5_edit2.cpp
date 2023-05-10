#include <iostream>
#include <string>
#include <conio.h>

// Validation  정책은 교체 가능해야 한다.

class Edit
{
	std::string data;
public:

	// 공통성과 가변성의 분리
	// => 변하지 않은 코드 내부에서 변하는 부분을 찾아라!!
	// => 변하는 것을 가상함수로 분리해라

	virtual bool validate(char c)
	{
		return true;
	}


	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break;

			if (validate(c)) //  값의 유효성을 판단하는 가상함수 호출
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
};

// Validation 정책을 변경하려면 Edit 파생 클래스를 만들어서
// 가상함수(변하는 것)을 override
class NumEdit : public Edit
{
public:
	bool validate(char c) override
	{
		return isdigit(c);
	}
};

int main()
{
//	Edit edit;
	NumEdit edit;

//	AddressEdit edit2;

	while (1)
	{
		std::string s = edit.getData();
		std::cout << s << std::endl;
	}
}
