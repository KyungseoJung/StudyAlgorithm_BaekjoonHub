#include <iostream>

int main()
{
	// 가장 아래 정사각형이 n개일 때, 실선으로 이루어진 도형의 둘레
	// 1개일 때, 1+1+1+1 = 4
	// 2개일 때, 2(윗면) + 옆면(2*2) + 아랫면(2)
	// 3개일 때, 3(윗면) + 옆면(3*2) + 아랫면(3)

	long long int n;	// 가장 아랫부분의 정사각형의 개수 (n의 범위가 크기 때문에, long long 지정)
	std::cin >> n;
	std::cout << 4*n;

	return 0;
}