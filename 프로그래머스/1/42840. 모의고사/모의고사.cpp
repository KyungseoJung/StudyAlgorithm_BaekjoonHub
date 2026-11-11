#include <string>
#include <vector>

#include <algorithm>    // sort 함수
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector <int> stu1 = {1, 2, 3, 4, 5};
    vector <int> stu2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector <int> stu3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    // 수포자 1의 맞힌 개수 세기
    int stu1Answer;
    int sum1 = 0;
    for(int i=0; i<answers.size(); i++)
    {
        if(i >= stu1.size())
        {
            stu1Answer = stu1[i % stu1.size()];
        }
        else
        {
            stu1Answer = stu1[i];
        }
        if(answers[i] == stu1Answer)
        {
            sum1 ++;
        }
    }
    

    // 수포자 2의 맞힌 개수 세기
    int stu2Answer;
    int sum2 = 0;
    for(int i=0; i<answers.size(); i++)
    {
        if(i >= stu2.size())
        {
            stu2Answer = stu2[i % stu2.size()];
        }
        else
        {
            stu2Answer = stu2[i];
        }
        if(answers[i] == stu2Answer)
        {
            sum2 ++;
        }
    }
    
    
    // 수포자 3의 맞힌 개수 세기
    int stu3Answer;
    int sum3 = 0;
    for(int i=0; i<answers.size(); i++)
    {
        if(i >= stu3.size())
        {
            stu3Answer = stu3[i % stu3.size()];
        }
        else
        {
            stu3Answer = stu3[i];
        }
        if(answers[i] == stu3Answer)
        {
            sum3 ++;
        }
    }

    
    // cout << sum1 << "\n";
    // cout << sum2 << "\n";
    // cout << sum3 << "\n";


    // 가장 많이 맞힌 사람 세기
    vector <int> sums;
    sums.push_back(sum1);
    sums.push_back(sum2);
    sums.push_back(sum3);

    int max = 0;
    int maxEle;
    
    for(int i=0; i<sums.size(); i++)
    {
        if(sums[i] > max)   // 새로운 최댓값이 나타나면 이전 원소들 모두 제거하고, 추가해주기
        {
            answer.clear();
            max = sums[i];
            maxEle = i;
            answer.push_back(maxEle+1);
        }
        else if(sums[i] == max) // 최댓값과 같은 값이면 추가해주기
        {
            answer.push_back(i+1);
        }
    }
    
    // 오름차순 정렬
    sort(answer.begin(), answer.end());
    
    
    return answer;
}