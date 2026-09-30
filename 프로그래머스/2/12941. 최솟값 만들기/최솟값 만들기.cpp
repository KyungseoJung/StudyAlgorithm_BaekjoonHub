#include <iostream>
#include<vector>

#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    // A와 B 원소 -> 짝을 짓는데 -> 가장 작은 값이 나오게 하려면: n번째로 작은 값은 n번째로 큰 값과 곱해져야 함
    // 그래야 밸런스가 맞아서, 더했을 때 최소값이 나옴
    
    // 정렬
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int size = A.size();
    for(int i=0; i< size; i++)
    {
        answer += (A[i] * B[size - 1 -i]);    
    }
    

    return answer;
}