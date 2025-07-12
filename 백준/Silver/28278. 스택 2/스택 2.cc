#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;	// 명령의 수
	cin >> N;

	vector <int> stack(N);
	int numOfElement = 0;	// 현재 stack 요소 개수
	int action;
	int element;

	while (N--)
	{
		cin >> action;

		switch (action)
		{
		case 1 :
			numOfElement++;

			cin >> element;
			stack[numOfElement-1] = element;
			break;
		case 2:
			if (numOfElement > 0)
			{
				cout << stack[numOfElement-1] << "\n";
				stack[numOfElement-1] = 0;
				numOfElement--;
			}
			else
				cout << "-1" << "\n";
			break;
		case 3 :
			cout << numOfElement << "\n";
			break;
		case 4:
			if (numOfElement > 0)
				cout << "0" << "\n";
			else if (numOfElement == 0)
				cout << "1" << "\n";
			break;
		case 5:
			if (numOfElement > 0)
				cout << stack[numOfElement-1] << "\n";
			else
				cout << "-1" << "\n";
			break;
		}
	}

	return 0;
}