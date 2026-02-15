#include <iostream>
#include <string>
using namespace std;
int main()
{
	string num;
	cin >> num;

	int sum;
	int count = 0;
	while (num.length() > 1)
	{
		sum = 0;
		for (int i = 0; i < num.length(); i++)
		{
			sum += (num[i] - '0');	// char 을 int 형태로 바꿔서 sum에 더하기
		}
		
		num = to_string(sum);
		count++;
	}

	int checkNum = stoi(num);
	cout << count << "\n";
	if ((checkNum == 3) || (checkNum == 6) || (checkNum == 9))
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}