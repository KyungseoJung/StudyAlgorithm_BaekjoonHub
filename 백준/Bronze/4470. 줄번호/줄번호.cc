#include <iostream>
#include <vector>
#include <string>


using namespace std;
int main()
{
	int N;
	cin >> N;
	cin.ignore();

	vector <string> sentence(N);
	string input;
	for (int i = 0; i < N; i++)
	{
		getline(cin, input);
		sentence[i] = (input);
	}

	// 출력
	for (int i = 0; i < N; i++)
	{
		cout << i + 1 << ". " << sentence[i] << "\n";
	}
}