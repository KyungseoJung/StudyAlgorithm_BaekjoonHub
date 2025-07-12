#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	stack <int> st;
	int k;
	cin >> k;
	int input;
	while (k--)	// k가 0이 되면 false로 while문 종료됨
	{
		cin >> input;
		if (input != 0)
			st.push(input);
		else if(input == 0)
			st.pop();
	}

	int sum = 0;
	//for (int i = 0; i <= st.size(); i++)	// st 사이즈가 계속 바뀌기 때문에, 이렇게 for문을 설정하는 건 적절하지 않음
	while(!st.empty())
	{
		sum += st.top();
		//cout << i << "번째 수 더하기: " << st.top() << "\n";
		st.pop();
	}

	cout << sum;
	return 0;
}