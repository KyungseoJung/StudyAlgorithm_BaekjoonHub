#include <string>
#include <vector>
#include <algorithm>    // sort 함수
using namespace std;

string solution(string my_string) {
    string answer = "";
    
    // 모두 소문자로 바꾸기
    for(int i=0; i<my_string.length(); i++) 
    {
        if(isupper(my_string[i]))
        {
            my_string[i] = tolower(my_string[i]);
        }
    }
    
    // 정렬하기
    sort(my_string.begin(), my_string.end());
    
    // answer에 넣기
    for(int i=0; i<my_string.length(); i++)
    {
        answer += my_string[i];
    }
    
    return answer;
}