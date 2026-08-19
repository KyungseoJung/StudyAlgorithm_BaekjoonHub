#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int num1, int num2) {
    string answer = "";
    answer = my_string;
    
    char char1, char2;
    char1 = my_string[num1];
    char2 = my_string[num2];
    
    answer[num1] = char2;
    answer[num2] = char1;
    
    return answer;
}