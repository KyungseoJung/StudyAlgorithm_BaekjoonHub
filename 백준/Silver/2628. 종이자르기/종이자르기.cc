#include <iostream>
#include <vector>
#include <stack>		// stack 사용하기 위함
#include <queue>		// queue 사용하기 위함
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
#include <set> // set 사용하기 위함
using namespace std;
// 2628번 문제: 종이 자르기

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int width, height;	// 종이의 총 가로길이, 세로길이를 입력
	cin >> width >> height;	

	int T;
	cin >> T;
	int isVertical;	// (1이면 세로로 자름. 0이면 가로로 자름) 가로인지 세로인지 확인하기 위한 변수
	int num;
	vector <int> verticalNums;	// 세로로 자른 번호들 저장
	vector <int> horizontalNums;	// 가로로 자른 번호들 저장
	while (T--)
	{
		cin >> isVertical >> num;
		if (isVertical == 0)
		{
			horizontalNums.push_back(num);
		}
		else
		{
			verticalNums.push_back(num);
		}
	}
	// 넘어가기 전에 오름차순 정렬해주기
	sort(horizontalNums.begin(), horizontalNums.end());
	sort(verticalNums.begin(), verticalNums.end());

	// 가장 큰 종이 조각의 넓이 = 가로로 제일 길게 남은 길이와 세로로 제일 길게 남은 길이를 곱한 것
	// 가로로 제일 길게 남은 길이 찾기
	int leftCol = 0;	// 가장 왼쪽에 있는 열 위치 저장 (처음엔 0)
	int maxWidth = -1;
	for (int i = 0; i < verticalNums.size(); i++)
	{
		if (verticalNums[i] - leftCol > maxWidth)
		{
			maxWidth = verticalNums[i] - leftCol;
		}
		leftCol = verticalNums[i];	// 다음 for문 넘어가기 전에 새롭게 업데이트
	}
	// 마지막으로 맨 끝자락과 비교
	if (width - leftCol > maxWidth)
	{
		maxWidth = width - leftCol;
	}
	
	// 세로로 제일 길게 남은 길이 찾기
	int upRow = 0;	// 가장 위쪽에 있는 행 위치 저장 (처음엔 0)
	int maxHeight = -1;
	for (int i = 0; i < horizontalNums.size(); i++)
	{
		if (horizontalNums[i] - upRow > maxHeight)
		{
			maxHeight = horizontalNums[i] - upRow;
		}
		upRow = horizontalNums[i];	// 다음 for문 넘어가기 전에 새롭게 업데이트
	}
	// 마지막으로 맨 끝자락과 비교
	if (height - upRow > maxHeight)
	{
		maxHeight = height - upRow;
	}


	cout << maxWidth * maxHeight;
	return 0;
}