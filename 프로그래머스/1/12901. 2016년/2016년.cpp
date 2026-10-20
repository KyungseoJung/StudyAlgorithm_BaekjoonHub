#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    // 윤년: 2월이 29일까지 있음
    
    // 1) 일단 며칠이 지났는지부터 확인하기
    vector <int> monthDay = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  // 각 달별로 며칠씩 있는지 확인 (1월은 1부터 시작하는 것으로 설정. 첫 0은 아무 의미 없음)
    
    // 31일까지 있는 달: 1, 3, 5, 7, 8, 10, 12
    // 30일까지 있는 달: 4, 6, 9, 11
    // 29일까지 있는 달: 2

    int day = 0;    // 며칠이 지났는지 확인하기 위한 변수
    if(a == 1)
    {
        day = b - 1;
    }
    else
    {
        for(int month = 1; month < a; month++)
        {
            day += monthDay[month];
        }
        day += (b - 1);
    }

    // 2) 며칠이 지났는지 알게 됐으니, 이제 무슨 요일인지 확인하기
    day = day % 7;
    vector <string> week = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    answer = week[day]; // 0이면 FRI, 1이면 SAT, ...
    
    
    return answer;
}