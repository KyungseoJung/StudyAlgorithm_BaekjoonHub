#include <iostream>
#include <vector>

using namespace std;

bool checkPrimeNumber(int num)
{
	if ((num == 0) || (num == 1))	// 0과 1은 소수가 아님
		return false;

	if (num == 2)	// 2는 소수
		return true;
	if (num % 2 == 0)	// 짝수로 나누었을 때, 나머지가 0이면 그 수는 소수가 아님
		return false;
	for (int i = 3; i * i <= num; i += 2)	// 제곱근까지 계산했을 때 약수가 없으면, 제곱근~num까지도 약수가 없음. 아래 for문을 모두 통과하면 즉, 소수인 것
	{
		if (num % i == 0)
			return false;
	}

	return true;
}

int main() 
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;	// test 개수
	cin >> T;
	int N;
	int numOfGB;	// 골드바흐 파티션 개수
	vector <int> answer(T);
	
	// 먼저 해당 숫자가 소수인지 미리 확인해놓기
	vector <int> isPrimeNum(1000000);
	for (int i = 0; i < isPrimeNum.size(); i++)
	{
		isPrimeNum[i] = checkPrimeNumber(i);
	}


	for (int i = 0; i < T; i++)
	{
		cin >> N;
		numOfGB = 0;
		for (int j = 0; j <= N / 2; j++)
		{

			if ((isPrimeNum[j] == true) && (isPrimeNum[N - j] == true))
				numOfGB += 1;
		}
		answer[i] = numOfGB;
	}

	//for (int i = 0; i < T; i++)
	//{

	//	cin >> N;
	//	numOfGB = 0;
	//	for (int j = 2; j <= N / 2; j++)	// 1은 소수가 아니니까 2부터 체크
	//	{
	//		if ((checkPrimeNumber(j) == true) && (checkPrimeNumber(N - j) == true))
	//			numOfGB += 1;
	//	}
	//	answer[i] = numOfGB;
	//}

	for (int i = 0; i < T; i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}