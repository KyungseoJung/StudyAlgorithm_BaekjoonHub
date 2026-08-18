#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int size = arr.size();
    int num = 1;    // 2^0 (=1)부터 시작
    while(true)
    {
        if(size > num)
        {
            num = num * 2;
        }
        else if(size <= num)
        {
            // 이제 바로 num 값을 이용하면 됨
            break;
        }
    }
    // 추가해야 하는 0의 개수
    int addNum = num - size;
    
    answer = arr;
    for(int i=0; i<addNum; i++)
    {
        answer.push_back(0);
    }
    
    return answer;
    
}