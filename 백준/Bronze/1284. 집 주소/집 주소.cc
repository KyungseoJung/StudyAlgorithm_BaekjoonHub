#include <iostream>
using namespace std;
// 1284 문제: 집 주소

int main()
{
    // 코드 빠르게 돌아가도록
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string input;
    int range;

    while (true)
    {
        cin >> input;
        if (input == "0")
        {
            return 0;
        }
        range = 0;

        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == '1')
            {
                range += 2;
            }
            else if (input[i] == '0')
            {
                range += 4;
            }
            else
            {
                // 그 외의 경우
                range += 3;
            }
        }
        cout << range + input.length() + 1 << "\n";
    }

    return 0;
}