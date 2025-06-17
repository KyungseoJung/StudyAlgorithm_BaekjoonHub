#include <iostream>

int main()
{
	// 직사각형 특징: 동일한 x좌표가 2개씩 2세트, 동일한 y좌표가 2개씩 2세트 있어야 함
	
	int x[4];
	int y[4];

	for (int i = 0; i < 3; i++)	// 3개 점 좌표 넣기
	{
		std::cin >> x[i];
		std::cin >> y[i];
	}

	if (x[0] == x[1])
		x[3] = x[2];
	if (x[0] == x[2])
		x[3] = x[1];
	if (x[1] == x[2])
		x[3] = x[0];

	if (y[0] == y[1])
		y[3] = y[2];
	if (y[0] == y[2])
		y[3] = y[1];
	if (y[1] == y[2])
		y[3] = y[0];

	std::cout << x[3] << " " << y[3];
    
    return 0;
}