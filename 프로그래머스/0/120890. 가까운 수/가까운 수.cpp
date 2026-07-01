#include <string>
#include <vector>
#include <cmath>    // abs 사용 목적
using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    int diff = 999;
    int ele;
    for(int i=0; i<array.size(); i++)
    {
        if(abs(array[i] - n) < diff)
        {
            ele = i;
            diff = abs(array[i] - n);
        }
        else if (abs(array[i] - n) == diff)
        {
            if(array[i] < array[ele])
            {
                ele = i;    // 가장 가까운 수가 여러 개일 경우, 더 작은 수가 최종 answer
            }
        }
    }
    
    answer = array[ele];
    return answer;
}