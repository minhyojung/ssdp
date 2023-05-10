// protected 생성자 : 자신은 객체를 만들수 없고(추상적 개념)
//				     파생 클래스의 객체는 만들수있게(구체적 개념)
//				     하는 의미..

// 용어.
// 추상(abstract) <=> 구체(concrete)

class Animal
{
//public: // 아래 main 모두 에러 아님
//private:// 아래 main 모두 에러
protected:
	Animal() {}
};
class Dog : public Animal
{
public:
//	Dog() : Animal() { } // <== 컴파일러가 추가
};
int main()
{
	// 다음중 에러를 모두 고르세요..
//	Animal	a; // error. protected 는 외부에서 호출 안됨.
	Dog     d; // ok
}



