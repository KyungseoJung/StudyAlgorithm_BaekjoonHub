#include <iostream>
#include <vector>

using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;	// 학생들의 수
	cin >> n;
	
	vector <int> lineUp;
	int pickNum;
	for (int i = 0; i < n; i++)
	{
		cin >> pickNum;	// 학생들이 뽑은 번호 숫자
		//cout << "사이즈: " << lineUp.size() << "pickNum: " << pickNum << "\n";
		lineUp.insert(lineUp.begin() + (lineUp.size() - pickNum), i+1);	// v.insert(v.begin() + n, i) : n번째 자리에 i라는 값을 insert한다
	}

	for (int i = 0; i <lineUp.size(); i++)
	{
		cout << lineUp[i];
		if (i != lineUp.size() - 1)
		{
			cout << " ";
		}
	}

	return 0;

}