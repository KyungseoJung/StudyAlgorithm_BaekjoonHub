#include <iostream>

int main()
{
	int p, k;

	std::cin >> p >> k;

	int arr[10000];
	int num=0;

	for (int i = 1; i < 10000; i++)
	{
		if (p % i == 0)
		{
			arr[num] = i;
			num++;
		}
	}

	if (k > num)
		std::cout << 0;
	else
		std::cout << arr[k - 1];

    return 0;
}