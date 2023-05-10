#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

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
// 1. 기능추가 클래스도 Stream 으로 부터 상속받아야 기능의 중첩가능
class EncrpytDecorator : public Stream
{
	Stream* stream; // 기능을 추가할 대상 객체를 가리키는 포인터
public:
	EncrpytDecorator(Stream* s) : stream(s) {}

	void write(const std::string& data)
	{
		auto s = data + " 암호화"; // 추가된기능

		stream->write(s); // 기존 객체의 기능 수행
	}
};

class ZipDecorator : public Stream
{
	Stream* stream; 
public:
	ZipDecorator(Stream* s) : stream(s) {}

	void write(const std::string& data)
	{
		auto s = data + " 압축됨"; 

		stream->write(s); 
	}
};

int main()
{
	FileStream fs("a.txt");
//	fs.write("hello");

	EncrpytDecorator ed(&fs); 
//	fs.write("hello");   // "hello 압축 암호화"

	ZipDecorator zd(&ed);
	zd.write("hello"); // "hello 압축"
}

// C#
// 저장소 클래스			데코레이터
// FileStream			GZipStream
// NetworkStream		CryptoStream
// PipeStream			XmlStream
// MemoryStream			HtmlStream

// 구글에서 "C# stream decorator" 검색후 "이미지보기"
