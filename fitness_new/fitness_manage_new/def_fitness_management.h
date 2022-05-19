#pragma once
#include <iostream>							//������� ���� �������
#include <string>							//string Ŭ������ ����ϱ� ���� �������
using namespace std;						//string �ڷ����� ����ϱ� ���� ���ӽ����̽�
void menu_fitness_management();				//�޴� �Լ� ����
enum { NORMAL = 1, SPINNING, PT, PILATES }; //ȸ�� ������ ���� ������

// ���� ���, ȸ�� ���� ������ ��� �ִ� ��� Ŭ����
class base_management 
{

	//���������� protected�� ��ȣ�Ѵ�.
protected:
	string normal_name;			//�̸�
	string normal_hpnumber;		//�ڵ��� ��ȣ
	string normal_gender;		//����

public:
	unsigned char normal_member_number;	//ȸ����ȣ
				//ȸ���� �Ⱓ, �޸� ������ ���� char�ڷ����� ���
	bool normal_clothes;				//��� �뿩����
	int normal_start;					//������
	int normal_end;						//������

	//���Ǵ�, PT, �ʶ��׽� Ŭ������ ���� ����(���� �ð�, ���� ����, Ʈ���̳� �̸�, �� PT Ƚ��)
	char class_time;					//�����ð�
	string class_day;				//��������
	string trainer;					//��� Ʈ���̳�

	base_management();										
	void add_member(base_management* member);				//ȸ�� �߰� �Լ�
	void rewrite_member(base_management* member);			//ȸ�� ���� ����
	void search_member(base_management* member) const;			//ȸ�� �˻� �Լ�(�̸�) 
	void search_member(base_management* member, int n) const;	//ȸ�� �˻� �Լ�(��ȭ��ȣ)
	void print_member(base_management* member) const;								//ȸ�� ��� ��� �Լ�
	void delete_member(base_management* member);			//ȸ�� ���� ���� �Լ�
	~base_management();	

	void additional_add_member(base_management* member);				//ȸ�� �߰� �Լ�
	void additional_rewrite_member(base_management* member);			//ȸ�� ���� ����
	void additional_search_member(base_management* member) const;		//ȸ�� �˻� �Լ�(��� Ʈ���̳�)

};

//�Ϲ� ȸ�� Ŭ����
class normal_member : public base_management
{
};

// ���Ǵ� Ŭ���� - �߰� ���� Ŭ������ ���
class spinning_member : public base_management
{
};

// PT Ŭ���� - �߰� ���� Ŭ������ ���
class pt_member : public base_management
{
};

// �ʶ��׽� Ŭ���� - �߰� ���� Ŭ������ ���
class pilates_member : public base_management
{
};