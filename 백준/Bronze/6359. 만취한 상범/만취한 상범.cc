#include <iostream>
#include <vector>

using namespace std;

vector <int> rooms;
// 각 멤버: 0이면 
int returnOpenNums(int n)
{

	for (int check = 2; check <= n; check++)
	{
		for (int i = check; i <= n; i = i + check)
		{
			if (rooms[i-1] == 1)
			{
				rooms[i - 1] = 0;
			}
			else
			{
				rooms[i - 1] = 1;
			}
		}
	}

	int count = 0;
	for (int i = 0; i < rooms.size(); i++)
	{
		if (rooms[i] == 1)
		{
			count++;
		}
	}

	return count;
}

int main()
{
	int T;
	cin >> T;

	int n;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		//rooms.resize(n);
		rooms.assign(n, 1);	// size를 n으로 설정하고, 모두 오픈(=1)

		cout << returnOpenNums(n) << "\n";
	}
}