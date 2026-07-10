#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    int num;    // 시작하는 숫자 찾기 (= l이상이면서 5의 배수인 가장 작은 수)
    for(int i=0; i<5; i++)
    {
        if((l + i) % 5 == 0)
        {
            num = l+i;
            break;
        }
    }
    
    // 그냥 num부터 시작해서 r이하까지 +5를 더해주기. 
    // 그리고 그 수가 0과 5로만 이루어진 숫자인지 해당하는지 확인하기
    
    bool check = true;
    string numString;
    while(num <= r)
    {
        check = true;
        numString = to_string(num);
        for(int i=0; i<numString.length(); i++)
        {
            if((numString[i] != '0') && (numString[i] != '5'))
            {
                check = false;
                break;
            }
        }
        
        if(check == true)
        {
            answer.push_back(num);
        }
        
        num += 5;
        
    }
    
    if(answer.size() == 0)
    {
        answer.push_back(-1);
        
    }
    return answer;
}