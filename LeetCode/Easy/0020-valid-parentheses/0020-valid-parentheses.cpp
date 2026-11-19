class Solution {
public:
    bool isValid(string s) {
        bool answer = true;
        stack <char> st;
        
        for(int i=0; i<s.length(); i++)
        {
            switch(s[i])
            {
                case '(':
                case '{':
                case '[':
                    st.push(s[i]);
                break;

                case ')':
                    if((!st.empty()) && (st.top() == '('))
                    {
                        st.pop();
                    }
                    else
                    {
                        answer = false;
                    }
                    break;
                case '}':
                    if((!st.empty()) && (st.top() == '{'))
                    {
                        st.pop();
                    }
                    else
                    {
                        answer = false;
                    }
                    break;

                case ']':
                    if((!st.empty()) && (st.top() == '['))
                    {
                        st.pop();
                    }
                    else
                    {
                        answer = false;
                    }
                    break;
            }
            
            if(answer == false)
            {
                break;
            }
        }

        if(!st.empty())
        {
            answer = false;
        }

        return answer;
    }

};