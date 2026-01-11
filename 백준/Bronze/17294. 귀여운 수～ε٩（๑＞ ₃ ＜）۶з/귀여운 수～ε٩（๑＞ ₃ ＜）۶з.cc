#include <iostream>
#include <vector>
#include <stack>		// stack 사용하기 위함
#include <queue>		// queue 사용하기 위함
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
#include <set> // set 사용하기 위함
using namespace std;
// 17294 문제: 귀여운 수

int main()
{
    // 코드 속도 빠르게 하기 위한 설정
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string input;
    cin >> input;

    int diff;
    if (input.length() < 3)
    {
        cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
        return 0;
    }
    else
    {
        // char을 int로 전환하는 코드
        diff = (input[1] - '0') - (input[0] - '0');

        for (int i = 2; i < input.length(); i++)
        {
            if (input[i] - input[i - 1] != diff)
            {
                cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
                return 0;
            }
        }
        // 위 for문을 모두 통과했다는 건, 모두 등차수열이라는 뜻임
    }
    
    cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
    return 0;
}