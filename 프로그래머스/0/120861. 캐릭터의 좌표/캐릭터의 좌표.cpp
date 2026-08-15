#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    
    int row = 0;    // 머쓱이의 위치
    int col = 0;    // 머쓱이의 위치
    int maxRow = board[0]/2;    // 가로로 갈 수 있는 최대 길이
    int maxCol = board[1]/2;    // 세로로 갈 수 있는 최대 길이
    
    for(int i=0; i<keyinput.size(); i++)
    {
        if(keyinput[i] == "up")
        {
            if(abs(col + 1) > maxCol)
            {
                col = col;
            }
            else
            {
                col++;
            }
        }
        else if(keyinput[i] == "down")
        {
            if(abs(col-1) > maxCol)
            {
                col = col;
            }
            else
            {
                col--;
            }
        }
        else if(keyinput[i] == "right")
        {
            if(abs(row+1)> maxRow)
            {
                row = row;
            }
            else
            {
                row++;
            }
        }
        else if(keyinput[i] == "left")
        {
            if(abs(row-1) > maxRow)
            {
                row = row;
            }
            else
            {
                row--;
            }
        }
    }
    answer.push_back(row);
    answer.push_back(col);
    
    return answer;
}