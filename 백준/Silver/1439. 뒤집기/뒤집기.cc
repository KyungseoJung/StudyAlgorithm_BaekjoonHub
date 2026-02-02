#include <iostream>
using namespace std;
// 1439 문제: 뒤집기
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string S;
	cin >> S;

	// 0이 연속되어 나타난 횟수랑, 1이 연속되어 나타난 횟수를 비교해서
	// ┗더 적게 나온 횟수가 뒤집어야 하는 최소 횟수임
	char current = '99';	// '-1'이랑 '1'이 같다고 인식하네. '-1'로 설정하면 안됨!!!
	int count0 = 0;
	int count1 = 0;
	for (int i = 0; i < S.length(); i++)
	{
		//cout << i << "번째 문자 " << S[i] << "확인\n";
		if (current != S[i])
		{
			//cout << i << "번째 문자 " << S[i] << "새로 등장\n";
			switch (S[i])
			{
			case '0':
				count0++;
				current = '0';
				break;
			case '1':
				count1++;
				current = '1';
				break;
			}
		}
	}
	int output = (count0 > count1) ? count1 : count0;
	cout << output;
	return 0;
}