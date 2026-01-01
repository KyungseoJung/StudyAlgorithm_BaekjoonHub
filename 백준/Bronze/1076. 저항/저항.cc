#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // 색상 순서대로 배열 생성
    vector<string> colors = {
        "black", "brown", "red", "orange", "yellow", 
        "green", "blue", "violet", "grey", "white"
    };

    string c1, c2, c3;
    cin >> c1 >> c2 >> c3;

    int v1 = 0, v2 = 0, v3 = 0;

    // 각 색상의 인덱스(값) 찾기
    for (int i = 0; i < 10; i++) {
        if (c1 == colors[i]) v1 = i;
        if (c2 == colors[i]) v2 = i;
        if (c3 == colors[i]) v3 = i;
    }

    // 결과 계산: (첫 번째 값 * 10 + 두 번째 값) * 10^세 번째 값
    // 결과값이 크므로 long long 사용
    long long result = (v1 * 10 + v2);
    
    for (int i = 0; i < v3; i++) {
        result *= 10;
    }

    cout << result << endl;

    return 0;
}