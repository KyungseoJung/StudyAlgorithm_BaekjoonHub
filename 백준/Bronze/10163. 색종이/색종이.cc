#include <iostream>
#include <vector>
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
#include <set> // set 사용하기 위함
using namespace std;
// 10163번 문제: 색종이
// 좌표를 일일이 계산하는 건 오히려 더 어려움.
// 그냥 무식하게, 1번 숫자가 적힌 스티커를 너비만큼 (너비)개 붙인다고 생각하자

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	//vector <vector <int>> data(N, vector <int> (4));	// leftX, leftY, width, height을 각각 넣기
	int leftX, leftY, width, height;	// N행 4열
	
	//int arr[1001][1001] = { 0 };
	vector <vector<int>> arr(1002, vector <int>(1002));
	vector <int> visible(N+1);	// 차례대로 각 색종이가 얼마나 보이나 저장
	
	// 색종이입력
	for (int i = 1; i <= N; i++)
	{
		cin >> leftX >> leftY >> width >> height;
		
		for (int row = leftX; row < (leftX + width); row++)
		{
			for (int col = leftY; col < (leftY + height); col++)
			{
				visible[i] = width * height;

				if (arr[row][col] != 0)
				{
					// 새로운 색종이가 기존 색종이를 가리는만큼, 기존 색종이의 보이는 부분의 크기를 1씩 줄여주기
					visible[arr[row][col]] -= 1;
				}
				arr[row][col] = i;	// 평면에 새로운 숫자로 업데이트해주기
			}
		}
	}

	// 각 색종이가 얼마만큼 차지하는지 출력
	for (int i = 1; i <= N; i++)
	{
		cout << visible[i] << "\n";
	}


}