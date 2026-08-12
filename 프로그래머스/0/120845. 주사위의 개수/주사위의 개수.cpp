#include <string>
#include <vector>

using namespace std;

int solution(vector<int> box, int n) {
    int answer = 0;
    
    // box에 나와있는 숫자가 순서대로 가로, 세로, 높이라고 가정하자.
    // 1) 일단 가로, 세로만 생각해보면
        // 가로에 얼만큼 들어가는지 카운팅 - 만약 가로에 a개 만큼 들어갈 수 있다면
        // 세로에 얼만큼 들어가는지 카운팅 - 만약 세로에 b개 만큼 들어갈 수 있다면
        // 가로 * 세로에 들어갈 수 있는 개수는 a * b개임
    // 변수: 만약, 둘 중 하나라도 0이면 가로 * 세로에 들어갈 수 있는 개수는 0개임. 따라서 위 방식대로 계산하면 됨
    answer = (box[0] / n) * (box[1] / n);
    
    // 2) 높이도 동일하게 생각하면 됨
    answer = answer * (box[2] / n);
    
    return answer;
}