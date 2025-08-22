#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int H, W, N, M;

	cin >> H >> W >> N >> M;

	int num1, num2;
	num1 = (H % (N+1) == 0) ? (H / (N+1)) : (H / (N + 1)) + 1;
	num2 = (W % (M+1) == 0) ? (W / (M+1)) : (W / (M + 1)) + 1;
	// N칸씩 띄워 앉아야 한다 = (N+1) 칸에 1명만 배치할 수 있다.
	// 만약 나누었을 때 나머지가 있다면, 한 사람 정도는 더 앉을 자리가 있다는 것

	cout << num1 * num2;
	return 0;
}