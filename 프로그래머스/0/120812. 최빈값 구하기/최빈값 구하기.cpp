#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    vector<int> count(1000, 0);   // 모두 0으로 설정
    
    for(int i=0; i<array.size(); i++)
    {
        count[array[i]] ++;
    }
    
    // 최빈값 확인하기
    int max = -1;
    bool duplication = false;   // 중복인지 아닌지 체크
    for(int i=0; i<1000; i++)
    {
        if(count[i] > max)
        {
            max = count[i];
            answer = i;
            duplication = false;
        }
        else if(count[i] == max)
        {
            duplication = true;
            answer = -1;
        }
    }
    
    return answer;
}