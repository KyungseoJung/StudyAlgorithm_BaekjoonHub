#include <string>
#include <vector>

#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer(s.length());
    vector<bool> exist(26, false); // 0~25까지 26개 알파벳이 등장했는지 저장하는 vector (인덱스 번호로 저장. 0번째부터)
    vector<int> pos(26);    // 1~26까지 26개 알파벳이 몇 번째 위치에 있는지 저장하는 vector (인덱스 번호로 저장. 0번째부터)
    
    char alphabet;
    int ele;
    for(int i=0; i<s.length(); i++)
    {
        alphabet = s[i];
        cout << "i : " << i << " / " << s.length() <<  "\n";
        
        // 영어는 모두 소문자이므로 바로 'a'를 빼도 됨
        ele = int(alphabet - 'a');  // int 안붙여도 숫자로 저장되긴 함.

        
        // 일단 앞에 동일한 게 있는지 확인
        if(exist[ele] == true)
        {
            answer[i] = i - pos[ele];
        }
        else
        {
            answer[i] = -1; // 앞에 동일한 알파벳이 없어서 0으로 설정되어 있다면, -1로 설정해주기
        }
        
        
        // 그리고 해당 알파벳에 대해서도 업데이트 해주기
        exist[ele] = true;  // ele문자는 존재한다
        pos[ele] = i;   // ele문자의 위치는 i에 위치한다.  // 이미 존재해도 가장 뒤의 자리로 업데이트되도록
    }
    
    return answer;
}