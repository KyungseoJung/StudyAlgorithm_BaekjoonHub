#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    answer = "fail";
    for(int i=0; i<db.size(); i++)
    {
        if(db[i][0] == id_pw[0])
        {
            if(db[i][1] == id_pw[1])
            {
                answer = "login";
                break;  // 한명이라도 fit하게 맞는 사람이 있다면 for문 바로 탈출
            }
            else
            {
                answer = "wrong pw";
            }
        }
    }
    
    return answer;
}