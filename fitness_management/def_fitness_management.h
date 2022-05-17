#pragma once
#include <iostream>
using namespace std;

int member_Classification = 0;	//ȸ�� ���� ����
void menu_fitness_management();
enum { NORMAL = 1, SPINNING, PT, PILATES };

//�Ϲ� ȸ�� Ŭ����
class normal_management {

//���������� private���� ��ȣ�Ѵ�.
private:
	char *normal_name;			//�̸�
	char *normal_hpnumber;		//�ڵ��� ��ȣ
	char *normal_gender;		//����

public:
//ȸ���� �����Ͽ� ȸ���� ������ ���� ���� ȸ���� �������̴�.
	int normal_member_number;	//ȸ����ȣ
	int normal_start;			//������
	int normal_end;				//������
	int normal_memebership;		//ȸ���� �Ⱓ
	bool normal_clothes;		//��� �뿩����
	int normal_locker;			//��Ŀ ��뿩�� �� ��Ŀ ��ȣ

	normal_management(normal_management *member);				//�����Լ�
	void add_member(normal_management* member);				//ȸ�� �߰� �Լ�
	void rewrite_member(normal_management* member);			//ȸ�� ���� ����
	void search_member(normal_management* member) const;		//ȸ�� �˻� �Լ�, ���� ���� ������ �����Ƿ� const ���
	void print_member() const;		//ȸ�� ��� ��� �Լ�, ���� ���� ������ �����Ƿ� const ���
	void delete_member(normal_management* member);			//ȸ�� ���� ���� �Լ�
	~normal_management();			//�����Լ�
};

// Ư�� Ŭ���� 
class special_management
{
public:
	//���� �ð�, ���� ����, Ʈ���̳� �̸�, �� PT Ƚ��
	int class_time;					//�����ð�
	char *class_day;				//��������
	char *trainer;					//��� Ʈ���̳�
	const int PT_number;			//�� PTȽ��
};

// ���Ǵ� Ŭ���� - Ư�� Ŭ������ ���
class spinning_management : protected special_management, protected normal_management
{
};

// PT Ŭ���� - Ư�� Ŭ������ ���
class pt_management : protected special_management, protected normal_management
{
};

// �ʶ��׽� Ŭ���� - Ư�� Ŭ������ ���
class pilates_management : protected special_management, protected normal_management
{
};


