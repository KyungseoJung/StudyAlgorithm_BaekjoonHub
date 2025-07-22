#include <iostream>
#include <deque>

using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	//deque가 2개 있는 것. (1개는 pop_front하고, 나머지 1개는 push_front)
	deque <int> line1;	// 처음에 기다리고 있는 줄
	deque <int> line2;	// 추가로 줄 설 수 있는 공간

	// 각 번호표 입력
	int inputNum;
	for (int i = 0; i < N; i++)
	{
		cin >> inputNum;
		line1.push_back(inputNum);
	}

	bool checkEachTime = false;
	bool nice = true;
	int findNumber = 1;	 // 간식을 받을 수 있는 번호표
	// 간식을 1,2,3,4,5,6, .. 순서대로 받을 수 있으면 Nice. 아니라면 Sad 출력.
	while (!line1.empty() || !line2.empty())	// 둘 중에 하나라도 empty가 아니라면 실행 (둘다 empty면 종료)
	{
		checkEachTime = false;	// 각 숫자를 찾았는지 확인하기 위함. 특정 숫자 1개를 아래 3개 if, else문이 지나도 못 찾는다면 그건 실패한 line임.
		//cout << "\n체크: " << findNumber << " | ";
		if ((!line1.empty()) && (line1.front() == findNumber))
		{
			//cout << "찾았다1!: " << findNumber << " | ";
			checkEachTime = true;
			line1.pop_front();
			findNumber++;
		}
		else if((!line2.empty()) && (line2.front() == findNumber))
		{
			//cout << "찾았다2!: " << findNumber << " | ";
			checkEachTime = true;
			line2.pop_front();
			findNumber++;
		}
		else // 2개 줄에 모두 원하는 번호표가 없다면, line1에 나올 때까지 pop_front
		{
			while (line1.empty() == false)	// line1이 비어있지 않을 때까지만 실행
			{
				if (line1.front() == findNumber)
				{
					//cout << "찾았다3!: " << findNumber << " | ";
					checkEachTime = true;
					line1.pop_front();
					findNumber++;
					break;
				}

				//cout << "line2로 " << line1.front() << "값을 넣기 | ";
				line2.push_front(line1.front()); //  line1에 맨 앞에 있던 사람을 line2에 맨 앞으로 보내기
				line1.pop_front();

			}
		}
		
		if (checkEachTime == false)
		{
			cout << "Sad";
			
			return 0;
		}

	}

	if (findNumber - 1 == N)
	{
		cout << "Nice";
	}
	else
	{
		cout << "Sad";
	}
	


	return 0;
}