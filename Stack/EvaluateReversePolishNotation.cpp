/* leetcode-150 */

#include<string>
#include<vector>
#include<stack>

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> nums;
        for(const string& s : tokens)
        {
            if(s == "+" || s == "-" || s == "*" || s == "/")
            {
                int a = nums.top(); nums.pop();
                int b = nums.top(); nums.pop();
            
                if(s == "+")
                    nums.push(b+a);
                else if(s == "-")
                    nums.push(b-a);
                else if(s == "*")
                    nums.push(b*a);
                else 
                    nums.push(b/a);
            }        
            else 
                nums.push(std::stoi(s));
        }
        return nums.top();
    }
};