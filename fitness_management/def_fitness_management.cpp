#include "def_fitness_management.h"
#define y true
#define n false
#define Members 150 // �ڵ忡�� ����� �迭�� ũ��(ȸ����)�� ��ũ�η� ����
int menu_numb = 0; //�޴� ��ȣ ����

void menu_fitness_management()
{
	cout << "-----<�ｺ�� ȸ������ ���α׷� ����ȭ��>-----" << endl << endl;
	cout << "1. �Ϲ� ȸ��" << endl;
	cout << "2. ���Ǵ� ȸ��" << endl;
	cout << "3. PT ȸ��" << endl;
	cout << "4. �ʶ��׽� ȸ��" << endl << endl;
	cout << "���Ͻô� ȸ�� ���� ��ȣ�� �������ּ���. : ";
	cin >> member_Classification;

	switch (member_Classification) //ȸ�����п� ���� �ٸ� �������� �����Ѵ�.
	{
	case NORMAL:
		cout << "�Ϲ� ȸ���� �����ϼ̽��ϴ�." << endl << endl;
		cout << "-----<�Ϲ� ȸ������ �޴�>-----" << endl << endl;
		normal_management* member = new normal_management[Members]; //�޸� ������ ���� �����Ҵ����� ȸ�� ��ü�迭�� �����Ѵ�.
		break;

	case SPINNING:
		cout << "���Ǵ� ȸ���� �����ϼ̽��ϴ�." << endl << endl;
		cout << "-----<���Ǵ� ȸ������ �޴�>-----" << endl << endl;
		spinning_management* member = new spinning_management[Members];
		break;

	case PT:
		cout << "PT ȸ���� �����ϼ̽��ϴ�." << endl << endl;
		cout << "-----<PT ȸ������ �޴�>-----" << endl << endl;
		pt_management* member = new pt_management[Members];
		break;

	case PILATES:
		cout << "�ʶ��׽� ȸ���� �����ϼ̽��ϴ�." << endl << endl;
		cout << "-----<�ʶ��׽� ȸ������ �޴�>-----" << endl << endl;
		pilates_management* member = new pilates_management[Members];
		break;

	default:
		cout << "�ش� ��ȣ�� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���." << endl;
		cout << "���� ���α׷��� �����ϰ� �����ôٸ� 'Ctrl + C'�� �����ּ���." << endl << endl;
		menu_fitness_management();
	}

	//�� Ŭ������ ȸ������ �޴�
	cout << "1. ȸ�� �߰�" << endl;
	cout << "2. ȸ�� ���� ����(��Ŀ, ���, ���� ����)" << endl;
	cout << "3. ȸ�� �˻�" << endl;
	cout << "4. ȸ�� ��� ���" << endl;
	cout << "5. ȸ�� ����" << endl << endl;

	cout << "-----<���Ͻô� �޴� ��ȣ�� �������ּ���.>-----" << endl;
	cin >> menu_numb;
	cout << endl;

	//switch���� ���� �޴��� �����Ѵ�.
	//������ ���� 1: ȸ�� ���� switch������ ȸ�� �����ؼ� �����Ҵ��� �ߴµ� �� ��Ҹ� ��� �Ʒ��� switch������ ������ ������
	switch (menu_numb)
	{
	case 1:
		cout << "ȸ�� �߰� ȭ���Դϴ�." << endl;
		member->add_member(normal_management * member);
		break;

	case 2:
		cout << "ȸ�� ���� ���� ȭ���Դϴ�." << endl;
		member->rewrite_member(normal_management * member);
		break;

	case 3:
		cout << "ȸ�� �˻� ȭ���Դϴ�." << endl;
		member->search_member(normal_management * member);
		break;

	case 4:
		cout << "ȸ�� ��� ��� ȭ���Դϴ�." << endl;
		member->print_member();
		break;

	case 5:
		cout << "ȸ�� ���� ȭ���Դϴ�." << endl;
		member->delete_member(normal_management * member);
		break;

	default:
		cout << "�ش� ��ȣ�� �������� �ʽ��ϴ�. ȸ�� ���� ȭ������ ���ư��ϴ�." << endl;
		cout << "���� ���α׷��� �����ϰ� �����ôٸ� 'Ctrl + C'�� �����ּ���." << endl;
		menu_fitness_management();
	}
}

