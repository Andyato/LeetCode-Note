/* leetcode-20 */

#include<string>
#include<stack>

class Solution
{
public:
    bool isValid(string s)
    {
        if(s.size() & 1 == 1) return false;

        stack<char> st;

        for(const char& c : s)
        {
            if(c == '(' || c == '[' || c == '{')
                st.push(c);
            else
            {
                if(st.empty()) return false;

                switch (c)
                {
                    case ')':
                        if(st.top() != '(') 
                            return false;
                        st.pop();
                        break;
                    case ']':
                        if (st.top() != '[')
                            return false;
                        st.pop();
                        break;
                    case '}':
                        if (st.top() != '{')
                            return false;
                        st.pop();
                        break;
                }

            }
        }

        if(!st.empty())
            return false;

        return true;
    }
};