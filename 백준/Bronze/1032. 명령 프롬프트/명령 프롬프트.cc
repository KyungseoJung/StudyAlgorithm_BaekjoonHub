#include <iostream>
#include <vector>

using namespace std;
// 1032번 문제: 명령 프롬프트
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	// 일단 입력하는 N개의 파일 이름은 모두 길이가 동일할 것임
	// 만약 N=1이라면, 그냥 그것만 출력해도 됨 (?가 최소한으로 있게 하는 게 목표니까)

	/*
	aaaaa
	aabaa
	bbabb
	*/
	// 1번째와 2번째의 차이점은 1개, 1번째와 3번째의 차이점은 4개이지만
	// 2번째와 3번째의 차이점은 5개임.
	// 즉, 어느 하나만 기준으로 두고 차이점을 계산하면, 카운팅이 모자랄 수 있음.
	// So, N개 파일 이름이 있으면, 각 파일들을 N_C_2만큼 조합해서 비교해봐야 함.

	int N;
	cin >> N;
	vector <string> fileNames(N);
	// 파일 이름 작성
	for(int i=0; i<N; i++)
	{
		cin >> fileNames[i];
	}

	// 파일 이름 서로 비교하기

	// ?(물음표)로 적을 위치 저장하기
	int len = fileNames[0].length();
	vector <int> ele(len, 0);	// 0이면 모든 파일들이 같은 문자를 가진 것. 1이면 하나라도 같은 문자가 아닌 것.
	for (int i = 0; i < N; i++)
	{
		for (int j = (i + 1); j < N; j++)
		{
			// 2개의 파일 이름을 비교하기 (다른 문자가 있다면 ele에 저장하기)
			for (int k = 0; k < len; k++)
			{
				if (fileNames[i][k] != fileNames[j][k])
				{
					if (ele[k] == 0)
					{
						ele[k] = 1;
					}
				}
			}
		}
	}

	// 패턴 출력하기 - 이건 0번째 파일 이름만 기준으로 보고 해도 됨.
	// 정상적이라면, 패턴은 모든 파일 이름에 동일하게 적용되어야 하니까
	for (int i = 0; i < len; i++)
	{
		if (ele[i] == 0)
		{
			cout << fileNames[0][i];
		}
		else
		{
			cout << '?';
		}
	}

	return 0;

}