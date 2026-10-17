#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다. 
    // cout << "Hello Cpp" << endl;
    
    
    vector <string> saidWords;  // 이미 말한 단어들
    char lastChar;  // 이전 단어의 마지막 글자 기억하기
    
    int person = 1;     // 사람의 번호 (1부터 시작)
    int turn = 1;       // 현재 몇 번째 차례의 게임인지 (1부터 시작)
    
    for(int i=0; i<words.size(); i++)
    {
        if(i != 0)
        {
            // 1) 마지막 글자를 그대로 말하지 않은 경우
            if(words[i][0] != lastChar)
            {
                cout << "-- " << words[i] << " 틀림 \n";
                // *** 틀림 ***
                answer.push_back(person);
                answer.push_back(turn);
                return answer;
            }
            
            // 2) 이미 나온 단어를 또 말한 경우            
            for(int ele = 0; ele < saidWords.size(); ele++)
            {
                if(saidWords[ele] == words[i])
                {
                    cout << words[i] << " 틀림 \n";
                    // *** 틀림 ***
                    answer.push_back(person);
                    answer.push_back(turn);
                    return answer;
                }
            }
        }
        lastChar = words[i][words[i].length()-1];
        saidWords.push_back(words[i]);
        
        person ++;
        if(person > n)
        {
            person -= n;
            turn++;
        }
        
        
    }

    // 탈락자가 없을 경우 
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}