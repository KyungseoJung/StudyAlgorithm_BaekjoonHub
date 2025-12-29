#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string H, N;
    cin >> H >> N;

    int count = 0;

    for (int i = 0; i + N.length() <= H.length(); i++)
    {
        bool same = true;
        for (int j = 0; j < N.length(); j++)
        {
            if (H[i + j] != N[j])
            {
                same = false;
                break;
            }
        }
        if (same) count++;
    }

    cout << count;
    return 0;
}
