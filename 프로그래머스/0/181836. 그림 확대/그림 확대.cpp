#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    string ele;
    for(int i=0; i<picture.size(); i++)
    {
        ele = "";   // string 초기화하기
        for(int j=0; j<picture[i].length(); j++)
        {
            for(int repeat = 0; repeat<k; repeat++)
            {
                ele.push_back(picture[i][j]);
            }
        }
        
        // 위에서 k번 반복한 string을 answer에 k번 추가해주면 됨.
        for(int j=0; j<k; j++)
        {
            answer.push_back(ele);            
        }
        
    }
    
    return answer;
}