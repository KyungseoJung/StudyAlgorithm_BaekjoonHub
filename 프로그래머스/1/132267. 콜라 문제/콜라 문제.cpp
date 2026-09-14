#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while(n >= a)
    {
        n -= a;     // 마트에 a개 병을 줌
        
        n += b; // b개 병을 받음
        answer += b;    // 받은 개수 누적시키기
    }
    return answer;
}