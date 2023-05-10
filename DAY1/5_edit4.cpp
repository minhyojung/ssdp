// 변하는 것을 가상함수로				// 변하는 것을 다른 클래스로
// => template method 패턴			// => strategy pattern
// => 상속 기반의 패턴				// => 포함 기반의 패턴
// => 실행시간에 정책 교체 안됨		// => 실행시간 정책 교체 가능
//										  (edit.setValidator(다른정책))
// => 정책을 NumEdit 안에 포함		// => 정책과 Edit 는 분리됨.
//    다른 입력도구에서 활용 안됨		// => 모든 입력도구에서 정책 클래스 사용가능
// => 유연성이 좋지 않다				// => 유연성이 좋다.

// => 멤버 함수 이므로				// => Validator 에서 Edit 멤버 접근이
//  private 멤버 데이타 접근가능		      어렵다

// "상속 보다 포함" 이 유연합니다.
class Edit
{
	IValidator* pval; // <=== 이런 코드가 포함입니다.
					  // pval ----------> 유효성 체크 객체
};