#include <iostream>
#include <vector>

using namespace std;

vector <long long int> budget;
int N;
long long int M;

long long int calculateMax()
{
	// 최대값 계산하기 (잘못된 방법)
	/*
	최대 예산 M을 N으로 나눈 값.
	그 값 이하인 지방 예산들은 상관이 없음. 그냥 예산을 그대로 주면 됨.
	그 값 이하인 지방 예산들에 대해서는, M - (작은 지방 예산들의 합) = 남은 금액
	남은 금액을 (남은 지방의 수)로 나누기.

	그렇게 계산한 값이, 최대 예산
	
	==>> 이 계산방식은 남은 지방 예산들이, 평균보다 이상일 때에만 해당되는 방식
	*/
	//long long int criteria = M / N;
	//long long int sum = 0;
	//int ele = 0;
	//for (int i = 0; i < N; i++)
	//{
	//	if (budget[i] <= criteria)
	//	{
	//		sum += budget[i];
	//		ele++;
	//	}
	//}

	//long long int rest = M - sum;
	//long long int restNum = N - ele;

	//return (rest / restNum);

	long long int criteria = M / N;
	int sum = 0;
	int max = 0;	// return 할 최대 예산값들 중 최댓값
	for (int i = criteria; i < M; i++)
	{
		sum = 0;
		for (int j = 0; j < N; j++)
		{
			if (budget[j] <= i)
			{
				sum += budget[j];
			}
			else
			{
				sum += i;
			}
		}
		if (sum <= M)
		{
			max = i;
		}
		else
		{
			return max;
			//break;	// for문 종료. 이전 텀에 저장했던 max값이 예산들 중 최댓값인 것.
		}
	}
}
int main()
{
	cin >> N;
	long long int sum=0;
	long long int budgetMax = 0;	// 각 지방에서 필요로 하는 예산들 중 최대값
	long long int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		budget.push_back(input);
		sum += input;

		if (budget[i] > budgetMax)
		{
			budgetMax = budget[i];
		}
	}

	cin >> M;

	if (M>= sum)
	{
		cout << budgetMax;
		return 0;
	}
	else
	{

		cout << calculateMax();
		return 0;
	}
}