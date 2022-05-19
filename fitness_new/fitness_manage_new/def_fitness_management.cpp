#include "def_fitness_management.h"
#define Members 255 // 코드에서 사용할 배열의 크기(회원수)를 매크로로 지정

base_management* member;							//회원 구분 후 동적 배열을 가리키기 위한 포인터 변수
int universal_numb = 0;							//메뉴 번호 변수
int member_Classification = 0;				//회원 구분 변수

void menu_fitness_management()
{
	cout << "-----<헬스장 회원관리 프로그램 메인화면>-----" << endl << endl;
	cout << "1. 일반 회원" << endl;
	cout << "2. 스피닝 회원" << endl;
	cout << "3. PT 회원" << endl;
	cout << "4. 필라테스 회원" << endl << endl;
	cout << "원하시는 회원 구분 번호를 선택해주세요. : ";
	cin >> member_Classification;
	cout << endl;

	switch (member_Classification) //회원구분에 따라 다른 선택지를 제공한다.
	{
	case NORMAL:
		cout << "일반 회원을 선택하셨습니다." << endl << endl;
		cout << "-----<일반 회원관리 메뉴>-----" << endl << endl;
		member = new normal_member[Members]; //메모리 관리를 위해 동적할당으로 회원 객체배열을 생성한다.
		break;

	case SPINNING:
		cout << "스피닝 회원을 선택하셨습니다." << endl << endl;
		cout << "-----<스피닝 회원관리 메뉴>-----" << endl << endl;
		member = new spinning_member[Members];
		break;

	case PT:
		cout << "PT 회원을 선택하셨습니다." << endl << endl;
		cout << "-----<PT 회원관리 메뉴>-----" << endl << endl;
		member = new pt_member[Members];
		break;

	case PILATES:
		cout << "필라테스 회원을 선택하셨습니다." << endl << endl;
		cout << "-----<필라테스 회원관리 메뉴>-----" << endl << endl;
		member = new pilates_member[Members];
		break;

	default:
		cout << "해당 번호는 존재하지 않습니다. 다시 입력해주세요." << endl;
		cout << "만약 프로그램을 종료하고 싶으시다면 'Ctrl + C'를 눌러주세요." << endl << endl;
		menu_fitness_management();
	}

	//각 클래스의 회원관리 메뉴
	cout << "1. 회원 추가" << endl;
	cout << "2. 회원 정보 수정(개인 정보, 락커, 운동복)" << endl;
	cout << "3. 회원 검색(이름, 전화번호, 담당 트레이너 검색 가능)" << endl;
	cout << "4. 회원 명부 출력(성별로 출력 가능)" << endl;
	cout << "5. 회원 삭제" << endl << endl;

	cout << "원하시는 메뉴 번호를 선택해주세요. : ";
	cin >> universal_numb;
	cout << endl;

	//switch문을 통해 메뉴에 진입한다.
	switch (universal_numb)
	{
	case 1:
		cout << "회원 추가 화면입니다." << endl << endl;
		member->add_member(member);
		if (member_Classification != NORMAL)	 //일반 회원이 아니라면 추가 정보 입력
			member->additional_add_member(member);
		break;

	case 2:
		cout << "회원 정보 수정 화면입니다." << endl << endl;
		member->rewrite_member(member);
		break;

	case 3:
		cout << "회원 검색 화면입니다." << endl; 
		cout << "1. 이름 " << endl << "2. 전화번호 " << endl << "3. 담당 트레이너 " << endl << "검색 분야를 선택해주세요. : "  << endl;
		cin >> universal_numb;
		if (universal_numb == 1)
			member->search_member(member);
		else if (universal_numb == 2) {}
			//member->search_member(member, universal_numb);
		else if (universal_numb == 3) {}
			//member->additional_search_member(member);
		else
		{
			cout << "해당 번호는 존재하지 않습니다. 회원 구분 선택으로 돌아갑니다." << endl;
			menu_fitness_management();
		}

	case 4:
		cout << "회원 명부 출력 화면입니다." << endl << endl;
		member->print_member(member);
		break;

	case 5:
		cout << "회원 삭제 화면입니다." << endl << endl;
		member->delete_member(member);
		break;

	default:
		cout << "해당 번호는 존재하지 않습니다. 회원 구분 화면으로 돌아갑니다." << endl;
		cout << "만약 프로그램을 종료하고 싶으시다면 'Ctrl + C'를 눌러주세요." << endl << endl;
		menu_fitness_management();
	}
}

