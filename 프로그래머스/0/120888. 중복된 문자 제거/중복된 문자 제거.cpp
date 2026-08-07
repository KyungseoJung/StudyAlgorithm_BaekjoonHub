#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    answer = my_string;
    int ele = 0;
    while(ele < answer.size())
    {
        for(int i=ele+1; i<answer.size(); i++)
        {
            if(answer[i] == answer[ele])
            {
                answer.erase(i, 1); // i번째 인덱스부터 1개 글자 삭제하기
                i --;   // 삭제함으로써 한칸씩 앞으로 당겨지기 때문에, i번째 알파벳을 다시 검사해야 함.
            }
        }
        ele++;
    }
    return answer;
}