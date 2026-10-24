#include <string>
#include <vector>

#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    // 1) 어떤 값을 최댓값으로 두고 시작하면 좋을까
    // citations.size()와 max(citations[i]) 중 더 작은 값
    // h가 아무리 커도, 두 값보다 클 수는 없으므로
    
    int start;
    int size = citations.size();
    int maxCitations;
    // 오름차순 정렬
    sort(citations.begin(), citations.end());
    maxCitations = citations[citations.size() - 1];
    
    start = (size > maxCitations)? maxCitations : size;
    
    
    // 2) h번 이상 인용된 논문의 개수 찾기
    // 정렬한다면, [0, 1, 3, 5, 6]
    // citations[ele] 번 이상 인용된 논문의 개수: citations.size() - ele
    // x번 이상 인용된 논문의 개수: citations 중 x 이상이면서 가장 작은 값을 찾고 index를 알아내서, citations.size() - 그index
        // ex) 4번 인용된 논문의 개수: 5 - 3(5의 index 번호) = 2
    
    
    int minEle = -1;
    int num;
    // 3) 위 규칙들을 이용해서 h번 이상 인용된 논문이 h편 이상일 때를 찾기 (최댓값으로)
    for(int i = start; i>0; i--)
    {
        // citations 중 i 이상이면서 가장 작은 값 찾기
        for(int ele = citations.size()-1; ele >=0 ; ele--)
        {
            if(citations[ele] < i)
            {
                minEle = ele +1;
                break;
            }
        }
        
        // i번 이상 인용된 논문의 개수 -> h 찾기.
        if(minEle == -1)    // 모두 i번 이상 인용된 논문만 있을 때에는 -1로 나옴
        {
            num = citations.size();
        }
        else
        {
            num = citations.size() - minEle;
        }
        
        // i번 이상 인용된 논문의 개수가 i편 이상이면 됨
        // 즉, num이 i이상이면 찾기 완료! for문에서 나오기
        if(num >= i)
        {
            answer = i;
            break;
        }
        
    }
    return answer;
}