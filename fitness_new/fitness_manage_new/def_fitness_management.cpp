#include "def_fitness_management.h"
#define Members 255 // �ڵ忡�� ����� �迭�� ũ��(ȸ����)�� ��ũ�η� ����

base_management* member;							//ȸ�� ���� �� ���� �迭�� ����Ű�� ���� ������ ����
int universal_numb = 0;							//�޴� ��ȣ ����
int member_Classification = 0;				//ȸ�� ���� ����

void menu_fitness_management()
{
	cout << "-----<�ｺ�� ȸ������ ���α׷� ����ȭ��>-----" << endl << endl;
	cout << "1. �Ϲ� ȸ��" << endl;
	cout << "2. ���Ǵ� ȸ��" << endl;
	cout << "3. PT ȸ��" << endl;
	cout << "4. �ʶ��׽� ȸ��" << endl << endl;
	cout << "���Ͻô� ȸ�� ���� ��ȣ�� �������ּ���. : ";
	cin >> member_Classification;
	cout << endl;

	switch (member_Classification) //ȸ�����п� ���� �ٸ� �������� �����Ѵ�.
	{
	case NORMAL:
		cout << "�Ϲ� ȸ���� �����ϼ̽��ϴ�." << endl << endl;
		cout << "-----<�Ϲ� ȸ������ �޴�>-----" << endl << endl;
		member = new normal_member[Members]; //�޸� ������ ���� �����Ҵ����� ȸ�� ��ü�迭�� �����Ѵ�.
		break;

	case SPINNING:
		cout << "���Ǵ� ȸ���� �����ϼ̽��ϴ�." << endl << endl;
		cout << "-----<���Ǵ� ȸ������ �޴�>-----" << endl << endl;
		member = new spinning_member[Members];
		break;

	case PT:
		cout << "PT ȸ���� �����ϼ̽��ϴ�." << endl << endl;
		cout << "-----<PT ȸ������ �޴�>-----" << endl << endl;
		member = new pt_member[Members];
		break;

	case PILATES:
		cout << "�ʶ��׽� ȸ���� �����ϼ̽��ϴ�." << endl << endl;
		cout << "-----<�ʶ��׽� ȸ������ �޴�>-----" << endl << endl;
		member = new pilates_member[Members];
		break;

	default:
		cout << "�ش� ��ȣ�� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���." << endl;
		cout << "���� ���α׷��� �����ϰ� �����ôٸ� 'Ctrl + C'�� �����ּ���." << endl << endl;
		menu_fitness_management();
	}

	//�� Ŭ������ ȸ������ �޴�
	cout << "1. ȸ�� �߰�" << endl;
	cout << "2. ȸ�� ���� ����(���� ����, ��Ŀ, ���)" << endl;
	cout << "3. ȸ�� �˻�(�̸�, ��ȭ��ȣ, ��� Ʈ���̳� �˻� ����)" << endl;
	cout << "4. ȸ�� ��� ���(������ ��� ����)" << endl;
	cout << "5. ȸ�� ����" << endl << endl;

	cout << "���Ͻô� �޴� ��ȣ�� �������ּ���. : ";
	cin >> universal_numb;
	cout << endl;

	//switch���� ���� �޴��� �����Ѵ�.
	switch (universal_numb)
	{
	case 1:
		cout << "ȸ�� �߰� ȭ���Դϴ�." << endl << endl;
		member->add_member(member);
		if (member_Classification != NORMAL)	 //�Ϲ� ȸ���� �ƴ϶�� �߰� ���� �Է�
			member->additional_add_member(member);
		break;

	case 2:
		cout << "ȸ�� ���� ���� ȭ���Դϴ�." << endl << endl;
		member->rewrite_member(member);
		break;

	case 3:
		cout << "ȸ�� �˻� ȭ���Դϴ�." << endl; 
		cout << "1. �̸� " << endl << "2. ��ȭ��ȣ " << endl << "3. ��� Ʈ���̳� " << endl << "�˻� �о߸� �������ּ���. : "  << endl;
		cin >> universal_numb;
		if (universal_numb == 1)
			member->search_member(member);
		else if (universal_numb == 2) {}
			//member->search_member(member, universal_numb);
		else if (universal_numb == 3) {}
			//member->additional_search_member(member);
		else
		{
			cout << "�ش� ��ȣ�� �������� �ʽ��ϴ�. ȸ�� ���� �������� ���ư��ϴ�." << endl;
			menu_fitness_management();
		}

	case 4:
		cout << "ȸ�� ��� ��� ȭ���Դϴ�." << endl << endl;
		member->print_member(member);
		break;

	case 5:
		cout << "ȸ�� ���� ȭ���Դϴ�." << endl << endl;
		member->delete_member(member);
		break;

	default:
		cout << "�ش� ��ȣ�� �������� �ʽ��ϴ�. ȸ�� ���� ȭ������ ���ư��ϴ�." << endl;
		cout << "���� ���α׷��� �����ϰ� �����ôٸ� 'Ctrl + C'�� �����ּ���." << endl << endl;
		menu_fitness_management();
	}
}