//�⺻ �����Լ� ���ǹ�, �� ������ �ʱ�ȭ ���ش�.
normal_management::normal_management()
{
private:								//���������� private���� ��ȣ�Ѵ�.
	char* normal_name = NULL;			//�̸�
	char* normal_hpnumber = NULL;		//�ڵ��� ��ȣ
	char* normal_gender = NULL;			//����

public:
	int normal_member_number = 0;     //ȸ����ȣ
	int normal_start = 0;			//������
	int normal_end = 0;				//������
	int normal_memebership = 0;		//ȸ���� �Ⱓ
	bool normal_clothes = false;	//��� �뿩����
	int normal_locker = 0;			//��Ŀ ��뿩��
}

// �Ϲ� ȸ�� �߰� �Լ� ���ǹ�
// ����2 : �� Ŭ�������� add_member�� �����ϴ� �ͺ��� ȿ������ ���� ����� ������
void normal_management::add_member(normal_management* member)
{
	cout << "ȸ�� �߰��� �����ϼ̽��ϴ�." << endl;
	int member_index = NULL;				//�迭���� ȸ���� �ε��� ����
	for (int i = 0; i < Members; i++)		//�ݺ����� ���� �� �ε����� ã�´�.
		{
			if (member[i].normal_member_number == 0)  //�� �ε����� �ִٸ� �ݺ����� ���� 
			{	
				member_index = i;					//member_index�� ȸ����ȣ�� �ε��� ���� �Ҵ��Ѵ�.
				member[member_index].normal_member_number = i;
				break;
			}

		}
	//�ݺ����� ���� �Ŀ��� member_index�� NULL�̶�� �� �ڸ��� �����Ƿ� �Լ��� �����Ѵ�.
	if (member_index == NULL)	
	{
		cout << "�ｺ�� �����ο��� �ʰ��߽��ϴ�.";
		return;
	}
	
	cout << "�߰��� ȸ������ ������ �Է����ּ���." << endl;
	cout << "�̸� : ";
	cin >> member[member_index].normal_name;
	cout << "�ڵ��� ��ȣ (0000-0000): ";
	cin >> member[member_index].normal_hpnumber;
	cout << "���� (��/��) : ";
	cin >> member[member_index].normal_gender;
	cout << "������(YYYYMMDD) : ";
	cin >> member[member_index].normal_start;
	cout << "ȸ���� ����(1, 3, 6, 12���� �� ����) : ";
	cin >> member[member_index].normal_memebership;
	normal_end = normal_start + normal_memebership * 30;
	cout << "��� �뿩 ���� (y/n) : ";
	cin >> member[member_index].normal_clothes;
	cout << "���� ��Ŀ ��뿩�� (y/n) : ";
	cin >> member[member_index].normal_locker;
	if (normal_locker == y) {
		cout << "��Ŀ ��ȣ�� ȸ����ȣ�� �����˴ϴ�." << endl;
		normal_locker = member_index;
	}
}

//ȸ�� ��� ��� �Լ� ���ǹ�
void normal_management::print_member()
{
	cout << "ȸ�� ��� ����� �����ϼ̽��ϴ�." << endl;
	cout << "ȸ�� ��ȣ | �̸� | �ڵ��� ��ȣ | ���� | ȸ���� ������ | ȸ���� ������ | ��� �뿩 ���� | ���ζ�Ŀ ��뿩��" << endl << endl;
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

//ȸ�� �˻� �Լ� ���ǹ�
void normal_management::search_member(normal_management* member)
{
	cout << "ȸ���˻��� �����ϼ̽��ϴ�. �˻� �о߸� �������ּ���." << endl;
	cout << "1. �̸�, 2. �ڵ��� ��ȣ, 3. ����" << endl;
	cin >> menu_numb;

	switch (menu_numb)
	{
	case 1:
		cout << "�̸� �˻��� �����ϼ̽��ϴ�."
	}
	//220517 11:43 �ڵ� �ۼ� ���� : ���� - ����
}
//ȸ�� ���� ���� �Լ� ���ǹ�
void normal_management::rewrite_member(normal_management* member)
{

}


//ȸ�� ���� �Լ� ���ǹ�
void normal_management::delete_member(normal_management* member)
{

}

//�޴� ȭ���� ����ϴ� �Լ� ���ǹ�


