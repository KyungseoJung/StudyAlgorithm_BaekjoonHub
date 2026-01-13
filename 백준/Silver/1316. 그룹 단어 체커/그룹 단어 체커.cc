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
// 5054 문제: 주차의 신

int main()
{
    // 코드 속도 빠르게 하기 위한 설정
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    string input;
    vector <char> already;  // 이미 등장한 알파벳을 저장하는 vector
    char current;   // 현재 반복되고 있는, 또는 가장 마지막에 사용한 알파벳 저장용

    bool groupWord;
    int countGroupWord = 0;
    while (N--)
    {
        groupWord = true;
        already.clear();    // 각 단어마다 완전히 비우기
        cin >> input;
        current = input[0];

        for (int i = 1; i < input.length(); i++)
        {
            if (current != input[i])
            {
                // 새로 등장한 글자 input[i]가 이미 등장한 적 있는 단어는 아닌지 확인
                // 이미 등장한 적 있다면, 이 단어는 그룹단어가 아님
                for (int j = 0; j < already.size(); j++)
                {
                    if (input[i] == already[j])
                    {
                        groupWord = false;
                        break;
                    }
                }

                // 등장해본 적 없는 알파벳이라면
                // 기존에 사용했던 알파벳을 already에 저장하고, current를 input[i]로 업데이트하기
                already.push_back(current);
                current = input[i];
            }

            if (groupWord == false)
            {
                break;
            }
        }

        // 만약 모든 자릿수를 검사했는데, 그룹단어가 맞다면 카운팅+1
        if (groupWord == true)
        {
            countGroupWord++;
        }
    }
    
    cout << countGroupWord;
    return 0;
}