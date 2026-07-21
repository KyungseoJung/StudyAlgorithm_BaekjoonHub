#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    bool same = false;
    vector <int> before;
    while(true)
    {        
        // 저장용
        before = arr;
        
        // 규칙 적용
        for(int i=0; i<arr.size(); i++)
        {
            if((arr[i] % 2 == 0) && (arr[i] >= 50))
            {
                arr[i] = arr[i] / 2;
            }
            else if((arr[i] % 2 == 1) && (arr[i] < 50))
            {
                arr[i] = arr[i] * 2 + 1;
            }
        }
        answer += 1;
        
        // 같은지 확인
        same = true;
        for(int i=0; i<arr.size(); i++)
        {
            if(before[i] != arr[i])
            {
                same = false;
            }
        }
        
        
        // 만약 같다면 그 값이 정답
        if(same == true)
        {
            break;
        }
    }
    
    // 헷갈린 점: arr(0) = arr(1)이라면 x는 1이 아니라, 0이 답임.
    answer -= 1;
    
    return answer;
}