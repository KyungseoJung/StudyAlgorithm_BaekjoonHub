#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector <int> nums;  // 약수 저장하는 vector
    
    for(int i=1; i*i<= n; i++)
    {
        if(n % i == 0)
        {
            answer += i;
            if(i*i != n)
            {
                answer += (n/i);
            }
        }
    }
    return answer;
}