#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    vector<int> answer;
    answer = numbers;
    int popNum;
    if(direction == "right")
    {
        popNum = answer.back();
        answer.pop_back();
        answer.insert(answer.begin(), popNum);
    }
    else
    {
        popNum = answer[0];
        answer.erase(answer.begin());
        answer.push_back(popNum);
    }

    return answer;
}