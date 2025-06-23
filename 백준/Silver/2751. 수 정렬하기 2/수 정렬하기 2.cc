#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;
	std:: vector<int> input(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> input[i];
	}

	sort(input.begin(), input.end());

	for (int i = 0; i < N; i++)
	{
		std::cout << input[i] << "\n";
	}

	return 0;
}