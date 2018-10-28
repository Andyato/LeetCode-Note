/* leetcode-71 */

#include<stack>
#include<string>
#include<sstream>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> st;
        string str, res;
        istringstream ss(path);
        
        while( getline(ss, str, '/') )
        {
            if(str == "" || str == ".")
            {
                continue;
            }
            else if(str == "..")
            {
                if(!st.empty()) st.pop();
            }
            else
            { 
                st.push(str);
            }
        }

        if(st.empty())
            return "/";
        
        while(!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }
        return res;
    }
};