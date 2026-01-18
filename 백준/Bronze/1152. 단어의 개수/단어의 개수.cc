#include <iostream>
#include <vector>
#include <stack>		// stack 사용하기 위함
#include <queue>		// queue 사용하기 위함
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
#include <set> // set 사용하기 위함
using namespace std;
// 1152 문제: 단어의 개수


int main()
{
    // 코드 속도 빠르게 하기 위한 설정
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string input;
    //cin >> input;
    getline(cin, input);    // 이렇게 입력받아야 띄어쓰기도 포함된 한 줄을 통째로 input에 넣음

    bool blank = true;
    int count = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ')
        {
            blank = true;
        }
        else // 현재 빈칸이 아닌데,
        {
            //cout << "현재 글자: " << input[i] << " | 이전 blank 상태: " << blank << "\n";
            if (blank == true)    // 이전에 빈칸이었다면, 지금 새로운 단어가 등장한 것이므로 카운팅+1
            {
                count++;
            }
            // 이전에 빈칸이 아니었다면, 그냥 아무것도 아님~
             
            blank = false;  // 새롭게 설정해주기
        }
    }

    cout << count;
    return 0;
}