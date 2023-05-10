#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// 모든 스트림의 공통의 인터페이스
struct Stream
{
	virtual void write(const std::string&) = 0;
	virtual ~Stream() {}

	// 그외에 read, is_open, flush 등의 입출력 관련 기능 함수 
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
	FileStream fs("a.txt");
	fs.write("hello");

	NetworkStream ns("127.0.0.1", 4000);
	ns.write("hello");

	PipeStream ps("named pipe");
	ps.write("hello");

}
