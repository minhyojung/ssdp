// 7_단위전략6
#include <vector>
#include <iostream>

template<typename T>
class debug_alloc
{
	// 미리 약속되어 있는(C++표준문서에) 함수를 제공하면 됩니다.
public:
	T* allocate(std::size_t sz)
	{
		void* p = malloc(sizeof(T)* sz);
		printf("allocate : %p, %d cnt\n", p, sz);
		return static_cast<T*>(p);
	}

	void deallocate(T* p, std::size_t sz)
	{
		printf("deallocate : %p, %d cnt\n", p, sz);
		free(p);
	}

	// 아래 3개가 관례적으로 필요
	debug_alloc() {}
	typedef T value_type;

	template<typename U> debug_alloc(const debug_alloc<U>&) {}
};

int main()
{
//	std::vector<int> v;
	std::vector<int, debug_alloc<int> > v;

	std::cout << "------------------\n";

	v.resize(10); // 이순간 메모리 할당기 객체(allocator)의 allocate()함수 사용

	std::cout << "------------------\n";

	v.clear(); // size는 0이 되지만 사용하던 메모리가 지워진것은 아닙니다.
	v.shrink_to_fit(); // 이 때 지워집니다.

	std::cout << "------------------\n";

//	std::string s1 = "A";
//	std::string s2 = "a";
//	s1 == s2;
}
