#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>	// to_string

using namespace std;
// 2577번 문제.

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	long long int multiple;
	multiple = A * B * C;

	vector <int> count(10,0);	// 0부터 9까지 - 일단 내부 element를 모두 0으로 설정
	string st = to_string (multiple);

	//cout << st.length() << "\n";
	int ele;
	for (int i = 0; i < st.length(); i++)
	{
		//cout << "st[" << i << "]: " << st[i] << "\n";
		ele = st[i] - '0';
		//cout << "count[" << ele << "]: ";
		//cout << count[ele] << "\n";
		count[ele]++;
	}

	for (int i = 0; i < count.size(); i++)
	{
		cout << count[i] << "\n";
	}

	return 0;
}