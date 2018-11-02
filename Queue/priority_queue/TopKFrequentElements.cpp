/* leetcode-347 */

#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        vector<int> ans;

        unordered_map<int, int> freq;
        for(const int& num : nums)
                ++freq[num];

        //扫描freq，维护出现频率最高的K个元素
        priority_queue< pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;//pair<频率，元素>
        for(auto iter = freq.begin(); iter != freq.end(); ++iter)
        {
            if(pq.size() < k)
                pq.push( make_pair(iter->second, iter->first) );
            else
                if(iter->second > pq.top().first)
                {
                    pq.pop();
                    pq.push( make_pair(iter->second, iter->first) );
                }
        }

        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

class Solution2
{
  public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        vector<int> ans;

        unordered_map<int, int> freq;
        for (const int &num : nums)
            ++freq[num];

        //扫描freq，维护出现频率最低的N-K个元素
        priority_queue< pair<int, int> > pq; //pair<频率，元素>
        for (auto iter = freq.begin(); iter != freq.end(); ++iter)
        {
            if (pq.size() < freq.size() - k)
                pq.push( make_pair(iter->second, iter->first) );
            else if (!pq.empty() && iter->second < pq.top().first)
            {
                ans.push_back(pq.top().second);
                pq.pop();
                pq.push( make_pair(iter->second, iter->first) );
            }
            else 
                ans.push_back(iter->first)
        }
        return ans;
    }
};