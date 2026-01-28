#include <iostream>
#include <string>
using namespace std;
// 1681 문제: 줄 세우기

bool checkInclude(int num, int basis)
{
    // num에 basis라는 숫자가 포함되어 있는지 확인
    string numString;
    numString = to_string(num);

    char basisChar = basis + '0';

    for (int i = 0; i < numString.length(); i++)
    {
        if (numString[i] == basisChar)
        {
            return true;
        }
    }

    // 위 for문을 모두 통과했다면, num안에는 basis라는 숫자가 없는 것임.
    return false;

}

int main()
{
    // 코드 속도 빠르게 하기 위한 설정
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, L;
    cin >> N >> L;

    int check = 0;  // 라벨 받은 학생 수
    int ele = 1;
    while (true)
    {

        //if (checkInclude(ele, L) == true)
        //{
        //    
        //}
        if(checkInclude(ele, L) == false)
        {
            check++;
        }

        if (check >= N) // 현재까지 라벨 받은 학생의 수가 N명이 되면, while문 중단
        {
            cout << ele;
            return 0;
        }

        ele++;
    }

    return 0;
}