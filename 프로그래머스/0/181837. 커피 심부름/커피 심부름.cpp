#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order) {
    int answer = 0;
    bool americano = false;
    vector <string> price1 = {"iceamericano", "americanoice", "hotamericano", "americanohot", "americano", "anything"};
    vector <string> price2= {"icecafelatte", "cafelatteice", "hotcafelatte", "cafelattehot", "cafelatte"};
    
    for(int i=0; i<order.size(); i++)
    {
        americano = false;
        for(int j=0; j<price1.size(); j++)
        {
            if(order[i] == price1[j])
            {
                americano = true;
                break;
            }
        }
        if(americano == true) // 아메리카노 4,500원
        {
            answer += 4500;
        }
        else    // 카페라떼 5,000원
        {
            answer += 5000;
        }
        
    }
    
    
    return answer;
}