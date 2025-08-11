#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int N, X;
	cin >> N >> X;
	vector <int> nums(N);
	vector <int> smaller;
	for (int i=0; i<N; i++)
	{
		cin >> nums[i];
		if (nums[i] < X)
		{
			smaller.push_back(nums[i]);
		}
	}

	for (int i = 0; i < smaller.size(); i++)
	{
		cout << smaller[i];

		if( i != smaller.size()-1)	// 마지막 숫자는 뒤에 빈칸 넣지 않기
		{
			cout << " ";
		}
	}

	return 0;
}