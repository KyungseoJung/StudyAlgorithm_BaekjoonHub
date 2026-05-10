#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    answer = 2; // 처음 디폴트 값은 2 (str1 안에 str2이 있는 것을 발견하면 1로 바꾸기)
    bool same = true;
    for(int i=0; i<str1.length(); i++)
    {
        if(str1[i] == str2[0])
        {
            same = true;
            for(int j=1; j<str2.length(); j++)
            {
                if(str1[i+j] != str2[j])
                {
                    same = false;
                    break;
                }
            }
            if(same == true)    // same이 여전히 true이면, 위에서 달랐던 문자가 하나도 없는 것이므로
            {
                answer = 1;         
                
            }

        }
    }
    return answer;
}