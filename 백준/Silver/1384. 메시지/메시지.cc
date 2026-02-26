#include <iostream>
#include <vector>

using namespace std;
// 1384번 문제: 메시지
int main()
{
	int N;
	int group = 1;
	vector <string> names;
	vector <vector <char>> papers;
	while (true)
	{
		cin >> N;

		if (N == 0)
		{
			break;
		}
		else
		{
			// 적히는 아이 수에 따라 vector의 크기를 resize
			//resize(N - 1, ' ');	// 크기를 (N-1)로 변경하고, 추가된 공간을 기본값(공백)으로 채운다.
			papers.assign(N, vector<char>(N - 1, ' '));	// 크기를 (N-1)로 변경하고, 모든 요소를 기본값(공백)으로 덮어쓴다.
			names.assign(N, " ");

			for (int i = 0; i < N; i++)
			{
				cin >> names[i];
				for (int j = 0; j < N - 1; j++)
				{
					cin >> papers[i][j];
				}
			}
		}

		// 그룹 n번째 확인 시작
		if (group >= 2)	// 2번째 그룹 부터는 한 줄 더 띄어쓰기
		{
			cout << "\n";
		}
		cout << "Group " << group << "\n";
		bool nobody = true;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N - 1; j++)
			{
				if (papers[i][j] == 'N')
				{
					nobody = false;

					int check = (N - 1) - (j + 1) + 1;
					int badWordPersonEle = i + check;	//나쁜 말 한 사람 찾기
					if (badWordPersonEle >= N)
					{
						badWordPersonEle = badWordPersonEle - N;
					}

					cout << names[badWordPersonEle] << " was nasty about " << names[i] << "\n";
				}
			}
		}

		if (nobody == true)
		{
			cout << "Nobody was nasty\n";
		}

		group++;	
	}

	return 0;
}