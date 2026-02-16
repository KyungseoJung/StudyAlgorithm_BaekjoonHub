#include <iostream>
using namespace std;
int main()
{
	int X;
	cin >> X;

	int len = 64;
	int min = len;	// 일단 처음에는 64cm 막대 하나만 갖고 있으므로
	int count = 1;	// 막대의 개수
	int checkLen;
	while (true)
	{
		if (X == 64)
		{
			cout << 1;
			break;
		}
		// ===========(가장 짧은 길이의 막대를 반 자르고, 그 중 하나를 버린 길이를 비교하기!!) =======================
		checkLen = (len - min) + (min / 2);
		if (checkLen > X)
		{
			len = len - min / 2;	// 가장 짧은 길이의 막대를 반 잘라서 그 중 하나 버림
			min = min / 2;
			// count는 변함 없음	(반 잘라서 개수가 하나 +1 됐다가, 하나 버렸기 때문에 -1)
		}
		else if (checkLen == X)
		{
			// 드디어 원하던 막대의 길이가 구해진 것임!!
			// count는 변함 없음
			cout << count;
			break;	// while문 통과

		}
		else
		{
			// 전체 막대의 길이(len)은 변동 없음
			count++;
			min = min / 2;
		}
	}

	return 0;
}