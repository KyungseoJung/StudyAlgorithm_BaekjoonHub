#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    // A~Z까지 몇번 걸리는지 미리 저장해두면 간편할듯
    // 입력 불가능한 문자는 -1로 저장하기
    
    vector <char> alphabet; // A~Z까지의 알파벳을 저장해둔 vector 만들기
    char charEle;
    int len = 26;
    for(int i=0; i<len; i++) 
    {
        charEle = char('A' + i);
        alphabet.push_back(charEle);
    }
    
    vector <int> charCount(len); // A(0)부터 Z(25)까지 26개의 알파벳을 입력할 때 각각 키를 몇번 눌러야 하는지 저장해두기
    bool find;
    for(int i=0; i<len; i++)
    {
        charEle = char('A' + i);
        charCount[i] = -1;
        find = false;
        
        for(int j=0; j<keymap.size(); j++)
        {
            for(int k=0; k<keymap[j].length(); k++)
            {
                if(keymap[j][k] == charEle)
                {
                    if(find == true)    // 만약 이미 찾은 상태이라면, 이전에 찾은 횟수보다 적을 때에만 업데이트해주기
                    {
                        if(k+1 < charCount[i])
                        {
                            charCount[i] = k+1;
                        }
                    }
                    else
                    {
                        charCount[i] = k + 1;
                        find = true;                        
                    }
                }
            }
        }
        
    }
    
    // 2) 이제 각 알파벳에 대해 횟수더해주기
    int sum;
    int ele;
    for(int i=0; i<targets.size(); i++)
    {
        sum = 0;
        for(int j=0; j<targets[i].length(); j++)
        {
            ele = int(targets[i][j] - 'A');
            if(charCount[ele] == -1)    // 하나라도 표현 못하는 알파벳이 있다면 그냥 바로 -1 처리
            {
                sum = -1;
                break;
            }
            else
            {
                sum += charCount[ele];            
            }
        }
        answer.push_back(sum);
    }
    
    return answer;
}