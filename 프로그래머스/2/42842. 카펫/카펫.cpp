#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // brown과 yellow의 합은 넓이
    // (brown / 2 + 2)은 가로 + 세로 길이 합
    
    long long int area = brown + yellow;  // 넓이 구하기
    long long int sum = brown / 2 + 2; // 가로 + 세로 길이 합부터 구하자
    long long int row, col;
    for(int col = 1; col < sum; col++)
    {
        row = sum - col;
        if(row * col == area)
        {
            answer.push_back(row);
            answer.push_back(col);
            break;
        }
    }
    return answer;
}