//#include <stdio.h>
//#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

/* 시간 초과: gpt의 힌트
* 재귀 호출할 때마다 문자열 전체가 복사됩니다.
이 복사 비용이 누적되어 시간 초과가 날 수 있어요.

따라서, 각 함수에서 참조(&)로 받기. 

그냥 & 쓰는 경우 vs. const & 쓰는 경우:
const를 붙이면 “이 함수는 문자열을 절대 건들지 않겠다”는 약속을 문법적으로 강제합니다.
So, 읽기 전용인 string은 const string& s로.
값이 바뀔 수 있는 _checkNum은 int& _checkNum으로 설정.

*/
int recursion(const string& s, int l, int r, int& _checkNum)
{
    _checkNum++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1, _checkNum);

}

int isPalindrome(const string& s, int& _checkNum) {
    _checkNum = 0;
    return recursion(s, 0, s.size() - 1, _checkNum);
}


int main() {

    int T;  // 테스트 개수
    cin >> T;
    int checkIsPalindrom = 0;
    int checkNum = 0;
    vector <string> input(T);
    
    for(int i=0; i<T; i++)
    {

        cin >> input[i];
        checkIsPalindrom = isPalindrome(input[i], checkNum);

        cout << checkIsPalindrom << " " << checkNum << "\n";
    }


    return 0;
}