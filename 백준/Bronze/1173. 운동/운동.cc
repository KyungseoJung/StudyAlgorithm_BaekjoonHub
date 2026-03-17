#include <iostream>

using namespace std;
// 1173번 문제: 운동
int main()
{
	int N, m, M, T, R;
	cin >> N >> m >> M >> T >> R;
	
	int X = m;	// 현재 맥박을 저장 및 확인하기 위한 변수
	int time = 0;	// 필요한 시간 계산
	int exerciseTime = 0;	// 운동을 한 시간
	while (true)
	{
		// ** 쉬어야 하는 상태 외에 모두 운동을 하면, m을 굳이 고려하지 않아도 되지 않을까?
		// 아니네... 운동 자체가 불가능한 경우도 고려해야 해서 안됨
		// 예외 경우 고려 (운동 자체가 불가능한 경우)
		if (m + T > M) // 운동 1번조차 불가능한 경우
		{
			cout << - 1;
			return 0;
		}

		if (X + T <= M)	// 맥박을 초과하지 않으면 바로 운동하자
		{
			X += T;
			time++;	// 1분 증가
			exerciseTime++;
		}
		else // 맥박을 초과할 것 같으면 잠깐 쉬자. 그 외에는 무조건 운동
		{
			// 쉬어야 함
			if (X - R < m) // 맥박은 절대로 m보다 낮아지면 안된다. 따라서, X-R이 m보다 작으면 맥박은 m이 된다.
			{
				X = m;
			}
			else
			{
				X -= R;
			}
			time++;
		}

		if (exerciseTime >= N) // 운동 할당량만큼 다 했으면 그만
		{
			break;
		}
	}

	cout << time;
	
	return 0;
}