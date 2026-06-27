#include <string>
#include <vector>

#include <sstream>

using namespace std;

int solution(string s) {
    int answer = 0;
    stringstream ss(s);
    string word;
    
    int preventNum = 0;
    int sum = 0;
    while(ss >> word)
    {
        if(word == "Z")
        {
            sum -= preventNum;
        }
        else
        {
            sum += (stoi)(word);
            preventNum = (stoi)(word);
        }
    }
    
    answer = sum;
    return answer;
}