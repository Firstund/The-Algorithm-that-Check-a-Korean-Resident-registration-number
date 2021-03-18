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
	cout << "지역: ";

	if (a >= 0 && a < 9)
	{
		cout << "서울" << endl;
	}
	else if (a < 13)
	{
		cout << "부산" << endl;
	}
	else if (a < 16)
	{
		cout << "인천" << endl;
	}
	else if (a < 19)
	{
		cout << "경기도 주요도시" << endl;
	}
	else if (a < 26)
	{
		cout << "주요도시 외의 경기도" << endl;
	}
	else if (a < 35)
	{
		cout << "강원도" << endl;
	}
	else if (a < 40)
	{
		cout << "충청북도" << endl;
	}
	else if (a < 48)
	{
		cout << "충청남도" << endl;
	}
	else if (a < 55)
	{
		cout << "전라북도" << endl;
	}
	else if (a < 67)
	{
		cout << "전라남도" << endl;
	}
	else if (a < 91)
	{
		cout << "경상도" << endl;
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
	int data[5] = { 0, }; // 출생 연도, 출생 월, 출생 일, 성별, 출생 지역
	int dataNum = 0;

	time_t t = time(NULL);
	struct tm* pLocal = localtime(&t);
	

	cout << "주민등록번호를 - 없이 입력하세요." << endl;

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

		cout << "출생 날짜 : " << data[0] << "년 " << data[1] << "월 " << data[2] << "일 " << endl;

		if ((data[3] % 2) == 1)
			cout << "\n성별 : 남자" << endl;
		else
			cout << "\n성별 : 여자" << endl;

		cout << "나이: " << ((pLocal->tm_year + 1900) - data[0]) + 1 << "살" << endl;

		CheckLocal(data[4]);
	}
	catch (bool a)
	{
		cout << "유효하지 않은 주민등록번호" << endl;
	}

	return(0);
}