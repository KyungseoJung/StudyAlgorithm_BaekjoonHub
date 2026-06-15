#include <string>
#include <vector>
#include <sstream>  // 토큰 추출을 위해 stringstream을 사용하기 위한 목적

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    for(int i=0; i<quiz.size(); i++)
    {
        stringstream ss(quiz[i]);
        
        // 또는 for(string s:quiz) -> stringstream ss(s)로 코드 작성해도 좋음
        int x, y, z;
        char op, eq;
        ss >> x >> op >> y >> eq >> z;
        
        if(op == '+')
        {
            if(x + y == z)
            {
                answer.push_back("O");
            }
            else
            {
                answer.push_back("X");
            }
        }
        else if(op == '-')
        {
            if(x - y == z)
            {
                answer.push_back("O");
            }
            else
            {
                answer.push_back("X");
            }
        }
    }
    
    return answer;
}