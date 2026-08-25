#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    int len = pat.length();
    // substr 함수 사용하기 // substr(시작 위치, 알파벳 길이)
    for(int i=0; i<=myString.length() - pat.length(); i++)
    {
        if(myString.substr(i, len) == pat)
        {
            answer++;
        }
    }
    return answer;
}