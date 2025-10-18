#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
//#include <cctype>

//#1456번 문제
//** 포인트
/*
1. 에라토스테네스의 체
2. pow대신 일일이 곱해주기
3. 쓰레기값이 나와서 while문 통과하지 못하는 것을 방지하기 위해 if문 추가
*/
using namespace std;
bool checkPrimeNum(int num)
{
	if (num == 1)
	{
		return false;
	}
	else if (num == 2)
	{
		return true;
	}
	else
	{
		for (int i = 2; i <= sqrt(num); i++)
		{
			if (num % i == 0)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	long long int A, B;
	cin >> A >> B;

	// (1) A의 제곱근보다 크고 B의 제곱근보다 작거나 같은 소수들 찾아보기 (B의 제곱근보다 작아야, 그 수를 N제곱 했을 때 B 이하의 숫자일 테니까)
	//*** 아래 코드처럼 소수를 구하면 연산 시간이 오래 걸리므로 <에라토스테네스의 체> 코드를 이용한다!!! ?
	//vector <long long int> primeNumList;
	//for (long long int i = 2; i <= sqrt(B); i++)
	//{
	//	// sqrt(A)부터 하면 안 됨. 그러면 2, 3... 소수들도 잃어버리기 때문. 
	//	// 즉, 가능한 소수의 최댓값은 따로 한정해둘 수 있지만, 확실한 최소값은 알 수 없다는 것. (2부터 고려해야한다는 말)
	//	if (checkPrimeNum(i) == true)
	//	{
	//		primeNumList.push_back(i);
	//	}
	//}
	vector<long long> primeNumList;

	long long maxBase = static_cast<long long>(sqrtl(B)); // √B를 한 번만 계산

	//*** 에라토스테네스의 체
	vector<bool> isPrime(maxBase + 1, true);
	if (maxBase >= 0) isPrime[0] = false;
	if (maxBase >= 1) isPrime[1] = false;

	for (long long i = 2; i * i <= maxBase; ++i) {
		if (!isPrime[i]) continue;
		for (long long j = i * i; j <= maxBase; j += i) {
			isPrime[j] = false;
		}
	}

	// 소수만 리스트에 담기
	for (long long p = 2; p <= maxBase; ++p) {
		if (isPrime[p]) primeNumList.push_back(p);
	}


	// (2) 이제, 해당 소수들의 N제곱 값이 A이상 B이하에 몇 개나 해당되는지 확인하기
	//*** pow로 계산하면 연산 시간이 길어질 수 있으므로 일일이 곱하며 while문 돌기
	long long int count = 0;
	long long int num;
	long long int val;
	for (int i = 0; i < primeNumList.size(); i++)	// 각 소수들에 대하여 N제곱을 해보고, A이상 B에 해당되면 count++
	{
		val = primeNumList[i];
		num = val * val;	// 제곱부터 시작해서 카운팅
		while (num <= B)
		{
			if (num >= A)
			{
				//cout << num << "는 거의 소수 \n";
				count++;
			}

			//*** 오버플로가 발생하면, 쓰레기값(음수가 나올 수도 O)이 나오므로, while문에서 벗어나지 못하거나 개수가 잘못 카운팅 될 수 있음.
			if(num > (B/val))	// if (num * val > B) -> 이렇게 하면 여전히 (num*val)을 계산할 때 쓰레기값이 나올 수도 있으므로
			{
				break;
			}
			num = num * val;
		}
	}

	cout << count;
	return 0;

}
