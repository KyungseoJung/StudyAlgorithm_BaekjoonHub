#include <string>
#include <vector>

#include <algorithm>    // sort 함수 사용하기 위함
#include <sstream>      // stringstream 사용하기 위함

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