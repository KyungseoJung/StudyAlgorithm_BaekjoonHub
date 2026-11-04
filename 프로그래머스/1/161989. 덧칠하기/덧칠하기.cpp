#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    vector <bool> painted(section.size(), false);  // 각 section이 색칠해졌는지 확인하기 위한 vector // 첫 시작은 모두 false
    
    // 페인트칠 길이가 m이고 시작이 s라면, s부터 s+m-1까지 색칠해짐
    int startEle;
    for(int i=0; i<section.size(); i++) 
    {
        if(painted[i] == false)
        {
            startEle = section[i];
            for(int j=i+1; j<section.size(); j++)   // 벽에서 벗어나는 건 신경쓰지 말자. 어차피 j에서 범위를 넘어서지 않을 것이고, 실제 세계에서는 그냥 범위를 넘어서게 되면, 오히려 반대 방향으로(맨 왼쪽 끝에서 오른쪽으로) 색칠한다고 가정하면 됨
            {
                if((section[j] <= section[i]+m-1) && (painted[j] == false))
                {
                    painted[j] = true;
                }
            }
            
            answer++;
        }
    }
    
    return answer;
}