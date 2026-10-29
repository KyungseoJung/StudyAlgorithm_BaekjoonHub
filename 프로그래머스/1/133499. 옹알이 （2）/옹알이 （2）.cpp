#include <string>   // erase 함수
#include <vector>

#include <iostream>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector <string> available = {"aya", "ye", "woo", "ma"};
    
    bool same;
    
    int beforeSaidEle = -1;  // 이전에 말한 available의 단어의 index 번호
    bool continuing = false;
    
    for(int i=0; i<babbling.size(); i++)
    {
        if(continuing != true)    // 이전에 확인했던 단어를 다시 확인하는 경우가 아닐 때에만
        {
            beforeSaidEle = -1;
            // 이전에 확인했던 단어를 다시 확인하는 경우라면, beforeSaidEle를 유지
        }
        
        continuing = false; // 일단 여기서는 false로 바꿔주기. 만약 다시 확인해야 되면, 가장 마지막 if문 (남은 글자수가 0이 아닐 때), true로 바뀔 것임.
        // 여기서 false로 안바꿔주면, continuing은 계속 true로 유지될 테니까
        
        // 각 단어마다 확인하기

        for(int ele = 0; ele < available.size(); ele++)
        {
            same = true;
            for(int l = 0; (l < available[ele].length()) && (l < babbling[i].length()); l++)
            {
                if(babbling[i][l] != available[ele][l])
                {
                    same = false;
                    break;
                }
            }
            // 만약 모든 글자가 동일하다면, same은 true로 나올 것임
            // *** 조건 추가: 현재 파악하고 있는 글자(babbling[i])가 available[ele]보다 크거나 같은지 확인
                // 만약, 현재 파악하고 있는 글자가 avaliable[ele]보다 작으면, 위 for문에서 길이 제한의 문제로 for문을 모두 안 거친채 same = true로 넘어왔을 수도 있기 때문
            if((same == true) && (beforeSaidEle != ele) && (babbling[i].length() >= available[ele].length()))
            {
                babbling[i].erase(0, available[ele].length());  // 0번째 알파벳부터 해당 단어 길이만큼 지우기
                if(babbling[i].length() == 0)   // 길이가 0이 되었다면, 그 babbling[i] 단어는 조카가 발음할 수 있는 것임
                {
                    cout << "babbling의 " <<  i << " 번째 단어 말할 수 있음 \n";
                    answer++;
                }
                else
                {
                    // 아직 0이 안되었다면, 동일한 단어를 한번 더 확인하기
                    i--;
                    
                    continuing = true;
                    beforeSaidEle = ele;
                    
                }
                
                break;
            }


        }
    }
    return answer;
}