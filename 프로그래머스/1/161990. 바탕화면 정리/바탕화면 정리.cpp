#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    // 제일 작은 x값과 y값을 시작으로 ----> 제일 큰 x값과 y값을 끝으로 잡으면 됨
    // 1) 제일 작은 x값과 제일 작은 y값 찾기
    int minRow = 999;
    int minCol = 999;
    int maxRow = -1;
    int maxCol = -1;
    for(int i=0; i<wallpaper.size(); i++)
    {
        for(int j=0; j<wallpaper[i].length(); j++)
        {
            if(wallpaper[i][j] == '#')
            {
                if(i < minRow)
                {
                    minRow = i;
                }
                
                if(j < minCol)
               {
                   minCol = j;
               }
                
                if(i > maxRow)
                {
                    maxRow = i;
                }
                
                if(j > maxCol)
                {
                    maxCol = j;
                }
            }
        }
    }
    
    // 시작점: (minX, minY)
    // 끝점: (maxX + 1, maxY + 1)
    
    answer.push_back(minRow);
    answer.push_back(minCol);
    answer.push_back(maxRow + 1);
    answer.push_back(maxCol + 1);
    return answer;
}