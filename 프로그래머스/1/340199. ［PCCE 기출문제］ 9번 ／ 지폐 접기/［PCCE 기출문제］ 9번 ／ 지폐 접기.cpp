#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int walletMin, walletMax;
    walletMin = (wallet[0] > wallet[1])? wallet[1] : wallet[0];
    walletMax = (wallet[0] > wallet[1])? wallet[0] : wallet[1];
    
    int min, max;
    int maxEle; // max에 해당하는 ele를 저장하기
    while(true)
    {
        // 일단 지갑에 들어가는지 확인하기
        if(bill[0] > bill[1])
        {
            min = bill[1];
            max = bill[0];
            maxEle = 0;
        }
        else
        {
            min = bill[0];
            max = bill[1];
            maxEle = 1;
        }

        if((walletMin < min) || (walletMax < max))
        {
            bill[maxEle] = bill[maxEle] / 2;
            answer += 1;
        }
        else
        {
            // while문 통과하기
            break;
        }
        
    
    }
    
    return answer;
}