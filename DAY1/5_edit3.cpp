#include <iostream>
#include <string>
#include <conio.h>

// 변하는 것을 분리하는 2가지 방법
// 1. 변하는 것을 가상함수로 - Edit2.cpp 
// 2. 변하는 것을 다른 클래스로 - 지금 소스

// validation 정책은 교체 가능해야 한다. - 인터페이스 설계
struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool isComplete(const std::string& s) { return true; }

	virtual ~IValidator() {}
};

// 주민 번호 : 901   1     확인






class Edit
{
	std::string data;
	
	IValidator* pval = nullptr;
public:
	void setValidator(IValidator* p) { pval = p; }


	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13  && (pval == nullptr || pval->isComplete(data)) ) break;

			if ( pval == nullptr || pval->validate(data, c) ) // 유효성을 다른 객체에 위임
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
};

// 이제 다양한 Validator 를 제공하면 됩니다.
class LimitDigitValidator : public IValidator
{
	int limit;
public:
	LimitDigitValidator(int n) : limit(n) {}

	bool validate(const std::string& s, char c) override
	{
		return s.size() < limit && isdigit(c);
	}

	bool isComplete(const std::string& s) override
	{
		return s.size() == limit;
	}
};



int main()
{
	Edit edit;
	LimitDigitValidator v(5);
	edit.setValidator(&v);

	LimitDigitValidator v2(15);
	edit.setValidator(&v2);

	while (1)
	{
		std::string s = edit.getData();
		std::cout << s << std::endl;
	}
}
