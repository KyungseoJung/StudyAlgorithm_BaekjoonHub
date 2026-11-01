#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    // *** 에라토스테네스의 체 ***
    // 특정 숫자가 소수인지 아닌지 판별하는 vector 만들기
    long long int endNum = 1000001;
    vector <bool> primeNumber(endNum, true);
    primeNumber[0] = false;
    primeNumber[1] = false;
    
    for(int i=2; i*i<=endNum; i++)
    {
        if(primeNumber[i] == true)
        {
            for(int j= i*i; j<=endNum; j+= i)   // 제곱수 이전의 배수들은 이미 이전 수에서 false 처리 되었을 것이기 때문에, 제곱수부터 살펴보면 됨
            {
                primeNumber[j] = false;
            }
        }
    }
    
    
    for(int i=2; i<= n; i++)
    {
        if(primeNumber[i] == true)
        {
            answer++;
        }
    }
    return answer;
}