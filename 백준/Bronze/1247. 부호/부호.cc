#include <iostream>

using namespace std;
// 1247번 문제: 부호

/*
long long int와 double 비교:
(long double은 사실상 double과 거의 유사하대)

1. 정확한 정수 값이 중요하다면 무조건 long long을 쓰세요.
2. 소수점이 필요하고 정밀도가 낮아도 되면 float, 높아야 하면 double을 씁니다.
3. 입력하신 19자리 숫자는 double의 정밀도(15자리)를 초과하기 때문에 값이 왜곡됩니다.
S
*/
int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
	int Num = 3;
	
	int N;

	long long int input;
	__int128_t sum;    // 백준 환경에서 제공하는 자료형이래.
	while (Num--)
	{
		sum = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> input;
            // #### 더할 때 형변환 처리
            sum += (__int128_t)input;
			// sum += input;
		}

		if (sum > 0)
		{
			cout << "+\n";
		}
		else if (sum < 0)
		{
			cout << "-\n";
		}
		else
		{
			cout << "0\n";
		}
	}
	return 0;
}