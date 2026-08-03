#include <string>
#include <vector>

#include <iostream>
using namespace std;

string solution(int age) {
    string answer = "";
    int num;
    // cout << (int) 'a';
    
    while(age >= 1)
    {
        num = age % 10;
        answer = char(num + 97) + answer;
        age = age / 10;
    }
    return answer;
}