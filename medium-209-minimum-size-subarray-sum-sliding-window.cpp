/*
Runtime
O(n)
3ms
Beats
15.79%

Memory
O(1)
41.93MB
Beats
40.71%
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX, sum = 0;
        int slow = 0, fast = 0;

        for (fast; fast < nums.size(); fast++){
            sum += nums[fast];
            while (sum >= target){
                sum -= nums[slow];
                len = min(len, fast-slow+1);
                slow++;
            }
        }

        return len == INT_MAX ? 0 : len;    
        }
};
