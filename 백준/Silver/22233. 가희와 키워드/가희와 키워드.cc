#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
#include <cctype>	// isdigit 함수/ isupper, islower 함수 (소문자인지, 대문자인지 확인)
#include <unordered_set>	// unordered_set 함수 사용 목적
//#22233번 문제

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	// 메모장에 써놓은 단어들 입력 받기 ==================
	//vector<string> memo(N);
	unordered_set <string> memo(N);
	string inputMemo;
	for (int i = 0; i < N; i++)
	{
		cin >> inputMemo;
		memo.insert(inputMemo);
	}
	
	// 메인 코드 ==================
	vector <string> blog;
	string input;
	string token;
	cin.ignore();	// 앞에서의 엔터 무시
	int count = 0;	// 겹치는 단어 수
	for (int i = 0; i < M; i++)
	{
		//cin.ignore();	// 여기서 사용하면 안 됨. 
		// 1번째 루프는 올바르게 엔터를 무시하지만, 
		// 2번째 루프부터는 엔터를 엔터로 인식하지 않고 알아서 무시하는 것 같음.

		getline(cin, input);
		stringstream ss(input);
		blog.clear();

		while (getline(ss, token, ','))
		{
			// 블로그에 쓴 키워드 입력 받기 ==================
			blog.push_back(token);
		}

		for (int j = 0; j < blog.size(); j++)
		{
			// 아래 코드: 둘이 만약에 같게 된다 = token을 찾으려다가 끝까지 갔다는 것 = token이 memo에 없다는 의미
			if (memo.find(blog[j]) != memo.end())
			{
				memo.erase(blog[j]);	// memo에서 해당 키워드 제거. 처리 시간 O(1)
			}
// 아래 코드처럼 하면, 처리 시간이 너무 오래 걸림 ========================
// -> vector 대신 unordered_set 사용하자! 그게 바로 위의 코드 ========================
/*
			for (int k = 0; k < memo.size(); k++)
			{
				if (blog[j] == memo[k])
				{
					//memo.erase(memo.begin() + k);	// 한번 중복된 단어는 메모장에서 바로 지우기
					// erase 함수는 중간의 요소를 제거하고, 뒤의 요소들을 한칸씩 앞으로 당겨와야 함. O(N)의 시간이 듦
					count++;
				}
			}
*/
		}

		cout << memo.size() << "\n";	// 메모장에 남은 키워드 수 출력
	}
	 
	return 0;

}
