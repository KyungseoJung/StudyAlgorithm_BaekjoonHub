#include <iostream>

int main()
{
	int hour, min, time;	// 시작 시간(시, 분)과 필요한 시간(분) 입력
	std::cin >> hour >> min >> time;
	int hour_c, min_c;

	if (min + time < 60)
	{
		// min + time이 60미만일 때
		hour_c = hour;
		min_c = min + time;
	}

	if (min + time >= 60)	// min + time이 60이상일 때 (60, 120, 180... 이상인 경우 포함)
	{
		// 일단 몫 계산 필요 (min+time)/60 -> 이 몫의 값을 hour에 더해져서 hour_c 값이 도출될 예정.
		int quotient_min = (min + time) / 60;
		if ((hour + quotient_min) < 24)
		{
			hour_c = hour + quotient_min;
			min_c = (min + time) % 60;
		}
		else if ((hour + quotient_min) >= 24)	// 만약 이 hour_c값이 24이상이라면 0, 1, 2... 로 표현
		{
			hour_c = hour + quotient_min - 24;
			min_c = (min + time) % 60;
		}
	}

	std::cout << hour_c << " " << min_c << std::endl;

	return 0;
}