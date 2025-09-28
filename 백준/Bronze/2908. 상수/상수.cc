#include <iostream>
#include <vector>
// stoi, reverse 함수 사용하기 위함
#include <string>
#include <algorithm>

using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string input1, input2;
	cin >> input1 >> input2;

	reverse(input1.begin(), input1.end());
	reverse(input2.begin(), input2.end());
	//cout << input1 << " " << input2 << "\n";

	int num1 = stoi(input1);
	int num2 = stoi(input2);

	//cout << num1 << " " << num2 << "\n";
	int output = (num1 > num2) ? num1 : num2;
	
	cout << output;
	return 0;

}