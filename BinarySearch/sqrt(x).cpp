/* leetcode-69 */

class Solution
{
  public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;

        int l = 1, r = x;

        while (r - l > 1)
        {
            int mid = l + (r - l) / 2;
            int sqrtX = x / mid;

            if (mid == sqrtX)
                return mid;
            else if (mid > sqrtX)
                r = mid;
            else
                l = mid;
        }
        return l;
    }
};