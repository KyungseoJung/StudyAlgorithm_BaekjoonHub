#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int answer = 0;
    
    int ant1 = 0;
    int ant2 = 0;
    int ant3 = 0;   // 장군개미, 병정개미, 일개미의 숫자
    // 장군개미 몇마리 데려갈까
    if(hp >= 5)
    {
        ant1 = hp /5 ;
        hp = hp % 5;
    }
    
    // 병정개미 몇마리 데려갈까
    if(hp >= 3)
    {
        ant2 = hp / 3;
        hp = hp % 3;
    }
    
    // 일개미 몇마리 데려갈까
    if(hp >= 1)
    {
        // ant3 = hp /1 ;
        // hp = hp % 1;
        
        ant3 = hp;
    }
    
    answer = ant1 + ant2 + ant3;
    return answer;
}