/* leetcode-454 */
//
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution //时间空间 O(n*n)
{
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
    {
        int ans = 0;
        unordered_map<int, int> CD;
        for(int k = 0; k < C.size(); ++k)
            for(int l = 0; l < D.size(); ++l)
                ++CD[C[k] + D[l]];

        for(int i = 0; i < A.size(); ++i)
            for(int j = 0; j < B.size(); ++j)
            {
                int counts = CD[0 - A[i] - B[j]];
                if (counts)
                    ans += counts;
            }
        return ans;
    }
};