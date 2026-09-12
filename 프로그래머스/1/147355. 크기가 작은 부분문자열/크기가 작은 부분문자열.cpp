#include <string>   // substr을 위해 필요
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    string num;
    for(int i=0; i <= t.length() - p.length(); i++)
    {
        num = (t.substr(i, p.length()));  // 3자리만 string으로 뽑고, int로 변환해서 nums에 저장하기
        // 를 하려고 했으나, 굳이 int로 변환할 필요 없이 바로 p와 비교해도 될 듯
        // 어차피 숫자로도 큰 값은, string에서도 큰 값일 테니까
        if(num <= p)
        {
            answer++;
        }
    }
    return answer;
}