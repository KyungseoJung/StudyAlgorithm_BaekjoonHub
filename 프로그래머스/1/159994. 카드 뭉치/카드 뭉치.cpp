#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int ele1 = 0;   // cards1의 사용해야 하는 현재 index
    int ele2 = 0;   // cards2의 사용해야 하는 현재 index
    
    answer = "Yes"; // No라면, 아래 for문에서 걸러지게 되어있음
    
    for(int i=0; i<goal.size(); i++)
    {
        if((goal[i] == cards1[ele1]))
        {
            ele1++;
        }
        else if((goal[i] == cards2[ele2]))
        {
            ele2++;
        }
        else
        {
            answer = "No";
            break;  // for문 종료
        }
    }
    
    return answer;
}