//생성함수 정의부, 멤버변수에 대한 초기화를 진행한다.
base_management::base_management()
{
	//string 변수 : 공백으로 초기화
	normal_name = " ";			//이름
	normal_hpnumber = " ";		//핸드폰 번호
	normal_gender = " ";		//성별
	class_day = " ";			//수업요일
	trainer = " ";				//담당 트레이너

	//int, char, bool 변수 : false 또는 0으로 초기화
	normal_member_number = 0;	//회원번호
	normal_start = 0;			//시작일
	normal_end = 0;				//종료일
	normal_clothes = false;		//운동복 대여여부
	class_time = 0;				//수업시간
	
}

//회원 추가함수 정의문
void base_management::add_member(base_management* member)
{
	unsigned char member_index = 0;			//배열에서 사용할 회원 인덱스 변수
	bool cnt = false;						//인원 초과를 확인하는 변수

	for (int i = 0; i < Members; i++)		//반복문을 통해 빈 인덱스를 회원 인덱스, 회원 번호로 지정한다.
	{
		if (member[i].normal_member_number == 0)	 //빈 인덱스가 있다면 반복문을 실행 
		{
			member_index = i;						
			member[member_index].normal_member_number = i + 1;
			cnt = true;
			break;
		}
	}

	if (!cnt)		//반복문 실행 후에도 cnt값이 false라면 인원 초과						
	{
		cout << "헬스장 수용 가능 인원을 초과했습니다." << endl << endl;
		return;
	}
	char normal_memebership; //회원권 기간 변수
	
	cout << "추가할 회원님의 정보를 입력해주세요." << endl;
	cout << "이름 : ";
	cin >> member[member_index].normal_name;
	cout << "핸드폰 번호 (010-0000-0000): ";
	cin >> member[member_index].normal_hpnumber;
	cout << "성별 (남/여) : ";
	cin >> member[member_index].normal_gender;
	cout << "시작일(YYYYMMDD) : ";
	cin >> member[member_index].normal_start;
	cout << "회원권 종류(개월 수 입력) : ";
	cin >> normal_memebership;
	normal_end = normal_start + normal_memebership * 30;
	cout << "운동복 대여 여부 (y/n) : ";
	cin >> universal_numb;
	member[member_index].normal_clothes = (universal_numb == 'y') ? true : false; //삼항연산자
}

void base_management::search_member(base_management* member) const
{

}

void base_management::rewrite_member(base_management* member)
{
	member->print_member(member);
	cout << "변경할 회원님의 번호를 입력해주세요. : ";

}


void base_management::print_member(base_management* member) const
{
	cout << "회원 명부 출력을 선택하셨습니다." << endl;
	cout << "회원 번호 | 이름 | 핸드폰 번호 | 성별 | 회원권 시작일 | 회원권 종료일 | 운동복 대여 여부" << endl << endl;
	for (int i = 0; i < Members; ++i)
	{
		if (member[i].normal_member_number != 0) {					//값이 있는 배열만 출력
			cout << member[i].normal_member_number << " ";
			cout << member[i].normal_name << " ";
			cout << member[i].normal_hpnumber << " ";
			cout << member[i].normal_gender << " ";
			cout << member[i].normal_start << " ";
			cout << member[i].normal_end << " ";
			cout << member[i].normal_clothes << " " << endl;
		}
		
	}
}

void base_management::delete_member(base_management* member)
{
	member->print_member(member);
	cout << "변경할 회원님의 회원 번호를 입력해주세요. : ";
	cin >> universal_numb;
	normal_name = " ";			
	normal_hpnumber = " ";		
	normal_gender = " ";		
	class_day = " ";			
	trainer = " ";										
	normal_member_number = 0;	
	normal_start = 0;			
	normal_end = 0;				
	normal_clothes = false;		
	class_time = 0;	

	cout << member[universal_numb].normal_name << "회원님의 정보가 삭제되었습니다." << endl << endl;
}

base_management::~base_management()
{
}

void base_management::additional_add_member(base_management* member)
{
}

void base_management::additional_rewrite_member(base_management* member)
{
}

void base_management::additional_search_member(base_management* member) const
{
}

