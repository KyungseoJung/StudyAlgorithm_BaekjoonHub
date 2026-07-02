#include <string>
#include <vector>

#include <iostream> // 디버깅용
using namespace std;

long long solution(string numbers) {
    long long answer = 0;
    string answerString = "";
    
    vector <string> english = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    bool same = false;
    
    // for(int i=0; i<numbers.size(); i++)
    while(numbers.size() > 0)
    {
        for(int j=0; j<english.size(); j++)
        {
            same = false;
            // 단어가 맞는지 확인하기
            if(numbers[0] == english[j][0])
            {
                same = true;
                // 첫번째 알파벳이 동일하다면, 다음 알파벳들도 동일한지 확인하기
                for(int k=1; k<english[j].length(); k++)
                {
                    if(numbers[k] != english[j][k])
                    {
                        same = false;
                        break;  // 하나라도 다르면 더 볼 거 없음
                    }
                }
            }
            
            if(same == true)    // 위 for문을 모두 거쳤는데도 true라면 (대응되는 숫자를 찾은 것임)
            {
                numbers.erase(0, english[j].length());  // 문장(numbers)의 0부터 english[j]의 길이에 해당하는 만큼 지우기
                cout << "현재 numbers: " << numbers << " 추가할 숫자: " << j << "\n";
                // answerString += to_string(j); 
                answer = answer * 10 + j;   // 한칸씩 앞으로 땡겨주고, 새로운 숫자 j를 일의 자리에 넣어주기
                break;
            }
        }
        
    }
    
    // answer = stoi(answerString);
    return answer;
}