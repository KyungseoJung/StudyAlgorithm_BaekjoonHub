#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int s, int e) {
    string answer = "";
    int len = my_string.length();
    for(int i=0; i< s; i++)
    {
        answer = answer + my_string[i];
    }
    
    // 뒤집을 문장 더하기
    for(int i = e; i>=s; i--)
    {
        answer = answer + my_string[i];
    }
    
    for(int i= e+1; i<len; i++)
    {
        answer = answer + my_string[i];
    }
    return answer;
}