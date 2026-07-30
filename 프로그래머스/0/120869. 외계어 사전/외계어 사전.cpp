#include <string>
#include <vector>

#include <iostream>
using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 0;
    
    vector <int> count;
    int size = spell.size();
    
    answer = 2; // 기본적으로 2로 설정해두고, 아래 for문에서 적절한 단어가 나타나면 1로 바꾸기
    bool find;
    for(int i=0; i<dic.size(); i++)
    {
        count.assign(size, 0);  // 단어들 확인할 때마다 모든 원소를 0으로 재할당 및 초기화
        
        for(int j=0; j<dic[i].length(); j++)    // 각 단어의 알파벳 모두 확인 및 spell과 비교하기
        {
            for(int k=0; k<spell.size(); k++)
            {
                cout << "spell의 " << k << "번째:" ;
                // cout << spell[k] ;
                cout << spell[k][0];    // ****** 이렇게 하면, string을 char로 가져올 수 있지 않을까? ******
                
                cout << " | dic의 " << i << "번째 단어의 " << j << "번째 알파벳:";
                cout << dic[i][j] << "\n";
                // cout << to_string(dic[i][j]) << "\n";
                // to_string으로 하면 안되는구나..
                
                // if(to_string(dic[i][j]) == spell[k])
                if(dic[i][j] == spell[k][0])
                {
                    cout << "같음---\n";
                    count[k] ++;
                }
            }
        }
        
        // 알파벳을 한번씩만 모두 사용한 단어가 있는지 확인
        find = true;
        for(int j=0; j < size; j++)
        {
            if(count[j] != 1)   // 모두 1이라면 find = true로 나오도록
            {
                find = false;
            }
        }
        
        if(find == true)
        {
            answer = 1;
            break;  // 하나라도 존재한다면, for문을 더 돌면서 확인할 필요 없음.
        }
    }
    

    return answer;
}