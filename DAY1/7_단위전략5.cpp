// STL 의 원리
template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	T* buff;
	Alloc ax; // 메모리 할당기
			  // 앞으로 모든 멤버 함수는 이 객체를 사용해서 
			  // 메모리 할당/해지 해야 합니다.
public:
	void resize(std::size_t sz)
	{
		// 메모리 재할당이 필요한 경우 어떻게 해야 할까요 ?
		// new ? malloc ? system call ?

//		buff = new T[sz]; // 이렇게 만들면 사용자가 교체 할수 없습니다.

		buff = ax.allocate(sz);	// 표준 할당기는 이순간 new 사용

		ax.deallocate(buff, sz); // 해지도 이렇게. 표준할당기는 delete사용
	}
};
vector<int> v;
