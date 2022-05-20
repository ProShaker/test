#include "def_fitness_management.h"
#define y true
#define n true

//���α׷� ���� ������ �޴� ȭ���� ��� ����Ѵ�.
void action_fitness_management()
{
	while (1)
	{
		menu_fitness_management();
	}
}

//�޴� ȭ���� ����ϴ� �Լ� ���ǹ�
void menu_fitness_management()
{

	cout << "-----<�ｺ�� ȸ������ ���α׷� ����ȭ��>-----" << endl << endl;
	cout << "1. ȸ�� �߰�" << endl;
	cout << "2. ȸ�� ���� ����(��Ŀ, ���, ���� ����)" << endl;
	cout << "3. ȸ�� �˻�" << endl;
	cout << "4. ȸ�� ��� ���" << endl;
	cout << "5. ȸ�� ����" << endl << endl;

	cout << "-----<���Ͻô� �޴� ��ȣ�� �������ּ���.>-----" << endl;
	cin >> menu_numb;
	cout << endl;
	cout << "-----<" << menu_numb << "�� �޴� ȭ���Դϴ�.>-----" << endl;

	//switch���� ���� �޴��� �����Ѵ�.
	switch (menu_numb)
	{
	case 1:
		cout << "ȸ�� �߰� ȭ���Դϴ�." << endl;
		normal_management.add_member()
		add_member();
		break;

	case 2:
		cout << "ȸ�� ���� ���� ȭ���Դϴ�." << endl;
		normal_management.rewrite_member();
		break;

	case 3:
		cout << "ȸ�� �˻� ȭ���Դϴ�." << endl;
		normal_management.search_member();
		break;

	case 4:
		cout << "ȸ�� ��� ��� ȭ���Դϴ�." << endl;
		normal_management.print_member();
		break;

	case 5:
		cout << "ȸ�� ���� ȭ���Դϴ�." << endl;
		normal_managemen.delete_member();
		break;

	//1 ~ 5 �̿��� ���ڸ� �� ��� �޴� �Լ��� ��ȣ���Ѵ�.
	default:
		cout << "�ش� ��ȣ�� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���." << endl;
		cout << "���� ���α׷��� �����ϰ� �����ôٸ� Ctrl + K�� �����ּ���." << endl;
		menu_fitness_management();
	}
}

//ȸ�� ���� ���� �Լ�
void separate_member()
{
	cout << "ȸ�� ������ �������ּ���." << endl;
	cout << "1. �Ϲ� ȸ��" << endl;
	cout << "2. ���Ǵ� ȸ��" << endl;
	cout << "3. PT ȸ��" << endl;
	cout << "4. �ʶ��׽� ȸ��" << endl << endl;
	cout << "5. �ڷ� ����" << endl << endl;

	cout << "-----<���Ͻô� ȸ�� ���� ��ȣ�� �������ּ���.>-----" << endl;
	cin >> menu_numb;

	switch(menu_numb)
	{
	case NORMAL:
		cout << "�Ϲ� ȸ���� �����ϼ̽��ϴ�." << endl;
		break;

	case SPINNING:
		cout << "���Ǵ� ȸ���� �����ϼ̽��ϴ�." << endl;
		break;

	case PT:
		cout << "PT ȸ���� �����ϼ̽��ϴ�." << endl;
		break;

	case PILATES:
		cout << "�ʶ��׽� ȸ���� �����ϼ̽��ϴ�." << endl;
		break;

	case reTurn:
		cout << "�ڷ� ���⸦ �����ϼ̽��ϴ�." << endl;
		normal_management.reTurn();
		break;
		
	//1 ~ 5 �̿��� ���ڸ� �� ��� ȸ�� ���� �Լ��� ��ȣ���Ѵ�.
	default:
		cout << "�ش� ��ȣ�� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���." << endl;
		separate_member();
	}
}


//ȸ�� �߰� �Լ� ���ǹ�
void normal_management::add_member()
{
	separate_member();

	cout << endl;

	cout << "�߰��� ȸ������ ������ �Է����ּ���." << endl;
	cout << "�̸� : ";
	cin >> normal_name;
	cout << "�ڵ��� ��ȣ (�� 8�ڸ�): ";
	cin >> normal_hpnumber;
	cout << "���� (��/��) : ";
	cin >> normal_gender;
	cout << "������(YYYYMMDD) : ";
	cin >> normal_start;
	cout << "ȸ���� ����(1, 3, 6, 12����) : ";
	cin >> memebership;
	cout << "��� �뿩 ���� (y/n) : ";
	cin >> normal_clothes;
	cout << "��Ŀ ��뿩�� (y/n) : ";
	cin >> normal_locker;
	//���Ŀ� ��Ŀ ��ȣ �����ϴ� �κе� ����غ���

	//���Ǵ� ���� �� �߰� �Է�
	if (menu_numb == SPINNING)
	{
		//���Ǵ��� Ư�� �κ�
	}

	//PT ���� �� �߰� �Է�
	else if (menu_numb == PT)
	{
		//PT�� Ư�� �κ�
	}

	//�ʶ��׽� ���� �� �߰� �Է�
	else
	{
		//�ʶ��׽��� Ư�� �κ�
	}

}

//ȸ�� ���� ���� �Լ� ���ǹ�
void normal_management::rewrite_member()
{
	separate_member();
}

//ȸ�� �˻� �Լ� ���ǹ�
void normal_management::search_member()
{
	separate_member();

}

//ȸ�� ��� ��� �Լ� ���ǹ�
void normal_management::print_member()
{
	separate_member();

}

//ȸ�� ���� �Լ� ���ǹ�
void normal_management::delete_member()
{
	separate_member();

}
// �ڷ� ���� �Լ�
int normal_management::reTurn()
{
	return 0;
}