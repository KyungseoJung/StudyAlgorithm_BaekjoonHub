class Solution {
public:
    bool wordPattern(string pattern, string s) {

        bool answer = true;
        // string의 단어들을 담아두기 --------------
        string word;
        stringstream ss(s);
        vector <string> ssWords;
        while(ss >> word)
        {
            ssWords.push_back(word);
        }

        // pattern의 길이와 s의 단어 개수가 다른지 먼저!!! 확인하기 --------------------
        if(pattern.length() != ssWords.size())
        {
            answer = false;
            return answer;
        }

        vector <string> words (26, ""); // 0(a)부터 26(z)까지 알파벳에 각각 대응되는 단어 담기 --------------------

        int ele;
        for(int i=0; i<pattern.length(); i++)
        {
            ele = (int)(pattern[i] - 'a');
            if(words[ele] == "")
            {
                words[ele] = ssWords[i];
            }
            else
            {
                if(words[ele] != ssWords[i])
                {
                    answer = false;
                }
            }
        } 

        // s의 각 고유한 단어가 pattern의 정확히 하나의 문자에 매핑되는지도 확인하기 --------------------
        for(int i=0; i<words.size(); i++)
        {
            for(int j=i+1; j<words.size(); j++)
            {
                if((words[i] == words[j]) && (words[i] != "") )
                {
                    answer = false;
                    break;
                }
            }
        }



        return answer;
        
    }
};