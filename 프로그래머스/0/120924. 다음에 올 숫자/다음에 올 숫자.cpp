#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> common) {
    int answer = 0;

    bool sameDiff = true;  // 등차수열인지 확인
    int diffNum = common[1] - common[0];
    for (int i = 1; i < common.size()-1; i++)
    {
        if (common[i + 1] - common[i] != diffNum)
        {
            cout << i + 1 << "번째 요소 - " << i << "번째 요소 = " << (common[i + 1] - common[i]) << "등차가 diffNum(" << diffNum << ")과 다름\n";
            sameDiff = false;
            break;
        }
    }


    bool sameRatio = true; // 등비수열인지 확인
    int ratioNum;
    if (sameDiff == false)
    {
        ratioNum = common[1] / common[0];
        for (int i = 1; i < common.size()-1; i++)
        {
            if (common[i + 1] / common[i] != ratioNum)
            {
                cout << i + 1 << "번째 요소 / " << i << "번째 요소 = " << (common[i + 1] / common[i] ) << "등차가 diffNum(" << ratioNum << ")과 다름\n";

                sameRatio = false;
                break;
            }
        }
    }

    if (sameDiff == true)
    {
        answer = common[common.size() - 1] + diffNum;
    }
    else
    {
        answer = common[common.size() - 1] * ratioNum;
    }

    return answer;
}
