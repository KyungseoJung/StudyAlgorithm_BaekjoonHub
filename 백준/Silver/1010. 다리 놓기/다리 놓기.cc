#include <iostream>
#include <vector>
using namespace std;
// 생각1: M개의 사이트 중 N개를 뽑는데, 순서대로(숫자가 낮은 것부터 높은 것 순) 뽑는 경우의 수
// 생각2: N개의 사이트를 M개의 사이트에 연결하는 경우의 수 - 다리가 겹치는 경우의 수
// 생각3: M개의 사이트 중 N개를 뽑는 경우의 수! 와 같음. (왜?: 일단 M개 중 N개를 뽑는 것 까진 확실. 그 뽑은 N개를 순서대로 나열할 필요 없이, 그냥 뽑으면 자연스레 순서는 정해지게 되어 있음. )
// 순열, 조합 - 수학적 식으로 생각하는 게 정답인 듯.

long double returnFactorial(int num)
{
	long double answer = 1;
	for (int i = 1; i <= num; i++)
	{
		answer = answer * i;
		//cout << i << "번째 곱: " << answer << "\n";
	}

	return answer;
}

long long returnCombination(int n, int r)
{
	// combination(n_C_r) 계산 방법. 
	// (n!) / [(n-r)! (r!)] = [(n)*(n-1)* ... *(n-r+1) / (r!)]

	r = (r > n - r) ? n - r : r;	// (n-r)과 r 중에 더 작은 수로 r을 설정
	long long  answer = 1;
	for (int i = 1; i <= r; i++)
	{
		//answer = answer * (( n - i + 1) / i);
		answer = answer * (n - i + 1) * 1/i;	// 위 처럼 계산하면 가장 안쪽 (괄호)에 있는 값이 분수로 계산되는 게 아니라, 정수로 먼저 계산이 되어버림.
		// 예: 나는 5/2 형태로 계산하고 싶은데, 5/2 = 2로 먼저 계산되어서 곱해짐

	}

	//cout << n << "_C_" << r << ": " << answer << "\n";
	return answer;
}

int main()
{
	// 서쪽에는 N개의 사이트, 동쪽에는 M개의 사이트
	// 다리끼리는 서로 겹쳐질 수 없음. (서쪽의 1번 사이트가 동쪽의 m사이트에 연결되었다면, 
	// 서쪽의 2번 이상 사이트는 동쪽의 m+1 사이트에 연결되어야 함.

	int T;	// 테스트의 개수
	int N, M;	// 서쪽과 동쪽에 있는 사이트의 개수 (N, M은 0초과 30 미만)
	cin >> T;

	vector <long long > output(T);
	for(int i=0; i<T; i++)
	{
		cin >> N >> M;
		// M_C_N = (M!) / [(M-N)!N!]
		//output[i] = returnFactorial(M) / (returnFactorial(M - N) * returnFactorial(N));
		// ** 팩토리얼을 전부 구했다가 나누는 방식은 long double 정밀도 문제로 미세한 오차가 생길 수 있대 **

		output[i] = returnCombination(M, N);
	}

	for (int i = 0; i < T; i++)
	{
		cout << output[i]<<"\n";
	}

	return 0;

}