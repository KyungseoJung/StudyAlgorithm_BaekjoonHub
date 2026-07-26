#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer;
    
// erase 함수의 기본 원칙
// erase(arr.begin() + a, arr.begin() + b); =>>> a번째부터 b-1번째까지 원소 삭제 
// erase(arr.begin(), arr.end());       =>>> 처음부터 끝까지 모두 삭제
    // (원칙적으로 끝 원소는 포함하지 않음. 단, end를 사용하면 끝까지 삭제하는 것!)
    for(int i=0; i < query.size(); i++)
    {
        switch(i % 2)   // 짝수 인덱스, 홀수 인덱스라는 말은 query[i]가 홀짝인지 보라는 게 아니라, 짝수번째/홀수번째 인덱스인지 보라는 것이었다...
        {
            case 0 :    // 짝수인경우
                arr.erase(arr.begin() + query[i] + 1, arr.end());
                break;
            case 1 :    // 홀수인경우
                arr.erase(arr.begin(), arr.begin() + query[i]);
                break;
        }
    }
    answer = arr;

    return answer;
}