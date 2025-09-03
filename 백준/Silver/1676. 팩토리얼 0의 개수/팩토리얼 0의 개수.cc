#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// 1676번. 팩토리얼 0의 개수.

/* 생각
* 특정 숫자를 곱했을 때 x0과 같은 수가 나오는 겨우
1) 5와 짝수를 곱했을 때
2) 10의 배수를 곱했을 때

-> 팩토리얼로 곱해지는 숫자들 중, 5와 짝수(10의 배수가 아닌)의 짝궁 개수, 10의 배수의 개수. 100의 배수의 개수
-->> 이렇게 생각하는 거 아님. 5의 배수만 세면 됨. 짝수는 어차피 5에 비하면 아주아주 흔하고 많기 때문에.
	 그리고, 10의 배수, 100의 배수가 아니라 5의 개수임. 10은 5가 1개인 수(5*2), 100은 5가 2개인 수.(5^2 * 2)
*/
using namespace std;
int main()
{
	int N;
	cin >> N;

	int count = 0;
	
	//int countFive = 0;
	//int countTwo = 0;
	//for (int i = 1; i <= N; i++)	// 팩토리얼 곱셈에 사용되는 숫자들을 확인하기
	//{
	//	if (i % 100 == 0)
	//	{
	//		count+=2;
	//	}
	//	else if (i % 10 == 0)
	//	{
	//		//cout << "10의 배수 개수 count \n";
	//		count++;
	//	}
	//	else if (i % 5 == 0)	// 5의 배수이면서 2의 배수인 건 위에서 이미 필터링 됨
	//	{
	//		//cout << "5의 배수 개수 count \n";
	//		countFive++;
	//	}
	//	else if (i % 2 == 0)
	//	{
	//		//cout << "2의 배수 개수 count \n";
	//		countTwo++;
	//	}
	//}
	//// 다 끝나면, 5와 짝수의 짝궁 수를 확인하기 -> 생각한 방법: 5의 배수와 2의 배수의 개수를 각각 세고, 둘 중 더 작은 수가 짝꿍 수임
	//int min = countFive > countTwo ? countTwo : countFive;
	//count += min;

	// 짝수의 개수는 5의 배수에 비해 매우 많으므로, 5의 배수의 개수만 생각하면 됨.
	// *** 유의: 5의 2제곱, 3제곱, 4제곱을 품고 있는 수들에 대해서는 각각 counting을 2개, 3개, 4개 해줘야 함
	//			그 숫자들이 짝수들과 만나면 각각 10^2, 10^3, 10^4의 배수의 모양을 이루기 때문.
	// 예: 25 * 2 * 6 = 25 * 2 * 2 * 3= 300

	// 5^2 = 25, 5^3 = 125, 5^4 = 625 =>> 5^2, 5^3의 배수가 몇개인지만 따로 확인해주면 될 듯
	for (int i = 1; i <= N; i++)
	{
		if (i % 125 == 0)	// 5가 3번 곱해진 수들
		{
			count += 3;
		}
		else if (i % 25 == 0)	// 5가 2번 곱해진 수들
		{
			count += 2;
		}
		else if (i % 5 == 0)	// 5^2, 5^3에 해당하지 않는 5의 배수면 
		{
			count++;
		}
	}

	cout << count;
	return 0;
}
/* 단순한 방법: 
팩토리얼 다 계산하고나서, 10, 100, 1000, ...으로 나누었을 때 몫이 존재하고 나머지가 0인지
using namespace std;

long long int returnFact(int num)
{
	long long int returnNum = 1;
	for (int i = 1; i <= num; i++)
	{
		returnNum = returnNum * i;
	}

	return returnNum;
}

int main()
{
	int N;
	cin >> N;

	long long int fact = returnFact(N);	// 1이상의 어떤 수
	long long int divisor;

	for (int i = 1; i < 9999; i++)
	{
		divisor = pow(10, i);
		if ((fact / divisor > 0) && (fact % divisor != 0))
		{
			// 몫이 0보다 더 큰데, 나머지가 0이 아님 = pow(10, i) 이상인데, 뒷자리가 0이 아니다.
			// = 뒷자리가 0이 아닌 숫자가 나왔다는 것
			cout << i - 1;
			return 0;

		}
		else if ((fact / divisor) == 0)	// fact값이 10보다도 작을 때,
		{
			cout << i-1;
			return 0;
		}
	}

	return 0;
}
*/
