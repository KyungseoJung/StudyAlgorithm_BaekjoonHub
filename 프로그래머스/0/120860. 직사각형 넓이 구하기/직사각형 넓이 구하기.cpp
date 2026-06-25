#include <string>
#include <vector>
#include <cmath>    // abs 함수 사용하기 위함

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    // 0번째 dot와 같은 x값을 가진 점을 찾기 -> firstDotEle
    // 0번째 dot와 firstDotEle번째 dot값의 높이차를 기반으로 높이 값을 구하기
    int firstDotEle;
    for(int i=1; i<dots.size(); i++)
    {
        if(dots[i][0] == dots[0][0])
        {
            firstDotEle = i;
        }
    }
    int height = abs(dots[0][1] - dots[firstDotEle][1]);
    
    // 0번째, firstDotEle번째가 아닌 dot에 대해서 x값을 찾기 -> secondDotEle
    // 0번째 x값과 secondDotEle번째 x값의 차이를 이용해서 너비 값을 구하기
    int width;
    for(int i=1; i<dots.size(); i++)
    {
        if(i != firstDotEle)
        {
            width = abs(dots[0][0] - dots[i][0]);
            break;
        }
    }
    
    
    answer = height * width;
    
    return answer;
}