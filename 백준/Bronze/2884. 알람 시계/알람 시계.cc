#include <iostream>

int main()
{
	int hour, min;
	std::cin >> hour >> min;
	int hour_c, min_c;

	// 일반적인 경우 (min이 45분 이후라면)
	if (min >= 45)
	{
		hour_c = hour;
		min_c = min - 45;
	}
	else if (min < 45)
	{
		if (hour >= 1)
		{
			// min이 45분 전이라면 - 1 (hour이 1 이상이라면)
			hour_c = hour - 1;
			min_c = min + 60 - 45;
		}
		if (hour == 0)
		{
			// min이 45분 전이라면 - 2 (hour이 0이라면)
			hour_c = hour + 24 - 1;
			min_c = min + 60 - 45;
		}
	}
	
	std::cout << hour_c << " " << min_c;

	return 0;
}