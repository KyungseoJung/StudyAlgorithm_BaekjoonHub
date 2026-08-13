#include <string>
#include <vector>

#include <cctype>   // isdig 함수 사용하기 위함
#include <algorithm>    // sort 함수 사용하기 위함

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    for(int i=0; i<my_string.length(); i++)
    {
        if(isdigit(my_string[i]))   // 숫자이면 0이 아닌 값이 나옴. 따라서, ==true로 작성하는 건 오담 
        {
            answer.push_back(my_string[i] - '0');
        }
    }
    
    // 오름차순 정렬
    sort(answer.begin(), answer.end());
    return answer;
}