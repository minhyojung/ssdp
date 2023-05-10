#include <iostream>
#include <string>
#include <conio.h>

// 28 page ~

// GUI 입력 도구인 Edit 를 만들어 봅시다.
class Edit
{
	std::string data;
public:
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
