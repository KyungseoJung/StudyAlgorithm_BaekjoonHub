#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
//#include <cctype>

using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	// 정보 입력 ----------
	int n;
	cin >> n;

	int numOfInfo = 4;
	string info[100][4];	// 100행 5열
	int earliestYear = 9999; 
	int latestYear = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < numOfInfo; j++)	// 4가지 정보를 입력할 것이니까
		{
			cin >> info[i][j];
			if (j == numOfInfo-1)	// 연도에 대해서
			{
				if (stoi(info[i][j]) < earliestYear)	// 가장 일찍 태어난 사람의 연도를 저장
				{
					earliestYear = stoi(info[i][j]);
				}
				if (stoi(info[i][j]) > latestYear)	// 가장 늦게 태어난 사람의 연도를 저장
				{
					latestYear = stoi(info[i][j]);
				}
			}
		}
	}

	// (1) 가장 나이가 적은 사람 찾기
	int youngestEle = 0;	// 일단 첫 번째 사람이 가장 어리다고 가정하고 아래 과정 거치기
	for (int i = 0; i < n; i++)
	{
		if (stoi(info[youngestEle][3]) < stoi(info[i][3]))
		{
			youngestEle = i;
		}
		//else if (stoi(info[youngestEle][3]) > stoi(info[i][3]))
		//{
		//	continue;
		//}
		else if (stoi(info[youngestEle][3]) == stoi(info[i][3])) // 같은 연도에 태어났다면, 달을 비교
		{
			if (stoi(info[youngestEle][2]) < stoi(info[i][2]))
			{
				youngestEle = i;
			}
			//else if (stoi(info[youngestEle][2]) > stoi(info[i][2]))
			//{
			//	continue;
			//}
			else if (stoi(info[youngestEle][2]) == stoi(info[i][2])) // 같은 달에 태어났다면, 일을 비교
			{
				if (stoi(info[youngestEle][1]) < stoi(info[i][1]))
				{
					youngestEle = i;
				}
				//else if (stoi(info[youngestEle][1]) > stoi(info[i][1]))
				//{
				//	continue;
				//}
			}
		}
	}

	// (2) 가장 나이가 많은 사람 찾기
	int oldestEle = 0;		// 일단 첫 번째 사람이 가장 나이가 많다고 가정하고 아래 과정 거치기
	for (int i = 0; i < n; i++)
	{
		if (stoi(info[oldestEle][3]) > stoi(info[i][3]))
		{
			oldestEle = i;
		}
		else if (stoi(info[oldestEle][3]) == stoi(info[i][3]))	// 같은 연도에 태어났다면, 달을 비교
		{
			if (stoi(info[oldestEle][2]) > stoi(info[i][2]))
			{
				oldestEle = i;
			}
			else if (stoi(info[oldestEle][2]) == stoi(info[i][2]))	// 같은 월에 태어났다면, 일을 비교
			{
				if (stoi(info[oldestEle][1]) > stoi(info[i][1]))
				{
					oldestEle = i;
				}
			}
		}
	}

	cout << info[youngestEle][0] << "\n" << info[oldestEle][0];
	return 0;

}
