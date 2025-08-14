#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int N;	// 채널의 수 (2이상 100이하)
	cin >> N;
	vector <string> channels(N);
	string firstCH = "KBS1";
	string secondCH = "KBS2";
	for (int i = 0; i < N; i++)
	{
		cin >> channels[i];
	}

	vector <char> pushBtn;
	// 규칙: KBS1이 첫 번째에, KBS2가 두 번째에 있도록
	// 방법1: KBS1을 찾을 때까지 밑으로 쭈욱 내려가면서 서치. 찾으면 맨 위로 보낼 때까지 4번 버튼
	// KBS2을 찾을 때까지 밑으로 쭈욱 내려가면서 서치. 찾으면 2번째로 보낼 때까지 4번 버튼
	int arrowNum = 0;	// 현재 화살표가 위치한 번호
	string temp;
	for (int i = 0; i < N; i++)
	{
		if (channels[i] == firstCH)
		{
			for (int j = i; j >0; j--)
			{
				temp = channels[j-1];
				channels[j - 1] = channels[j];
				channels[j] = temp;

				pushBtn.push_back('4');
			}
			//arrowNum = 0;
			// 여기까지 하면, 화살표는 맨 첫 번째로 설정. KBS1은 맨 첫 번째에 설정된 상태임.
			break;
		}
		pushBtn.push_back('1');
		//arrowNum++;
	}

	for (int i = 0; i < N; i++)
	{
		if (channels[i] == secondCH)
		{
			for (int j = (i-1); j > 0; j--)
			{
				temp = channels[j - 1];
				channels[j - 1] = channels[j];
				channels[j] = temp;

				pushBtn.push_back('4');
			}
			//arrowNum = 0;
			// 여기까지 하면, 화살표는 두 번째로 설정. KBS2는 두 번째에 설정된 상태임.
			break;
		}
		pushBtn.push_back('1');
		//arrowNum++;
	}

	// 정답 출력 -----------
	for (int i = 0; i < pushBtn.size(); i++)
	{
		cout << pushBtn[i];
	}

	return 0;
}