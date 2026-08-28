#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    string answer = "";
    int i = 0;
    while(true)
    {
        if(n_str[i] == '0')
        {
            n_str.erase(0, 1);
        }
        else
        {
            break;
        }
    }
    answer = n_str;
    return answer;
}