#include <iostream>

int main()
{
	std::string name;
	double hakjum;
	std::string score;
	double sum = 0;
	double hakjumSum = 0;

	for (int i = 0; i < 20; i++)
	{
		std::cin >> name >> hakjum >> score;
		if (score != "P")	// 등급이 P이면 계산에 포함 X.
		{
			if (score == "A+")
				sum += 4.5 * hakjum;
			else if (score == "A0")
				sum += 4.0 * hakjum;
			else if (score == "B+")
				sum += 3.5 * hakjum;
			else if (score == "B0")
				sum += 3.0 * hakjum;
			else if (score == "C+")
				sum += 2.5 * hakjum;
			else if (score == "C0")
				sum += 2.0 * hakjum;
			else if (score == "D+")
				sum += 1.5 * hakjum;
			else if (score == "D0")
				sum += 1.0 * hakjum;
			//else if (score == "F")
			//	sum += 0;

			hakjumSum += hakjum;
		}

	}


	std::cout << (sum / hakjumSum);

	return 0;
}