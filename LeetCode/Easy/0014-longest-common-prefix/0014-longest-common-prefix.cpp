class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int minIndex = 999;    // 동일한 접두사 길이까지의 index번호를 저장하기
        // strs의 i번째 단어와 i+1번째 단어를 비교하면서 어디까지 같은지 비교하면 됨.
            // 그 다음에는 i+1와 i+2번째 단어를 비교
        

        // 1) 몇 번째 index까지 동일한 접두어인지 찾기
        int len1, len2;
        int minLen;
        int index;
        if(strs.size() == 1)    // 단어가 딱 1개만 있을 때
        {   
            minIndex = strs[0].length() - 1;
        }   
        else
        {
            for(int i=0; i<strs.size()-1; i++)
                {
                    len1 = strs[i].length();
                    len2 = strs[i+1].length();
                    minLen = (len1 > len2)? len2: len1;

                    index = minLen -1;
                    for(int j=0; j<minLen; j++)
                    {
                        if(strs[i][j] != strs[i+1][j])
                        {
                            index = j-1;
                            break;
                        }
                    }

                    if(index < minIndex)
                    {
                        minIndex = index;
                    }
                }

        }
 
        // 최소 index에 대해서 공통 접두사 얻어내기
        string answer = "";
        if(minIndex >= 0)
        {
            for(int i=0; i <= minIndex; i++)
            {
                answer = answer +strs[0][i];
            }
        }
        else
        {
            answer = "";
        }

        return answer;
    }
};