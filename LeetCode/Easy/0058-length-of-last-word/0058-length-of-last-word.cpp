class Solution {
public:
    int lengthOfLastWord(string s) {
        
        bool start = false;
        int count = 0;
        for(int i=s.length()-1; i>=0; i--)
        {
            if( (start == false) && (s[i] != ' ') )
            {
                start = true;
            }

            if( (start == true) && (s[i] != ' ') )
            {
                count ++;
            }
            else if( (start == true) && (s[i] == ' ') )
            {
                break;  // for문 통과
            }
        }

        return count;
    }
};