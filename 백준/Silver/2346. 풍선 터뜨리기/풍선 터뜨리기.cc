#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;
int main()
{
// 아우 2시간은 걸렸다.. 배열로 했다가, stack으로 했다가, deque로 했다가...
    
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	// 1번부터 N번까지 N개의 풍선이 원 모양으로 앉아있는 모습
	// 각 풍선에는 숫자 종이가 들어있음. (-N 이상 N이하)

	// 풍선 터뜨리기 -----------------------
	// 헷갈림: 문제에 나온대로 각 숫자 종이를 빼는 건 가능하겠는데, 그게 몇 번째 풍선의 종이인지 어떻게 알 수 있지? 
	// (한번 뽑은 풍선은 아예 빠지는 그 규칙이 되게 헷갈림) (배열로 풀까도 싶었는데 그게 더 헷갈리는 것 같아서, deque로 시도중)
	// vector의 pair 함수 이용해보기
	
	// 데이터 입력 -----------------------
	int N;	// 풍선 개수
	cin >> N;
	deque <pair<int, int>> balloonDQ(N);	// 첫 번째는 기존 풍선의 순서, 두 번째는 그 풍선 안의 숫자
	vector<int> answer(N);	// 뽑는 풍선 순서 값을 넣을 vector


	for (int i = 0; i < N; i++)
	{
		balloonDQ[i].first = i;	// 맨 처음 풍선을 0번이라고 하자.
		cin >> balloonDQ[i].second;
	}

	int moving;

	// 0번째 값은 미리 먼저 계산해주기
	answer[0] = balloonDQ[0].first;	//1
	moving = balloonDQ[0].second;	//3
	balloonDQ.pop_front();

	for (int i = 1; i < N; i++)
	{
		if (moving > 0)	// 양수라면 앞 숫자가 뒤로 가도록
		{
			for (int j = 0; j < moving-1; j++)	// (moving-1)인 이유: 애초에 맨 처음 balloon이 뽑히면서 자동으로 1칸이 이미 앞으로 당겨짐.
			{
				balloonDQ.push_back(balloonDQ.front());
				balloonDQ.pop_front();
			}

		}
		else // 음수라면 뒤 숫자가 앞으로 오도록
		{
			for (int j = 0; j < -moving; j++)
			{
				balloonDQ.push_front(balloonDQ.back());
				balloonDQ.pop_back();
			}
		}

		// moving이 종료된 후, 맨 앞에 있는 숫자가 뽑을 풍선임.
		moving = balloonDQ[0].second;	// 풍선 안에 적힌 숫자 (움직여야 하는 이동 수)
		answer[i] = balloonDQ[0].first;	// 풍선의 원래 순서 숫자
		balloonDQ.pop_front();
	}

	for (int i = 0; i < N; i++)
	{
		cout << answer[i] + 1 << " ";	
		// 지금까지 맨 첫 풍선을 0번째 풍선이라고 가정하고 코드를 풀었기 때문에, 마지막에 출력할 땐 +1 하고 출력해주기
	}


	return 0;
}