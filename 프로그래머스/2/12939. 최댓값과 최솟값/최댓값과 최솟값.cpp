#include <string>
#include <vector>

#include <algorithm>    // sort 함수 사용하기 위함
#include <sstream>      // stringstream 사용하기 위함
// ****** stoi()의 추가 기능 ******
// stoi("-5")      // -5
// stoi("+10")     // 10
// stoi("  -20")   // -20 (앞 공백 무시)
// stoi("100abc")  // 100 (뒤의 문자 무시, 숫자만 변환)
// stoi("0xFF")    // 오류! (16진수는 처리 안함)

#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    vector <int> nums;
    int num;
    
    stringstream ss(s);
    string word;
    while(ss >> word)
    {
        // -가 붙은 string을 stoi를 이용해서, 숫자로 바꿀 때: 바로 숫자로 바꿔주나
        num = (stoi)(word);
        nums.push_back(num);
    }

    
    // nums 출력
    
    sort(nums.begin(), nums.end());

    // cout << to_string(nums[0]) << " " << nums[nums.size() -1];
    
    answer += to_string(nums[0]);   // 최소값 넣고
    answer += " " ;                 // 공백 추가
    answer += to_string(nums[nums.size() -1]);  // 최대값 넣기
    return answer;
}