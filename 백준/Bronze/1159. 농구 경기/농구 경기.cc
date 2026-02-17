#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int n;
	cin >> n;
	string input;
	// 'a'는 숫자로 97임
	vector <int> count(26);	// 0부터 25까지 ('a'부터 'z'까지 등장 횟수 저장)
	while (n--)
	{
		cin >> input;
		count[(int)(input[0]) - 97]++;
	}

	// 5명 이상인 경우를 출력
	bool existAtLeastOne = false;
	for (int i = 0; i < count.size(); i++)
	{
		if (count[i] >= 5)
		{
			existAtLeastOne = true;
			cout << char('a' + i);
		}
	}
	if (existAtLeastOne == false)
	{
		cout << "PREDAJA";
	}

	return 0;
}