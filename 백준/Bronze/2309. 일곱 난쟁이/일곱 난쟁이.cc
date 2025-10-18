#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
// 2309번 문제.

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n = 9;
	vector <int> height(n);

	int input;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		height[i] = input;
		sum += height[i];
	}
	// 일단 오름차순으로 정렬
	sort(height.begin(), height.end());

	// 빼려고 하는 두 명의 키의 합이 (sum-100)이어야 함
	// 그래야 그 두명의 키의 합을 빼야 100이 됨
	int diff = sum - 100;

	for (int i = 0; i < n; i++)
	{
		for (int j = (i + 1); j < n; j++)
		{
			if (height[i] + height[j] == diff)
			{
				//cout << "지우기: " << height[i] << " " << height[j] << "\n";
				// j 먼저 지워야 함. j가 더 큰 숫자이니까. 
				// 그래야 height[j]를 지워도 height[i]가 i번째에 위치하게 됨
				height.erase(height.begin() + j);

				height.erase(height.begin() + i);

				// 바로 정답 출력하고 끝내기
				// 출력
				for (int i = 0; i < height.size(); i++)
				{
					cout << height[i] << "\n";
				}

				return 0;
			}
		}
	}


}