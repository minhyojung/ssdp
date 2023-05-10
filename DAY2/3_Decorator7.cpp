#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Stream
{
	virtual void write(const std::string&) = 0;
	virtual ~Stream() {}

};

class FileStream : public Stream
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
	// 파일에 쓸때 암호화 하는 기능을 추가하고 싶습니다.
	// 최선의 디자인을 찾아 봅시다.

	// 1. 사용자가 직접 데이타를 암호화 한후에 write...
	// => 불편하다.

	// 2. FileStream 에서 파생된 EncrpytFileStream 클래스 제공
	// => FileStream 뿐아니라 NetworkStream, PipeStream 도 파생클래스 만들어야 한다.
	// => 암호화가 아닌 압축기능이 필요하면 또 파생 클래스 필요
	// => "파생클래스가 너무 많아 진다."

	// 3. 기반 클래스인 Stream 에 암호화 기능을 추가하면 어떨까?
	// => 요구 사항이 있을때 마다 Stream 변경 ???
	// => OCP 위반.. 


	// 4. Decorator 패턴을 사용하면 어떨까 ?

	FileStream fs("a.txt");
	fs.write("hello");

	EncrpytDecorator ed(&fs); // File 뿐 아니라 모든 Stream 가능..
	fs.write("hello"); // 1. 데이타를 암호화 하고 (추가된 기능)
					   // 2. fs.write() 수행

	ZipDecorator zd(&ed);
	zd.write("hello"); // 1. 압축을 하고
					   // 2. ed.write()
}
