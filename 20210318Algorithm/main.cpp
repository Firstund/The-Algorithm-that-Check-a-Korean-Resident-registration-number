#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

using namespace std;

int ChangeNum(char a)
{
	switch (a)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2; 
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	}
}
void CheckLocal(int a)
{
	cout << "����: ";

	if (a >= 0 && a < 9)
	{
		cout << "����" << endl;
	}
	else if (a < 13)
	{
		cout << "�λ�" << endl;
	}
	else if (a < 16)
	{
		cout << "��õ" << endl;
	}
	else if (a < 19)
	{
		cout << "��⵵ �ֿ䵵��" << endl;
	}
	else if (a < 26)
	{
		cout << "�ֿ䵵�� ���� ��⵵" << endl;
	}
	else if (a < 35)
	{
		cout << "������" << endl;
	}
	else if (a < 40)
	{
		cout << "��û�ϵ�" << endl;
	}
	else if (a < 48)
	{
		cout << "��û����" << endl;
	}
	else if (a < 55)
	{
		cout << "����ϵ�" << endl;
	}
	else if (a < 67)
	{
		cout << "���󳲵�" << endl;
	}
	else if (a < 91)
	{
		cout << "���" << endl;
	}
}
bool CheckRRNum(char rRNum[14])
{
	int result[13] = { 0, };

	int j = 2;
	int i = 0;
	int a = 0;

	for (i = 0; i < 13; i++)
	{
		if (i == 8)
			j = 2;
		if(i != 12)
			result[i] = ChangeNum(rRNum[i]) * j;
		else
		{
			result[i] = ChangeNum(rRNum[i]);
		}
		j++;
	}


	for (int i = 0; i < 12; i++)
	{
		a += result[i];
	}

	if (result[12] == ((11 - (a % 11)) % 10))
		return true;
	else
		return false;
}
int main()
{
	char rRNum[14] = { "", };
	int data[5] = { 0, }; // ��� ����, ��� ��, ��� ��, ����, ��� ����
	int dataNum = 0;

	time_t t = time(NULL);
	struct tm* pLocal = localtime(&t);
	

	cout << "�ֹε�Ϲ�ȣ�� - ���� �Է��ϼ���." << endl;

	cin >> rRNum;

	try
	{
		if (!CheckRRNum(rRNum))
			throw true;

		for (int i = 0; i < 13; i++)
		{
			if ((((i % 2) == 0) || (i == 7)) && (i != 8))
			{
				if (i == 6)
				{
					data[dataNum] += ChangeNum(rRNum[i]);
					dataNum++;
				}
				else
					data[dataNum] += (ChangeNum(rRNum[i]) * 10);
			}
			else
			{
				data[dataNum] += ChangeNum(rRNum[i]);

				dataNum++;
			}
		}

		if (data[3] <= 2)
			data[0] += 1900;
		else if (data[3] <= 4)
			data[0] += 2000;

		cout << "��� ��¥ : " << data[0] << "�� " << data[1] << "�� " << data[2] << "�� " << endl;

		if ((data[3] % 2) == 1)
			cout << "\n���� : ����" << endl;
		else
			cout << "\n���� : ����" << endl;

		cout << "����: " << ((pLocal->tm_year + 1900) - data[0]) + 1 << "��" << endl;

		CheckLocal(data[4]);
	}
	catch (bool a)
	{
		cout << "��ȿ���� ���� �ֹε�Ϲ�ȣ" << endl;
	}

	return(0);
}