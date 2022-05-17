#include "def_fitness_management.h"
#define y true
#define n false
#define Members 150 // 코드에서 사용할 배열의 크기(회원수)를 매크로로 지정
int menu_numb = 0; //메뉴 번호 변수

void menu_fitness_management()
{
	cout << "-----<헬스장 회원관리 프로그램 메인화면>-----" << endl << endl;
	cout << "1. 일반 회원" << endl;
	cout << "2. 스피닝 회원" << endl;
	cout << "3. PT 회원" << endl;
	cout << "4. 필라테스 회원" << endl << endl;
	cout << "원하시는 회원 구분 번호를 선택해주세요. : ";
	cin >> member_Classification;

	switch (member_Classification) //회원구분에 따라 다른 선택지를 제공한다.
	{
	case NORMAL:
		cout << "일반 회원을 선택하셨습니다." << endl << endl;
		cout << "-----<일반 회원관리 메뉴>-----" << endl << endl;
		normal_management* member = new normal_management[Members]; //메모리 관리를 위해 동적할당으로 회원 객체배열을 생성한다.
		break;

	case SPINNING:
		cout << "스피닝 회원을 선택하셨습니다." << endl << endl;
		cout << "-----<스피닝 회원관리 메뉴>-----" << endl << endl;
		spinning_management* member = new spinning_management[Members];
		break;

	case PT:
		cout << "PT 회원을 선택하셨습니다." << endl << endl;
		cout << "-----<PT 회원관리 메뉴>-----" << endl << endl;
		pt_management* member = new pt_management[Members];
		break;

	case PILATES:
		cout << "필라테스 회원을 선택하셨습니다." << endl << endl;
		cout << "-----<필라테스 회원관리 메뉴>-----" << endl << endl;
		pilates_management* member = new pilates_management[Members];
		break;

	default:
		cout << "해당 번호는 존재하지 않습니다. 다시 입력해주세요." << endl;
		cout << "만약 프로그램을 종료하고 싶으시다면 'Ctrl + C'를 눌러주세요." << endl << endl;
		menu_fitness_management();
	}

	//각 클래스의 회원관리 메뉴
	cout << "1. 회원 추가" << endl;
	cout << "2. 회원 정보 수정(락커, 운동복, 개인 정보)" << endl;
	cout << "3. 회원 검색" << endl;
	cout << "4. 회원 명부 출력" << endl;
	cout << "5. 회원 삭제" << endl << endl;

	cout << "-----<원하시는 메뉴 번호를 선택해주세요.>-----" << endl;
	cin >> menu_numb;
	cout << endl;

	//switch문을 통해 메뉴에 진입한다.
	//현재의 문제 1: 회원 구분 switch문에서 회원 구분해서 동적할당을 했는데 이 요소를 어떻게 아래의 switch문으로 전달할 것인지
	switch (menu_numb)
	{
	case 1:
		cout << "회원 추가 화면입니다." << endl;
		member->add_member(normal_management * member);
		break;

	case 2:
		cout << "회원 정보 수정 화면입니다." << endl;
		member->rewrite_member(normal_management * member);
		break;

	case 3:
		cout << "회원 검색 화면입니다." << endl;
		member->search_member(normal_management * member);
		break;

	case 4:
		cout << "회원 명부 출력 화면입니다." << endl;
		member->print_member();
		break;

	case 5:
		cout << "회원 삭제 화면입니다." << endl;
		member->delete_member(normal_management * member);
		break;

	default:
		cout << "해당 번호는 존재하지 않습니다. 회원 구분 화면으로 돌아갑니다." << endl;
		cout << "만약 프로그램을 종료하고 싶으시다면 'Ctrl + C'를 눌러주세요." << endl;
		menu_fitness_management();
	}
}

