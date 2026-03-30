#include <iostream>

using namespace std;
int main()
{
	int N;
	cin >> N;

	string input;
	while (N--)
	{
		cin >> input;
		if ((input.length() >= 6) && (input.length() <= 9))
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";

		}
	}
	return 0;
}