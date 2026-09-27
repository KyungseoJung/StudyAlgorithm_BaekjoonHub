#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    // *** 핵심 단서 ****
//         카펫 구조:
//     ┌─────────────┐
//     │ 갈 갈 갈 갈  │
//     │ 갈 노 노 갈  │
//     │ 갈 갈 갈 갈  │
//     └─────────────┘

//     전체 가로 = w, 세로 = h
//     노란색 = (w-2) × (h-2)
//     갈색 = 2w + 2h - 4

//     따라서:
//     ✓ brown = 2(w + h - 2)
//     ✓ sum = brown/2 + 2 = w + h
//     ✓ area = w × h
    
    
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