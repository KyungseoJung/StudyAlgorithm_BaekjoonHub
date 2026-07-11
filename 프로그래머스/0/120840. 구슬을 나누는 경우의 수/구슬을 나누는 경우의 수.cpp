#include <string>
#include <vector>

using namespace std;

// long long int fact(int num)
// {
//     long long int result = 1;
//     for(int i=1; i<=num; i++)
//     {
//         result = result * i;        
//     }
    
//     return num;
// } 

int solution(int balls, int share) {
     long long int answer = 0;
    // 조합 문제 n_C_r
    // 1) r과 n-r 중 큰 값/ 작은 값을 골라낸다
    // 2-1) 만약 r이 더 크다면 분자에 n, n-1, ... r+1까지 곱해주기  // 분모에는 1, 2, ... n-r까지 곱해주기
    // 2-2) 만약 n-r이 더 크다면 분모에 n, n-1, ... n-r+1까지 곱해주기  // 분모에는 1, 2, ... r까지 곱해주기
    // 3) 유심히 보면, 결국 분모와 분자에 곱해주는 숫자의 개수가 동일함. (2-1: n-r개, 2-2: r개)
        // 분자의 범위는 확실히 알고 있고, 분모의 범위도 알 수 있음 (개수가 동일하기 때문에)
        // 따라서 factorial 계산을 하지 않고 그냥 for문으로 바로 한꺼번데 계산해줄 수 있음.
    
    // balls_C_share = (balls!) / {(share)!(balls-share)!}
    int min = (share > (balls-share))? (balls-share) : share;
    int max = (share > (balls-share))? share : (balls-share);

    answer = 1;
    int j = 1;
    for(int i = balls; i> max; i--)
    {
        answer = answer * i;
        answer = answer / j;
        j++;
    }
        
    // if(balls == share)  // 두 값이 동일할 때에도 for문을 한번은 탈 수 있으니까(?) => 그런 경우는 없음. 애초에 for문이 실행되지 않음.
    // {
    //     answer = 1;
    // }
    return answer;
}

