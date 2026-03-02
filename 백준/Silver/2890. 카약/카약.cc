#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int R, C;
	cin >> R >> C;

	// 현재 경기장 입력받기 ---------------------
	vector <string> line(R);
	for (int i = 0; i < R; i++)
	{
		cin >> line[i];
	}
	
	//cout << "체크1 \n";
	// 결승까지 얼마만큼의 거리가 남았는지 확인하기 ---------------------
	vector <int> checkTeamPos(10);	// 1~9번 팀이 있다고 했으므로.
	
	int num;
	for (int i = 0; i < R; i++)
	{
		for (int j = 1; j < C-1; j++)
		{
			if (line[i][j] != '.')
			{
				num = line[i][j] - '0';	// 몇 번 팀인지 확인

				// 결승선까지 몇 개의 '.'이 남았는지 확인
				checkTeamPos[num] = (C - (j + 3));
				//cout << "체크3 \n";

				//cout << num << "번 팀은 결승까지 " << checkTeamPos[num] << "만큼 남았따~\n";
				break;	// 해당 row는 더이상 볼 필요가 없어짐
			}
		}
	}
	
	// 등수 확인하기 ---------------------
	int countTeamNum = 0;	// 결승선까지 거리가 짧은 팀부터 확인하고, 등수 확인한 팀의 개수를 카운팅하자
	int checkRank = 1;
	bool someoneRank = false;	// 한 팀이라도 순위가 등록되었다면, checkRank를 +1
	vector <int> rank(10);	// 1번부터 9번까지 팀의 등수 저장하기 위한 vector
	int shortestLen = 0;	// 현재 
	while (true)
	{
		if (countTeamNum == 9)	// 모든 9개의 팀이 순위가 배정되었다면 통과하기
		{
			break;
		}
		for (int i = 1; i < checkTeamPos.size(); i++)	// 팀은 1번부터 9번까지 있으므로 i=1부터 시작
		{
			if (checkTeamPos[i] == shortestLen)
			{
				rank[i] = checkRank;
				countTeamNum++;	// 순위를 배정받은 팀의 개수 확인 (모두 등수가 매겨지면, while문을 통과하기 위함)
				someoneRank = true;
			}
		}
		shortestLen++;
		if (someoneRank == true)
		{
			checkRank++;
			someoneRank = false;	// 다음 확인을 위해 초기화
		}
	}

	// 순위 출력하기 -------------------------
	for (int i = 1; i < rank.size(); i++)	// 1번부터 9번팀까지 있으므로 i=1부터 시작
	{
		cout << rank[i] << "\n";
	}
}