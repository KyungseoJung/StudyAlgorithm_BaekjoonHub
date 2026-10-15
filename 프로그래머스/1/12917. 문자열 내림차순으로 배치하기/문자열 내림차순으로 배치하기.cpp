#include <string>
#include <vector>

#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    
    vector <char> v;
    // vector에 저장해서 내림차순 시행한 다음, 다시 넣기
    for(int i=0; i<s.length(); i++)
    {
        v.push_back(s[i]);
    }
    
    // 내림차순 정렬
    sort(v.rbegin(), v.rend()); // ** 내림차순 코드
    
    for(int i=0; i<v.size(); i++)
    {
        answer = answer + v[i];
    }
    return answer;
}