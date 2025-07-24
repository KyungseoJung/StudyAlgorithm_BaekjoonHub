#include <iostream>

using namespace std;

int main()
{
	// N! (팩토리얼 출력)
	int N;
	cin >> N;
	int answer = 1;
	for (int i = N; i > 0; i--)
	{
		answer = answer * i;
	}

	cout << answer;

	return 0;
}