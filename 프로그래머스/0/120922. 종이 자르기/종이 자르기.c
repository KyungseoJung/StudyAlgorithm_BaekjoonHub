#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int M, int N) {
    int answer = 0;
    int min = (M>N)? N : M;
    int max = (M>N)? M : N;
    
    // 무조건 작은 부분을 먼저 일자로 자르는 게 유리
    answer += (min - 1);
    answer += (max-1)*min;
    
    return answer;
}