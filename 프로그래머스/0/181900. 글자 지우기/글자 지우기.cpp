#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    answer = my_string;
    // 뒷자리부터 지우면, 글자들이 앞으로 당겨오는 문제를 보완 가능하기 때문에
    // 일단 정렬부터 하기. 그 후, 뒤에 위치하는 인덱스부터 지워나가기 
    sort(indices.begin(), indices.end());
    
    for(int i=indices.size() -1 ; i>= 0; i--)
    {
        answer.erase(indices[i], 1);
    }
    
    return answer;
}