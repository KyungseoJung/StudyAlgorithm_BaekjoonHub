#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int N;
	cin >> N;

	// 염기서열 vector
	vector <vector <char>> DNAVector(4, vector <char>(4));
	DNAVector[0] = { 'A', 'C', 'A', 'G' };
	DNAVector[1] = { 'C', 'G', 'T', 'A'};
	DNAVector[2] = { 'A', 'T', 'C', 'G' };
	DNAVector[3] = { 'G', 'A', 'G', 'T' };


	string inputString;
	cin >> inputString;

	int row, col;
	while (true)
	{
		if (N == 1)	// 문장이 1글자로 줄어들면
		{
			cout << inputString;
			break;
		}
		// n번째 요소 = N-1번째 요소
		// n-1번째 요소 = N-2번째 요소
		switch (inputString[N - 1]) // n번째 요소 검사
		{
		case 'A':
			col = 0;
			break;
		case 'G':
			col = 1;
			break;
		case 'C':
			col = 2;
			break;
		case 'T':
			col = 3;
			break;
		}

		switch (inputString[N - 2]) // n-1번째 요소 검사
		{
		case 'A':
			row = 0;
			break;
		case 'G':
			row = 1;
			break;
		case 'C':
			row = 2;
			break;
		case 'T':
			row = 3;
			break;
		}

		inputString.erase(N - 1, 1);	// N-1번째 문자부터 1개의 문자 삭제하기
		inputString[N - 2] = DNAVector[row][col];

		N--;
	}

	return 0;
}