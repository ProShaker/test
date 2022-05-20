#pragma once
#include <iostream>
using namespace std;

const int name_len = 11;

void action_fitness_management();

void menu_fitness_management();

//�޴� ��ȣ�� ������ ����, �޸� ������ ���� char �ڷ����� ����Ѵ�.
char menu_numb;

enum {
	NORMAL = 1,
	SPINNING,
	PT,
	PILATES,
	reTurn
};
//�Ϲ� ȸ�� Ŭ����
class normal_management {

//���������� private���� ��ȣ�Ѵ�.
private:
	//�̸�, �ڵ��� ��ȣ, ����
	char *normal_name;
	int normal_hpnumber;
	char normal_gender;

public:
//� ������, ��� ���� ������ �������� ���� �ٷ�� ���ϰ� �Ѵ�.
//ȸ���� �����Ͽ� const Ű���带 ����ؼ� �̿�� ������ ���� ���� ȸ���� �������̴�.
	const int normal_start;
	int normal_end;
	char memebership;
	bool normal_clothes;
	char normal_locker;

	void add_member();
	void rewrite_member();
	void search_member();
	void print_member();
	void delete_member();
	int reTurn();
};

// Ư�� Ŭ���� - �븻 Ŭ������ ���
class special_management : normal_management
{
public:
	//���� �ð�ǥ, ���� ����, Ʈ���̳� �̸�, �� PT Ƚ��
	char class_time;
	char class_day[2];
	char trainer[name_len];
	const int PT_number;
};

// ���Ǵ� Ŭ���� - Ư�� Ŭ������ ���
class spinning_management : special_management
{
};

// PT Ŭ���� - Ư�� Ŭ������ ���
class pt_management : special_management
{
};

// �ʶ��׽� Ŭ���� - Ư�� Ŭ������ ���
class pilates_management : special_management
{
};


