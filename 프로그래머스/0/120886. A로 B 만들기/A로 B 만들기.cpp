#include <string>
#include <vector>

#include <iostream>
using namespace std;

int solution(string before, string after) {
    int answer = 0;
    vector <bool> afterCheck(after.size(), false);  // 모두 false으로 해서 시작하기
    // before와 비교하면서, before에서 after의 특정 알파벳을 갖고 있다면 true로 바꾸기
    
    cout << before.size() << "\n";
    cout << before[1] << " \n";
    for(int i=0; i<before.size(); i++)
    {
        for(int j=0; j<after.size(); j++)
        {
            if((before[i] == after[j]) && (afterCheck[j] == false))
            {
                cout << i << " | " << j << " | " << before[i] << "\n";
                afterCheck[j] = true;
                break;  // 더이상 after에서 찾지 않기. 멈추기.                
            }
        }
    }
    
    // afterCheck 벡터에서 확인 - 모두 true이면 before와 fit하게 모든 알파벳 구성 및 개수가 맞았던 것
    answer = 1;
    for(int i=0; i<afterCheck.size(); i++)
    {
        if(afterCheck[i] == false)
        {
            answer = 0;
        }
    }
    
    return answer;
}