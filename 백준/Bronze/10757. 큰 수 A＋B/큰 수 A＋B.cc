#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 1. 숫자를 문자열로 입력받음
    string a, b;
    cin >> a >> b;

    string result = "";
    int i = a.length() - 1; // A의 끝 지점
    int j = b.length() - 1; // B의 끝 지점
    int carry = 0;          // 올림수

    // 2. 뒤에서부터 한 자리씩 더하기
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0'; // 문자를 숫자로 변환
        if (j >= 0) sum += b[j--] - '0';
        
        carry = sum / 10;        // 다음 자리로 넘길 값
        result += (sum % 10) + '0'; // 현재 자리 결과값 문자열 추가
    }

    // 3. 거꾸로 저장된 문자열을 뒤집어서 출력
    reverse(result.begin(), result.end());
    cout << result << endl;

    return 0;
}
