#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class FileStream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void write(const std::string& s) 
	{
		std::cout << "write : " << s << std::endl;
	}
};

int main()
{
	// 1. C 언어는 사용자가 직접 자원을 관리해야 하므로 불편합니다
	FILE* f = fopen("a.txt", "wt");
	fclose(f);

	// 2. C++ 소멸자로 자원 관리하므로 편리합니다.
	FileStream fs("a.txt");
	fs.write("hello");

	// fs 의 소멸자가 파일을 닫아 줍니다
}
