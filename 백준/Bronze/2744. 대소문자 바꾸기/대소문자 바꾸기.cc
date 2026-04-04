#include <iostream>

using namespace std;
int main()
{
	string input;
	cin >> input;
	for (int i = 0; i < input.length(); i++)
	{
		if (isupper(input[i]) != 0)
		{
			cout << (char)tolower(input[i]);
		}
		else
		{
			cout << (char)toupper(input[i]);
		}
	}

	return 0;
}