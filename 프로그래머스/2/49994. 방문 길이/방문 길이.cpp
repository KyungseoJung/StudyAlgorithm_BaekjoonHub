#include <string>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    // (-5, 5)부터 (5, -5)까지 각 길을 표현해보자면,
    // 가로로 10길이 * 10줄    // 세로로 10길이 * 10줄
    // 총 200개의 값만 확인할 수 있는 변수가 있으면 됨
    // 왼쪽 하단을 (0,0)으로 잡고, 3차원 배열만 있으면 표현할 수 있음 -> arr[11][11][2]
        // 첫 번째 차원: 각 경로의 가장 오른쪽의 x좌표 나타내기 (0 ~ 10)
        // 두 번째 차원: 각 경로의 가장 윗쪽의 y좌표 나타내기   (0 ~ 10)
        // 세 번째 차원: 각 경로가 수평모양인지(0), 수직모양인지(1)
    
    // 1) 지나간 길을 확인하는 3차원 배열 설정
    int pass[11][11][2] = {};   // 처음엔 0으로 설정
    
    // 2) 게임 캐릭터의 첫 위치: (5,5)로 두기
    int posX = 5;
    int posY = 5;
        
    // 3)지나간 길을 확인하기 (상하좌우 순서대로 U, D, L, R)
    for(int i=0; i<dirs.length(); i++)
    {
        switch(dirs[i])
        {
            case 'U':
                if(posY == 10)  // 10이면 그만 이동하기 (이미 위쪽 끝에 위치함)
                {
                    break;
                }
                else
                {
                    posY++;
                    if(pass[posX][posY][1] != 1)    // 처음 걸어본 길이라면
                    {
                        answer++;
                        pass[posX][posY][1] = 1;
                    }
                    break;                    
                }

            case 'D':
                if(posY == 0)   // 0이면 그만 이동하기  (이미 아래쪽 끝에 위치함)
                {
                    break;
                }
                else
                {
                    if(pass[posX][posY][1] != 1)    // 처음 걸어본 길이라면
                    {
                        pass[posX][posY][1] = 1;
                        answer++;
                    }
                    posY--; // 가장 윗쪽의 y좌표를 저장하는 거니까, 좌표 먼저 저장하고 posY를 -1해주기
                    break;
                }

            case 'L':
                if(posX == 0)   // 0이면 그만 이동하기 (이미 왼쪽 끝에 위치함)
                {
                    break;
                }
                else
                {
                    if(pass[posX][posY][0] != 1)    // 처음 걸어본 길이라면
                    {
                        pass[posX][posY][0] = 1;
                        answer++;
                    }
                    posX--; // 가장 오른쪽의 x좌표를 저장하는 거니까, 좌표 먼저 저장하고 posX를 -1해주기
                    break;                    
                }
            
            case 'R':
                if(posX == 10)   // 10이면 그만 이동하기 (이미 오른쪽 끝에 위치함)
                {
                    break;
                }
                else
                {
                    posX++;
                    
                    if(pass[posX][posY][0] != 1)    // 처음 걸어본 길이라면
                    {
                        pass[posX][posY][0] = 1;
                        answer++;                    
                    }
                    
                    break;       
                }

        }

    }
    
    return answer;
}