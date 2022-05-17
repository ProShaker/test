#pragma once
#include <iostream>
using namespace std;

int member_Classification = 0;	//회원 구분 변수
void menu_fitness_management();
enum { NORMAL = 1, SPINNING, PT, PILATES };

//일반 회원 클래스
class normal_management {

//개인정보는 private으로 보호한다.
private:
	char *normal_name;			//이름
	char *normal_hpnumber;		//핸드폰 번호
	char *normal_gender;		//성별

public:
//회원권 시작일에 회원권 종류를 더한 값이 회원권 종료일이다.
	int normal_member_number;	//회원번호
	int normal_start;			//시작일
	int normal_end;				//종료일
	int normal_memebership;		//회원권 기간
	bool normal_clothes;		//운동복 대여여부
	int normal_locker;			//락커 사용여부 및 락커 번호

	normal_management(normal_management *member);				//생성함수
	void add_member(normal_management* member);				//회원 추가 함수
	void rewrite_member(normal_management* member);			//회원 정보 수정
	void search_member(normal_management* member) const;		//회원 검색 함수, 변수 값의 변경이 없으므로 const 사용
	void print_member() const;		//회원 명부 출력 함수, 변수 값의 변경이 없으므로 const 사용
	void delete_member(normal_management* member);			//회원 정보 삭제 함수
	~normal_management();			//종료함수
};

// 특별 클래스 
class special_management
{
public:
	//수업 시간, 수업 요일, 트레이너 이름, 총 PT 횟수
	int class_time;					//수업시간
	char *class_day;				//수업요일
	char *trainer;					//담당 트레이너
	const int PT_number;			//총 PT횟수
};

// 스피닝 클래스 - 특별 클래스의 상속
class spinning_management : protected special_management, protected normal_management
{
};

// PT 클래스 - 특별 클래스의 상속
class pt_management : protected special_management, protected normal_management
{
};

// 필라테스 클래스 - 특별 클래스의 상속
class pilates_management : protected special_management, protected normal_management
{
};


