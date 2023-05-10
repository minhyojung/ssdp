
#include <iostream>
#include <string>
#include <map>

class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:

	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	inline static std::map<std::string, Image*> image_map;

	// 자기 자신을 만드는 static 멤버 함수 - 아주 널리 사용되는 기술
	static Image* Create(const std::string& url)
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
	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->Draw();

}



