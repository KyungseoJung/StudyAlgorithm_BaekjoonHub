#include <iostream>

int main()
{
	int x, y, w, h;

	std::cin >> x >> y >> w >> h;

	int min = 9999;

	// x축으로 이동하는 경우 생각
	if ((x - 0) < min)
		min = x;
	if ((w - x) < min)
		min = w - x;
	// y축으로 이동하는 경우 생각
	if ((y - 0) < min)
		min = y;
	if ((h - y) < min)
		min = h - y;

	std::cout << min;
	
	return 0;
}