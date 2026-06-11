#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    int surroundRow, surroundCol;
    // 지뢰가 있는 지역은 1, 위험지역은 2로 설정한다고 하자
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board.size(); j++)
        {
            // board를 둘러보면서 1이 있다면, (지뢰 위치는 포함 X) 주변 칸들을 모두 2로 만들어주자.
            if(board[i][j] == 1)
            {
                // 최대 8칸이 주변에 있을 수 있음.
                for(int row = -1; row <= 1; row++)
                {
                    for(int col = -1; col <= 1; col++)
                    {
                        surroundRow = i +row;
                        surroundCol = j + col;
                        if((surroundRow >= 0) && (surroundRow < board.size()) && (surroundCol >= 0 ) && (surroundCol < board.size() )   )
                        {
                            if(board[surroundRow][surroundCol] != 1)    // 지뢰가 있는 곳까지 2로 만들어버리면, 그 다음 차례에 지뢰를 감지하지 못할 수 있으므로
                            {
                                board[surroundRow][surroundCol] = 2;        
                                
                            }
                              
                        }
                    
                    }
                }

            }
            
        }
    }
    
    
    // 안전 지대를 카운팅하자 (지뢰가 있는 곳과, 위험 지역을 제외하고)
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board.size(); j++)
        {
            if(board[i][j] == 0) 
            {
                answer++;
            }
        }
    }
    
    return answer;
}