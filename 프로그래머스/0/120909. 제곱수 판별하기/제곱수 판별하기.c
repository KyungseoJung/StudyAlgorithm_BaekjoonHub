#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    for(int i=1; i<=1000; i++)
    {
        if(i * i == n)
        {
            answer = 1;
            break;
        }
        else if(i * i > n)
        {
            answer = 2;
            break;
        }
    }
    return answer;
}