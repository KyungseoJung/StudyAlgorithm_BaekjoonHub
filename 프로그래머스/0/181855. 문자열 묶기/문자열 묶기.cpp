#include <string>
#include <vector>

using namespace std;

int solution(vector<string> strArr) {
    int answer = 0;
    vector<int> countNum(31, 0);   // 1부터 30까지의 크기를 가진 문자열들이 몇 개 있는지 카운팅하는 목적 - 처음엔 모두 0부터 시작
    int size;
    for(int i=0; i<strArr.size(); i++)
    {
        size = strArr[i].length();
        countNum[size]++;
    }
    
    // 어떤 길이의 그룹이 가장 많은지 찾기
    int ele = 1;
    for(int i=1; i<countNum.size(); i++)
    {
        if(countNum[i] > countNum[ele])  // 가장 개수가 많은 그룹을 찾고
        {
            ele = i; // 가장 개수가 많은 그룹의, 길이를 저장하기
        }
    }
    
    answer = countNum[ele];  // 그룹의 길이를 return 하는 게 아니라, 그 그룹의 크기(멤버 개수)를 return 하는 것
    return answer;
}