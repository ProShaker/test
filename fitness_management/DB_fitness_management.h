//#pragma once
//#include <cstring>
//	
////자주 사용하는 변수를 상수화한다.
//const int members = 100;


//회원 구분을 위한 열거형
enum {NORMAL = 1, SPINNING, PT,	PILATES};

////회원의 개인정보를 저장할 3차원 배열의 동적할당, member[4][100][11]의 선언
////member[0] == member[NORMAL] : 일반회원 데이터 베이스 영역
////member[1] == member[SPINNING] : 스피닝회원 데이터 베이스 영역
////member[2] == member[PT] : PT회원 데이터 베이스 영역
////member[3] == member[PILATES] : 필라테스 회원 데이터 베이스 영역
//
//char *** member = new char **[4];
//for (int i = 0; i < 4; i++)
//{
//	member[i] = new char* [100];
//	for (int j = 0; j < 100; j++)
//	{
//		member[i][j] = new char[11];
//	}
//}
//
//
////-----일반 회원 데이터 베이스-----
//// 일반 회원 이름 배열
//char *normal_name[members] = {0};
//strcpy(normal_name[0], "원종찬");
//
////일반회원 핸드폰 번호 배열
//char normal_hpnumber[members] = { 0 };
//strcpy(normal_hpnumber[0], "40248406");
//
//char normal_gender[members];
//strcpy(normal_gender[0], "남자");
//
//int normal_start[members] = { 180206 };
//int normal_end[members] = { 230706 };
//bool normal_clothes[members] = { 1 };
//
////-----일반 회원 데이터 베이스-----
// 
////-----스피닝 회원 데이터 베이스-----
////스피닝 회원 이름 배열
//char spining_name[members] = { 0 };
//strcpy(spining_name[0], "황영민");
//
////스피닝회원 핸드폰 번호
//char spining_hpnumber[members] = { 0 };
//strcpy(spining_hpnumber[0], "25961092");
//
//char spining_gender[10];
//strcpy(spining_gender[0], "남자");
//
//char spining_week[10];
//strcpy(spining_week[0], "월");
//
//int spining_start[10] = { 190613 };
//int spining_end[10] = { 241213 };
//bool spining_clothes[10] = { 0 };
//
////-----스피닝 회원 데이터 베이스-----
//
////-----PT 회원 데이터 베이스-----
//
////PT회원 이름 배열
//char PT_name[10] = { 0 };
//strcpy(PT_name[0], "이수빈");
//
////PT회원 핸드폰 번호
//char PT_hpnumber[10] = { 0 };
//strcpy(PT_hpnumber[0], "41121741");
//
////PT회원 이름 배열
//char PT_gender[10];
//strcpy(PT_gender[0], "여자");
//
//char spining_week[10];
//strcpy(spining_week[0], "월");
//
//int spining_start[10] = { 190613 };
//int spining_end[10] = { 241213 };
//bool spining_clothes[10] = { 0 };
//
////-----스피닝 회원 데이터 베이스-----
//
//
//
////필라테스회원 이름 배열
//char pilates_name[10] = { 0 };
//strcpy(pilates_name[0], "김성진");
//
////필라테스회원 핸드폰 번호
//char pilates_hpnumber[10] = { 0 };
//strcpy(pilates_hpnumber[0], "85200258");
//
////회원 성별
//
//char pilates_gender[10];
//strcpy(pilates_gender[0], "남자");
//
////특별반 수강요일
//
//char PT_week[10];
//strcpy(PT_week[0], "수");
//char pilates_week[10];
//strcpy(pilates_week[0], "목");
//
////특별반 담당 트레이너
//char trainer[4];
//strcpy(trainer[0], "조광호,이도윤,김형준,김기용");
//strcpy(trainer[1], "조광호");
//strcpy(trainer[2], "이도윤");
//strcpy(trainer[3], "김형준");
//
////회원권 시작 일자
//
//
//int PT_start[10] = { 200531 };
//int pilates_start[10] = { 190122 };
//
////회원권 종료 일자
//int PT_end[10] = { 250331 };
//int pilates_end[10] = { 230322 };
//
////운동복 대여 여부
//
//bool PT_clothes[10] = { 0 };
//bool pilates_clothes[10] = { 0 };
//
////락커 사용여부
//bool normal_locker[10] = { false };
//bool spining_locker[10] = { false };
//bool PT_locker[10] = { true };
//bool pilates_locker[10] = { true };
//
//
//for (int i = 0; i < 4; i++) {
//	if (i == 0) {
//		for (int j = 0; j < 9; j++) {
//			member[normal][j][0] = normal_name[j];
//			member[normal][j][1] = normal_hpnumber[j];
//			member[normal][j][2] = normal_gender[j];
//			member[normal][j][3] = normal_start[j];
//			member[normal][j][4] = normal_end[j];
//			member[normal][j][5] = normal_cloths[j];
//			member[normal][j][6] = normal_locker[j];
//		}
//	}
//	if (i == 1) {
//		for (int j = 0; j < 9; j++) {
//			member[spining][j][0] = spining_name[j];
//			member[spining][j][1] = spining_hpnumber[j];
//			member[spining][j][2] = spining_gender[j];
//			member[spining][j][3] = spining_start[j];
//			member[spining][j][4] = spining_end[j];
//			member[spining][j][5] = spining_cloths[j];
//			member[spining][j][6] = spining_locker[j];
//			member[spining][j][7] = spining_week[j];
//			member[spining][j][8] = trainer[j];
//		}
//	}
//	if (i == 2) {
//		for (int j = 0; j < 9; j++) {
//			member[PT][j][0] = PT_name[j];
//			member[PT][j][1] = PT_hpnumber[j];
//			member[PT][j][2] = PT_gender[j];
//			member[PT][j][3] = PT_start[j];
//			member[PT][j][4] = PT_end[j];
//			member[PT][j][5] = PT_cloths[j];
//			member[PT][j][6] = PT_locker[j];
//			member[PT][j][7] = PT_week[j];
//			member[PT][j][8] = trainer[j];
//		}
//	}
//	if (i == 3) {
//		for (int j = 0; j < 9; j++) {
//			member[pilates][j][0] = pilates_name[j];
//			member[pilates][j][1] = pilates_hpnumber[j];
//			member[pilates][j][2] = pilates_gender[j];
//			member[pilates][j][3] = pilates_start[j];
//			member[pilates][j][4] = pilates_end[j];
//			member[pilates][j][5] = pilates_cloths[j];
//			member[pilates][j][5] = pilates_locker[j];
//			member[pilates][j][7] = pilates_week[j];
//			member[pilates][j][8] = trainer[j];
//		}
//	}
//}




