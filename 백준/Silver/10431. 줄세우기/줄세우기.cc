#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>	// std::find 기능 사용하기 위함
using namespace std;

#define PEOPLE_NUM 20
deque<int> lineUp;

bool checkMovingFront(int _inputHeight)
{
	for (int i = 0; i < lineUp.size(); i++)
	{
		if (lineUp[i] > _inputHeight)
		{
			return true;
		}
	}
	// 위 if문에서 한 번도 [return true]를 하지 않았다면
	return false;
}

int returnFirstNum(int _inputHeight)
{
	// 입력한 키를 기준으로, 앞에 자기보다 큰 학생이 있다면, 
	// 그 키가 큰 학생들 중 가장 앞에 있는 학생의 번호를 가져오기. (맨 앞을 0번째라고 했을 때)
	for (int i = 0; i < lineUp.size(); i++)
	{
		if (lineUp[i] > _inputHeight)
		{
			return i;
		}
	}
}

int main()
{
	int P;	// 테스트 케이스의 수 P (1이상 1000이하)
	cin >> P;
	//lineUp.resize(PEOPLE_NUM);	// 이렇게 미리 설정해놓으면, size가 20으로 제한되어 있고 0부터 19까지 0으로 채워져 있는 것. 

	vector <int> count(P);	// 각 케이스 별로, 뒤로 물러나는 수 카운팅

	int ele;
	int height;
	int movingCount;
	for (int i = 0; i < P; i++)
	{
		movingCount = 0;
		lineUp.clear();
		cin >> ele;

		//cout << "for문 시작\n";

		for (int i = 0; i < PEOPLE_NUM; i++)
		{
			//cout << "for문: " << i << "---\n";
			cin >> height;
			//cout << "데이터 잘 인식함: " << height << "\n";

			if (i == 0)
			{
				lineUp.push_back(height);
			}
			else
			{
				if (checkMovingFront(height) == true)
				{
					auto it = lineUp.begin() + returnFirstNum(height);
					movingCount += (i-returnFirstNum(height));	// 이전까지 있었던 학생들(i)이 한 걸음씩 뒤로 물러나도록
					//lineUp.push_front(height);	// 방금 들어온 아이가 앞으로 가야 함
					lineUp.insert(it, height);
				}
				else
				{
					lineUp.push_back(height);	// 방금 들어온 아이가 그대로 뒤에 서있도록 하기
				}
			}
		}
		count[ele-1] = movingCount;
	}

	//cout << "여기까지 완료----\n";
	for (int i = 0; i < P; i++)
	{
		cout << i+1 << " " << count[i];
		if (i < P - 1)
		{
			cout << "\n";
		}
	}

	return 0;
}