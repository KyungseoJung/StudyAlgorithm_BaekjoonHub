#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    int num1, num2;
    int laterSum = 0;   // 다음 자릿수에 더할 숫자
    // 예외 처리 해주기
    if((bin1 == "0") && (bin2 == "0") )
    {
        answer = "0";
    }
    else
    {
        while( (stoi(bin1) > 0) || (stoi(bin2) > 0) )
        {
            if(stoi(bin1) > 0)
            {
                num1 = stoi(bin1) % 10;
                bin1 = to_string (stoi(bin1) / 10);
            }
            else 
            {
                num1 = 0;
            }
            if(stoi(bin2) > 0)
            {
                num2 = stoi(bin2) % 10;
                bin2 = to_string ( stoi(bin2) / 10);
            }
            else
            {
                num2 = 0;
            }

            // 일의 자리, 십의 자리, 백의 자리, ... 순서대로 계산하기
            if(laterSum + num1 + num2 >= 2)
            {
                answer = to_string((laterSum + num1 + num2) % 2) + answer; // ex) 먼저 일의 자리가 1이 있었고, 그 다음 십의 자리에서 계산했는데 2가 나왔다면, 101로 작성해야 함
                laterSum = 1;
                cout << "더하기: " << answer << "\n";
            }
            else
            {
                answer = to_string(laterSum + num1 + num2) + answer;
                laterSum = 0;
                cout << "더하기: " << answer << "\n";
            }
        }

        // 마지막에 laterSum 더해주기
        if(laterSum == 1)   // laterSum이 어차피 2이상의 숫자가 될 수는 없으므로 1인지 아닌지만 검사하면 됨
        {
            answer = "1" + answer;
        }

        
    }

    return answer;
}