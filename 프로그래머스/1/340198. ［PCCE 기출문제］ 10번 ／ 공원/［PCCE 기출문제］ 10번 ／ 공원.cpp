#include <string>
#include <vector> 
#include <iostream>
#include <algorithm> // sort 함수 사용 목적
using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    // mats 정렬하기
    sort(mats.begin(), mats.end()); // 작은 숫자가 앞으로, 큰 숫자가 뒤로 가도록 정렬
     
    int answer = -1;
    int sum = 0;
    bool empty;
    for(int m = mats.size()-1 ; m >= 0; m--) // 다양한 mats 종류별로 확인하기 (큰 사이즈부터 가능한지 확인)
    {
        int size = mats[m];
        if(size > (int)park.size() || size > (int)park[0].size()) continue; // 공원보다 큰 돗자리는 스킵


        for(int row = 0; row < park.size() - mats[m] +1; row++)
        {
            for(int col = 0; col < park[0].size() - mats[m] + 1; col++)
            {
                sum = 0;
                empty = true;
                for(int r = 0; r < mats[m]; r++)
                {
                    for(int c = 0; c < mats[m]; c++)
                    {
                        if(park[row+r][col+c] != "-1")
                        {
                            empty = false;
                            break;
                        }
                    }

                }
                if(empty == true)
                {
                    answer = mats[m];
                    return answer;
                }
            }
        }
    }

    
    return answer;
}