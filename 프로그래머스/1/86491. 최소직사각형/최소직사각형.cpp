#include <string>
#include <vector>


#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int len = sizes.size();
    // 가로, 세로 길이 중 -> 더 긴 길이와 더 짧은 길이를 따로 저장하기
    vector<int> longs(len);
    vector<int> shorts(len);
    
    for(int i=0; i<len; i++)
    {
        if(sizes[i][0] > sizes[i][1])
        {
            longs[i] = sizes[i][0];
            shorts[i] = sizes[i][1];
        }
        else
        {
            longs[i] = sizes[i][1];
            shorts[i] = sizes[i][0];
        }
    }
    
    // 긴 길이 중 가장 긴 길이를 구하기
    int max1 = 0;
    int max2 = 0;
    for(int i=0; i<len; i++)
    {
        if(longs[i] > max1)
        {
            max1 = longs[i];
        }
    }
    // 짧은 길이 중 가장 긴 길이를 구하기
    for(int i=0; i<len; i++)
    {
        if(shorts[i] > max2)
        {
            max2 = shorts[i];
        }
    }
    
    cout << max1 << " " << max2 << "\n";
    
    answer = max1 * max2;
    
    return answer;
}