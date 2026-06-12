#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int answer = -1;
    // 최대 서비스를 받는 방법은, 열 마리당 먹으면서 쿠폰을 무조건 받기
    int firstChicken = chicken; // 첫 치킨 수 저장
    int sum = 0;    // 총 먹은 치킨의 ㅜ
    while(chicken >= 10)
    {
        chicken -= 10;
        chicken ++; // 쿠폰으로 하나 추가
        sum += 10;  // 먹은 치킨 개수 추가     
    }
    if(chicken > 0)
    {
        sum += chicken;
    }
    
    answer = sum - firstChicken;
    
    return answer;
}