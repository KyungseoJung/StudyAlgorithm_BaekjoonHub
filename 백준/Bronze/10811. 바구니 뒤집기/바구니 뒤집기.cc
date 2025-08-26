#include <iostream>
#include <vector>

using namespace std;

vector <int> basket;	// 헷갈릴 수 있으니까, 1번째 바구니 = basket[1]로 설정

void changeBakset(int start, int end)
{
	// 아래 코드를 이 한 줄로 가능하긴 함.
	//reverse(basket.begin() + start, basket.begin() + end);

	int temp;
	int num = (end - start + 1) / 2;	// 개수 나누기 2의 몫. 
	// 홀수개이면(나머지가 1로 남는다면), 어차피 가운데 바구니는 바꿀 필요가 없기 때문에, 몫만큼만 change하면 됨
	for (int i = 0; i < num; i++)
	{
		temp = basket[start + i];
		basket[start + i] = basket[end - i];
		basket[end - i] = temp;
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	basket.resize(N + 1);
	// 바구니 순서대로 입력하기 (1번째 바구니를 [0]으로 설정하지 않고 [1]부터 설정)-----------
	for (int i = 1; i <= N; i++)
	{
		basket[i] = i;
	}

	// 바구니 역순으로 만들기 -----------
	int i, j;

	for (int k = 0; k < M; k++)	// 2개씩 입력하니까 *2 해줌
	{
		cin >> i >> j;
		changeBakset(i, j);
	}

	// 최종 바구니 출력 ---------
	for (int i = 1; i <= N; i++)	// 처음에 1부터 N까지로 설정했었으니깐
	{
		cout << basket[i];
		if (i != N)
		{
			cout << " ";
		}
	}

	return 0;
}