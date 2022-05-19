#pragma once
#include <iostream>							//입출력을 위한 헤더파일
#include <string>							//string 클래스를 사용하기 위한 헤더파일
using namespace std;						//string 자료형을 사용하기 위한 네임스페이스
void menu_fitness_management();				//메뉴 함수 선언문
enum { NORMAL = 1, SPINNING, PT, PILATES }; //회원 구분을 위한 열거형

// 관리 기능, 회원 정보 변수를 담고 있는 기반 클래스
class base_management 
{

	//개인정보는 protected로 보호한다.
protected:
	string normal_name;			//이름
	string normal_hpnumber;		//핸드폰 번호
	string normal_gender;		//성별

public:
	unsigned char normal_member_number;	//회원번호
				//회원권 기간, 메모리 관리를 위해 char자료형을 사용
	bool normal_clothes;				//운동복 대여여부
	int normal_start;					//시작일
	int normal_end;						//종료일

	//스피닝, PT, 필라테스 클래스를 위한 변수(수업 시간, 수업 요일, 트레이너 이름, 총 PT 횟수)
	char class_time;					//수업시간
	string class_day;				//수업요일
	string trainer;					//담당 트레이너

	base_management();										
	void add_member(base_management* member);				//회원 추가 함수
	void rewrite_member(base_management* member);			//회원 정보 수정
	void search_member(base_management* member) const;			//회원 검색 함수(이름) 
	void search_member(base_management* member, int n) const;	//회원 검색 함수(전화번호)
	void print_member(base_management* member) const;								//회원 명부 출력 함수
	void delete_member(base_management* member);			//회원 정보 삭제 함수
	~base_management();	

	void additional_add_member(base_management* member);				//회원 추가 함수
	void additional_rewrite_member(base_management* member);			//회원 정보 수정
	void additional_search_member(base_management* member) const;		//회원 검색 함수(담당 트레이너)

};

//일반 회원 클래스
class normal_member : public base_management
{
};

// 스피닝 클래스 - 추가 관리 클래스의 상속
class spinning_member : public base_management
{
};

// PT 클래스 - 추가 관리 클래스의 상속
class pt_member : public base_management
{
};

// 필라테스 클래스 - 추가 관리 클래스의 상속
class pilates_member : public base_management
{
};