//기본 생성함수 정의문, 각 값들을 초기화 해준다.
normal_management::normal_management()
{
private:								//개인정보는 private으로 보호한다.
	char* normal_name = NULL;			//이름
	char* normal_hpnumber = NULL;		//핸드폰 번호
	char* normal_gender = NULL;			//성별

public:
	int normal_member_number = 0;     //회원번호
	int normal_start = 0;			//시작일
	int normal_end = 0;				//종료일
	int normal_memebership = 0;		//회원권 기간
	bool normal_clothes = false;	//운동복 대여여부
	int normal_locker = 0;			//락커 사용여부
}

// 일반 회원 추가 함수 정의문
// 문제2 : 각 클래스마다 add_member를 정의하는 것보다 효율적인 정의 방법은 없을까
void normal_management::add_member(normal_management* member)
{
	cout << "회원 추가를 선택하셨습니다." << endl;
	int member_index = NULL;				//배열에서 회원의 인덱스 변수
	for (int i = 0; i < Members; i++)		//반복문을 통해 빈 인덱스를 찾는다.
		{
			if (member[i].normal_member_number == 0)  //빈 인덱스가 있다면 반복문을 종료 
			{	
				member_index = i;					//member_index와 회원번호에 인덱스 값을 할당한다.
				member[member_index].normal_member_number = i;
				break;
			}

		}
	//반복문을 돌린 후에도 member_index가 NULL이라면 빈 자리가 없으므로 함수를 종료한다.
	if (member_index == NULL)	
	{
		cout << "헬스장 수용인원을 초과했습니다.";
		return;
	}
	
	cout << "추가할 회원님의 정보를 입력해주세요." << endl;
	cout << "이름 : ";
	cin >> member[member_index].normal_name;
	cout << "핸드폰 번호 (0000-0000): ";
	cin >> member[member_index].normal_hpnumber;
	cout << "성별 (남/여) : ";
	cin >> member[member_index].normal_gender;
	cout << "시작일(YYYYMMDD) : ";
	cin >> member[member_index].normal_start;
	cout << "회원권 종류(1, 3, 6, 12개월 중 선택) : ";
	cin >> member[member_index].normal_memebership;
	normal_end = normal_start + normal_memebership * 30;
	cout << "운동복 대여 여부 (y/n) : ";
	cin >> member[member_index].normal_clothes;
	cout << "개인 락커 사용여부 (y/n) : ";
	cin >> member[member_index].normal_locker;
	if (normal_locker == y) {
		cout << "락커 번호는 회원번호와 연동됩니다." << endl;
		normal_locker = member_index;
	}
}

//회원 명부 출력 함수 정의문
void normal_management::print_member()
{
	cout << "회원 명부 출력을 선택하셨습니다." << endl;
	cout << "회원 번호 | 이름 | 핸드폰 번호 | 성별 | 회원권 시작일 | 회원권 종료일 | 운동복 대여 여부 | 개인락커 사용여부" << endl << endl;
	for (int i = 0; i < Members; ++i)
	{
		cout << member[i].normal_member_number << " ";
		cout << member[i].normal_name << " ";
		cout << member[i].normal_hpnumber << " ";
		cout << member[i].normal_gender << " ";
		cout << member[i].normal_start << " ";
		cout << member[i].normal_end << " ";
		cout << member[i].normal_clothes << " ";
		cout << member[i].normal_locker << endl;
	}
}

//회원 검색 함수 정의문
void normal_management::search_member(normal_management* member)
{
	cout << "회원검색을 선택하셨습니다. 검색 분야를 선택해주세요." << endl;
	cout << "1. 이름, 2. 핸드폰 번호, 3. 성별" << endl;
	cin >> menu_numb;

	switch (menu_numb)
	{
	case 1:
		cout << "이름 검색을 선택하셨습니다."
	}
	//220517 11:43 코드 작성 중지 : 이유 - 졸림
}
//회원 정보 수정 함수 정의문
void normal_management::rewrite_member(normal_management* member)
{

}


//회원 삭제 함수 정의문
void normal_management::delete_member(normal_management* member)
{

}

//메뉴 화면을 출력하는 함수 정의문


