#include <iostream>
#include <vector>

using namespace std;

int check(int input)
{
	if (input == 1)    // 1은 소수가 아니고, 아래 for문에 해당되지 않으므로 따로 처리
		return 0;

	for (int i = 2; i < input; i++)	// 1과 자기 자신을 제외한 수들로 모두 나눠보기
	{
		if (input % i == 0)
		{
			return 0;
		}
	}
	// 만약 위 for문을 거치면서 한번도 나눠지는 수가 없었다면
	return 1;
}
int main()
{
	// 속도 빠르게 해주는 코드
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;	// 주어진 N개의 수
	cin >> N;

	//vector <int> numbers(N);

	//소수: 약수가 1과 자기 자신 뿐인 수
	int count = 0;
	int input;

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		//numbers[i] = input;
		count += check(input);
	}

	std::cout << count;

}