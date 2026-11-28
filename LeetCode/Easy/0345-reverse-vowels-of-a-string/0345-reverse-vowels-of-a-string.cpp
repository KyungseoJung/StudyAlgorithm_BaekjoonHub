class Solution {
public:
    string reverseVowels(string s) {
        
        // 모음을 일단 찾아서 vector에 저장하기 ---------------
        vector <char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector <char> findVowels;
        for(int i=0; i<s.length(); i++)
        {
            // 모음 확인
            for(int j=0; j<vowels.size(); j++)
            {
                if(tolower(s[i]) == vowels[j])
                {
                    findVowels.push_back(s[i]);

                    break;
                }
            }
        }


        // 문자열의 모음을 뒤집어서 넣기
        int ele = findVowels.size() -1 ;
        for(int i=0; i<s.length(); i++)
        {
            // 만약 특정 글자가 모음이라면
            for(int j=0; j<vowels.size(); j++)
            {
                if(tolower(s[i]) == vowels[j])
                {
                    s[i] = findVowels[ele];
                    ele--;

                    break;
                }
            }
        }

        return s;
    }
};