#include <string>
#include <vector>
#include <iostream>
// #include <cctype>   // tolower 사용 
using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    answer.resize(52, 0);
    // cout << (int)('A') << "\n";  // 65 출력
    // cout << (int)('Z') << "\n";  // 90 출력
    // cout << (int)('a') << "\n";  // 97 출력
    // cout << (int)('z') << "\n";  // 122 출력
    // [0]~[25]까지 'A'~'Z'
    // [26]~[51]까지 'a'~'z'
    char alphabet;
    for(int i=0; i<my_string.length(); i++)
    {
        alphabet = my_string[i];
        if(islower(alphabet))
        {
            answer[alphabet - 71]++;
        }
        else
        {
            answer[alphabet - 65]++;
            
        }

    }
    return answer;
}