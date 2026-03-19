#include <iostream>

using namespace std;
int main()
{
	int N;
	cin >> N;
	int spaceNum;	// 출력할 공백 개수
	int starNum;	// 출력할 별의 개수
	for (int i = 0; i < N; i++)
	{
		spaceNum = N - 1 - i;
		starNum = N - spaceNum;
		for (int j = 0; j < spaceNum; j++)
		{
			cout << ' ';
		}
		for (int j = 0; j < starNum; j++)
		{
			cout << '*';
		}
		cout << "\n";
	}
	for (int i = N-2; i>=0; i--)
	{
		spaceNum = N - 1 - i;
		starNum = N - spaceNum;
		for (int j = 0; j < spaceNum; j++)
		{
			cout << ' ';
		}
		for (int j = 0; j < starNum; j++)
		{
			cout << '*';
		}
		cout << "\n";
	}
}