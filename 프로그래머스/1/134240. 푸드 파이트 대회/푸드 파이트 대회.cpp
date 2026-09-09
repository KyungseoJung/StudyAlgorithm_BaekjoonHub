#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    int size = food.size();
    vector <int> foodNums(size);  // 1번~9번 음식을 각 한 선수당, 몇 개를 먹는 것으로 배치할지
    for(int i=1; i < size; i++)
    {
        foodNums[i] = (food[i] / 2);
    }
    
    // 왼쪽부터 먹는 선수가 먹을 음식 번호를, answer에 넣기
    for(int i=1; i< size; i++)
    {
        for(int j=0; j<foodNums[i]; j++)
        {
            answer = answer + to_string(i);        
        }
    }
    answer = answer + "0";
    
    // 오른쪽부터 먹는 선수가 먹을 음식 번호를, answer에 넣기
    for(int i=size -1; i>=1; i--)
    {
        for(int j=0; j<foodNums[i]; j++)
        {
            answer = answer + to_string(i);        
        }
    }
    
    return answer;
}