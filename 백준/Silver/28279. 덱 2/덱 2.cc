#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;
int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;  // 명령의 수 N
    cin >> N;
    int command;
    int commandInt;
    deque <int> dq;

/*  1 X: 정수 X를 덱의 앞에 넣는다. (1 ≤ X ≤ 100, 000)
    2 X : 정수 X를 덱의 뒤에 넣는다. (1 ≤ X ≤ 100, 000)
    3 : 덱에 정수가 있다면 맨 앞의 정수를 빼고 출력한다.없다면 - 1을 대신 출력한다.
    4 : 덱에 정수가 있다면 맨 뒤의 정수를 빼고 출력한다.없다면 - 1을 대신 출력한다.
    5 : 덱에 들어있는 정수의 개수를 출력한다.
    6 : 덱이 비어있으면 1, 아니면 0을 출력한다.
    7 : 덱에 정수가 있다면 맨 앞의 정수를 출력한다.없다면 - 1을 대신 출력한다.
    8 : 덱에 정수가 있다면 맨 뒤의 정수를 출력한다.없다면 - 1을 대신 출력한다.*/
    while (N--)
    {
        cin >> command;
        switch (command)
        {
        case 1 : 
            cin >> commandInt;
            dq.push_front(commandInt);
            break;
        case 2:
            cin >> commandInt;
            dq.push_back(commandInt);            
            break;
        case 3:
            if (dq.empty())
                cout << "-1\n";
            else
            {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
            break;
        case 4:
            if (dq.empty())
                cout << "-1\n";
            else
            {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
            break;
        case 5:
            cout << dq.size() << "\n";
            break;
        case 6:
            if (dq.empty())
                cout << "1\n";
            else
                cout << "0\n";
            break;
        case 7:
            if (dq.empty())
                cout << "-1\n";
            else
            {
                cout << dq.front() << "\n";
            }
            break;
        case 8:
            if (dq.empty())
                cout << "-1\n";
            else
            {
                cout << dq.back() << "\n";
            }
            break;
        }
    }
    


    return 0;
}