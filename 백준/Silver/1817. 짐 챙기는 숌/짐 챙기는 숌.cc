#include <iostream>
#include <vector>

using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	// 데이터들 입력하기
	int N, M;
	cin >> N >> M;

	vector <int> boxesWeights(N);

	for (int i = 0; i < N; i++)
	{
		cin >> boxesWeights[i];
	}

	// 몇 개의 박스가 필요한지 계산하기
	if (N == 0)
	{
		cout << 0;
		return 0;
	}

	int countBoxNum = 1;
	int sum = 0;	// 박스에 들어간 책의 무게의 합
	for (int i = 0; i < N; i++)
	{
		//cout << i << "번째 박스 \n";
		if (sum + boxesWeights[i] > M)
		{
			//cout << "무게초과! 박스 하나 추가해서 책 넣기 \n";
			sum = boxesWeights[i];	// 박스에 들어간 책의 무게의 합을 현재 넣은 책으로 초기화하기
			countBoxNum++;
		}
		else
		{
			//cout << "무게미달! 이전 박스에 책 하나 더 넣기\n";
			sum += boxesWeights[i];
		}
	}

	cout << countBoxNum;
	return 0;
}
