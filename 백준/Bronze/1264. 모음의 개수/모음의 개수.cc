#include <iostream>
#include <vector>
#include <string>

using namespace std;
// 1264번 문제: 모음의 개수
int main()
{
	vector <char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	
	string input;
	int count;

	while (true)
	{
		getline(cin, input);
		if (input == "#")
		{
			break;
		}
		count = 0;
		for (int i = 0; i < input.length(); i++)
		{
			for (int j = 0; j < vowels.size(); j++)
			{
				if (input[i] == vowels[j])
				{
					count++;
				}
			}
		}

		cout << count << "\n";
	}

	return 0;
}