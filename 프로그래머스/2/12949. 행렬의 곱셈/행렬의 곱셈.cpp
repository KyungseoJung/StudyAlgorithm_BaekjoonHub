#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    // 3행 2열 행렬 x 2행 2열 행렬 = 3행 2열 행렬
    // a행 b열 x c행 d열 = a행 d열 (이때 b = c 여야 곱셈이 가능함.)
    int a = arr1.size();
    int b = arr1[0].size();
    int c = arr2.size();
    int d = arr2[0].size();
    answer.assign(a, vector <int> (d));    // 크기 지정
    
    // answer의 i행 j열의 값은 arr1의 i행과 arr2의 j열 값들의 곱과 같음
    int sum;
    for(int i=0; i<answer.size(); i++)
    {
        for(int j=0; j<answer[0].size(); j++)
        {
            sum = 0;
            for(int ele = 0; ele < b; ele++)    // arr1의 i행과 arr2의 j열의 값들을 짝 지어서 곱해주기 
            {
                sum += (arr1[i][ele] * arr2[ele][j]);
            }
            
            answer[i][j] = sum;
        }
    }
                  
    return answer;
}