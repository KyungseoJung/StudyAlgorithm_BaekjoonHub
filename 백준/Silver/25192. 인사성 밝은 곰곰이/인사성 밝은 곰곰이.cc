#include <iostream>
//#include <deque>
#include <unordered_set>
#include <set>

using namespace std;

// deque나 for문, bool형 변수 등을 사용하지 않고
// 간편하게 unordered_set을 이용하면 편함
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;	// 채팅방의 기록 수
	cin >> N;
	int count=0;

	set<string> seen;


	string name;

	while (N--)
	{
		cin >> name;

		if (name == "ENTER")
		{
			seen.clear();	// alreadyChatName 초기화하기 (새로운 사람이 들어왔으니까)
			// 다음 사람(다음 N)부터 체크 시작하기
		}
		else
		{
			//cout << "seen.count(" << name << ") = " << seen.count(name) << "\n";
			auto pr = seen.insert(name);
			if (pr.second) {   // .second==true 면 "새로 들어간" 상태
				count++;
			}
			// 만약 1개라도 있다면, insert 하지 않고 pass
		}

	}

	cout << count;
	return 0;
}