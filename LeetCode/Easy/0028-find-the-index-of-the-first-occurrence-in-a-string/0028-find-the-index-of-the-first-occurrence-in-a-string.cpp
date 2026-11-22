class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int index;
        bool different;
        for(int i=0; i<haystack.length(); i++)
        {
            if(haystack[i] == needle[0])
            {
                different = false;
                index = i;
                for(int j=0; j<needle.length(); j++)
                {
                    if(haystack[i+j] != needle[j])
                    {
                        different = true;
                        break;
                    }
                }
                if(different == false)
                {
                    return index;
                }
            }
        }

        return -1;
    }
};