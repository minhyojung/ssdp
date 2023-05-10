
#include <iostream>
#include <string>
#include <map>

// SRP : Single Responsibility Principle
// => 단일 책임의 원칙
// => 하나의 클래스는 하나의 책임만 가져야 한다.


class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:

	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	friend class ImageFactory;
};

class ImageFactory
{
	std::map<std::string, Image*> image_map;
public:
	Image* Create(const std::string& url)
	{
		Image* img = nullptr;

		auto ret = image_map.find(url);

		if (ret == image_map.end())
		{
			img = new Image(url);
			image_map[url] = img;
		}
		else
			img = ret->second;

		return img;
	}
};


int main()
{
	ImageFactory factory; // 공장은 싱글톤으로 하는 경우도 많습니다.

	Image* img1 = factory.Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = factory.Create("www.naver.com/a.png");
	img2->Draw();

}



