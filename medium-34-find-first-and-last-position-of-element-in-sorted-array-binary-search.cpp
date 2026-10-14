/*
Runtime
O(log n)
0ms
Beats
100.00%

Memory
O(n)
17.65MB
Beats
16.91%
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }

        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int c = l + (r - l) / 2;

            if (nums[c] < target) {
                l = c + 1;
            } else {
                r = c;
            }
        }

        if (nums[l] != target){
            return {-1, -1};
        }

        int start = l;

        r = nums.size() - 1;

        while (l < r) {
            int c = l + (r - l + 1) / 2;

            if (nums[c] <= target) {
                l = c;
            } else {
                r = c - 1;
            }
        }

        return {start, l};
    }
};
