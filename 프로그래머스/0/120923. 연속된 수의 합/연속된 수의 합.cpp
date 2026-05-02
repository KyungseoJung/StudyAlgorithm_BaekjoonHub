#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    // 원리가 있음
    // num이 홀수일 때 -----------
    // Ex) num = 3 (홀수)라면 -> N-1, N, N+1 같은 형태로 대칭 더해질 것이고, 결국엔 3 * N = total이 되어야 함 (즉, toal과 num이 주어진다면, 가운데 숫자(N)가 정해져있다는 것을 알 수 있음)
    // N = total / num
    int N;
    if(num %2 == 1)
    {
        N = total / num;
        for(int i= - num/2; i <= num/2; i++)
        {
            answer.push_back(N+i);
        }
    }
    
    // num이 짝수일 때 -----------
    // 1 2 3 4 5 6 // num = 6, total: 21 // 가운데 2개 숫자의 합이 7인 것을 찾으면 됨
    // 가운데 2개 숫자의 합이 [total / (num/2)] 인 것을 찾으면 됨 
    // 찾으려는 숫자 2개의 합을 findNum이라 한다면, findNum * (num/2) = total이 됨
    // (So, total은 0 이상이므로 findNum도 일단은 0 이상임)
    if(num %2 == 0)
    {
        int findNum = total / (num/2);
        
        int ele = 0;    // -1 + 0 = 음수이므로, ele 는 0이상부터 찾으면 됨
        while(true)
        {
            if((ele) + (ele + 1) == findNum)
            {
                break;
            }
            else
            {
                ele ++;
            }
        }
        
        
        int start = -(num/2-1); // 메모: -1
        int end = num + start - 1;  // 메모: num = 4   end = 2  // end - start + 1 = num
        for(int i = start; i <= end; i++)
        {
            answer.push_back(ele+i);
        }
        
    }
    
    return answer;
}