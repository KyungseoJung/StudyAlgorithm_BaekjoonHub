#include <iostream>
#include <vector>
using namespace std;

int returnBiggest(vector<int> vec)
{
	int size = vec.size();
	int max = -999;
	for(int i=0; i<size; i++)
	{
		if (vec[i] > max)
			max = vec[i];
	}

	//cout << "max: " << max << "\n";
	return max;
}

int returnSmallest(vector<int> vec)
{
	int size = vec.size();
	int min = 1000000;
	for (int i = 0; i < size; i++)
	{
		//cout << "vec[" << i << "]: " << vec[i] << "\n";
		if (vec[i] < min)
			min = vec[i];
	}
	//cout << "min: " << min << "\n";

	return min;
}

int main()
{
	// 코드 속도 향상
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;		// 구하고자 하는 수 N
	int num;	// N의 약수의 개수
	cin >> num;
	vector <int> divisor(num);
	
	for (int i = 0; i < num; i++)
	{
		cin >> divisor[i];
	}

	// N: 가장 큰 수와 가장 작은 수의 곱
	N = returnBiggest(divisor) * returnSmallest(divisor);

	cout << N;
	return 0;
}