//�����Լ� ���Ǻ�, ��������� ���� �ʱ�ȭ�� �����Ѵ�.
base_management::base_management()
{
	//string ���� : �������� �ʱ�ȭ
	normal_name = " ";			//�̸�
	normal_hpnumber = " ";		//�ڵ��� ��ȣ
	normal_gender = " ";		//����
	class_day = " ";			//��������
	trainer = " ";				//��� Ʈ���̳�

	//int, char, bool ���� : false �Ǵ� 0���� �ʱ�ȭ
	normal_member_number = 0;	//ȸ����ȣ
	normal_start = 0;			//������
	normal_end = 0;				//������
	normal_clothes = false;		//��� �뿩����
	class_time = 0;				//�����ð�
	
}

//ȸ�� �߰��Լ� ���ǹ�
void base_management::add_member(base_management* member)
{
	unsigned char member_index = 0;			//�迭���� ����� ȸ�� �ε��� ����
	bool cnt = false;						//�ο� �ʰ��� Ȯ���ϴ� ����

	for (int i = 0; i < Members; i++)		//�ݺ����� ���� �� �ε����� ȸ�� �ε���, ȸ�� ��ȣ�� �����Ѵ�.
	{
		if (member[i].normal_member_number == 0)	 //�� �ε����� �ִٸ� �ݺ����� ���� 
		{
			member_index = i;						
			member[member_index].normal_member_number = i + 1;
			cnt = true;
			break;
		}
	}

	if (!cnt)		//�ݺ��� ���� �Ŀ��� cnt���� false��� �ο� �ʰ�						
	{
		cout << "�ｺ�� ���� ���� �ο��� �ʰ��߽��ϴ�." << endl << endl;
		return;
	}
	char normal_memebership; //ȸ���� �Ⱓ ����
	
	cout << "�߰��� ȸ������ ������ �Է����ּ���." << endl;
	cout << "�̸� : ";
	cin >> member[member_index].normal_name;
	cout << "�ڵ��� ��ȣ (010-0000-0000): ";
	cin >> member[member_index].normal_hpnumber;
	cout << "���� (��/��) : ";
	cin >> member[member_index].normal_gender;
	cout << "������(YYYYMMDD) : ";
	cin >> member[member_index].normal_start;
	cout << "ȸ���� ����(���� �� �Է�) : ";
	cin >> normal_memebership;
	normal_end = normal_start + normal_memebership * 30;
	cout << "��� �뿩 ���� (y/n) : ";
	cin >> universal_numb;
	member[member_index].normal_clothes = (universal_numb == 'y') ? true : false; //���׿�����
}

void base_management::search_member(base_management* member) const
{

}

void base_management::rewrite_member(base_management* member)
{
	member->print_member(member);
	cout << "������ ȸ������ ��ȣ�� �Է����ּ���. : ";

}


void base_management::print_member(base_management* member) const
{
	cout << "ȸ�� ��� ����� �����ϼ̽��ϴ�." << endl;
	cout << "ȸ�� ��ȣ | �̸� | �ڵ��� ��ȣ | ���� | ȸ���� ������ | ȸ���� ������ | ��� �뿩 ����" << endl << endl;
	for (int i = 0; i < Members; ++i)
	{
		if (member[i].normal_member_number != 0) {					//���� �ִ� �迭�� ���
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
	cout << "������ ȸ������ ȸ�� ��ȣ�� �Է����ּ���. : ";
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

	cout << member[universal_numb].normal_name << "ȸ������ ������ �����Ǿ����ϴ�." << endl << endl;
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

