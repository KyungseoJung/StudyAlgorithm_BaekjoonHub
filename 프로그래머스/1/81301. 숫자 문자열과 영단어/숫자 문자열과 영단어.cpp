#include <string>
#include <vector>

#include <cctype>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    string answerString = "";
    vector <string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for(int i=0; i<s.length(); i++)
    {
        if(isdigit(s[i]))
        {
            answerString = answerString + s[i];
            cout << s[i] << "는 숫자 \n";
            cout << "answerString 상태: " << answerString << "\n";

        }
        else
        {
            bool same = true;
            int passLen;    // i를 전진시키기 위해서 글자 길이를 저장해줘야 함.
            for(int j=0; j<numbers.size(); j++)   // j번째 숫자 string과 비교해주기
            {
                same = true;
                for(int k=0; (k<numbers[j].length()) && (i + k <s.length()); k++)
                {
                    if(s[i + k] != numbers[j][k])
                    {
                        same = false;
                        break;
                    }
                }
                if(same == true)
                {
                    answerString = answerString + to_string(j);
                    cout << "찾았다. 이 문장은 숫자: " << j << "\n";
                    cout << "answerString 상태: " << answerString << "\n";
                    
                    // *** i를 전진시켜주기 ***
                    passLen = numbers[j].length();
                    i += (passLen - 1);
                    break;
                }
            
            }
        }
    }
    
    answer = (stoi)(answerString); 
    return answer;
}