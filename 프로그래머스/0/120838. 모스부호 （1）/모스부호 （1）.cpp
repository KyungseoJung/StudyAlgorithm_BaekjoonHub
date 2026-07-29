#include <string>
#include <vector>

#include <sstream>  // stringstream 사용하기 위함
#include <iostream>
using namespace std;

string solution(string letter) {
    string answer = "";
    
    // morse 정의
    vector <string> morse;
    morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    char alphabet = 'a';
    
    // letter 해석하기
    stringstream ss(letter);
    string word;
    while(ss >> word)
    {
        for(int i=0; i<morse.size(); i++)
        {
            if(morse[i] == word)
            {
                answer += char(alphabet + i);
            }
        }
        
    }
    
    return answer;
}