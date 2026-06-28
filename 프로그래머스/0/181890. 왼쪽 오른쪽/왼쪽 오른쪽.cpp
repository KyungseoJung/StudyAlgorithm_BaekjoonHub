#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> str_list) {
    vector<string> answer;
    // bool exist = false;  // 생각해보니 l이나 r이 없으면 그냥 안 넣으면 되는 거라서, bool 처리로 따로 확인할 필요 없을 듯
    for(int i=0; i<str_list.size(); i++)
    {
        if(str_list[i] == "l")
        {
            // exist = true;
            for(int j =0; j< i; j++)
            {
                answer.push_back(str_list[j]);
            }
            break;
        }
        else if(str_list[i] == "r")
        {
            // exist = true;
            for(int j= i+1; j<str_list.size(); j++)
            {
                answer.push_back(str_list[j]);
            }
            break;
        }
    }
    return answer;
}