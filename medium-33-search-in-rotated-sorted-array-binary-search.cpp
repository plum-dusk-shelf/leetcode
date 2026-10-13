/*
Runtime
O(log n)
0ms
Beats
100.00%

Memory
O(1)
15.18MB
Beats
70.67%
*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;

        while (l < r) {
            int c = (r + l) /2;

            if (nums[c] < nums[r]){
                r = c   ;
            }
            else {
                l = c + 1;
            }
        }

        int pivot = r;

        l = 0, r = pivot - 1;        
        while (l <= r) {
            int c = (r + l) / 2;
            if (nums[c] == target){
                return c;
            } else if (target < nums[c]){
                r = c - 1;
            } else if (target > nums[c]){
                l = c + 1;
            }
        }

        l = pivot, r = nums.size()-1;        
        while (l <= r) {
            int c = (r + l) / 2;
            if (nums[c] == target){
                return c;
            } else if (target < nums[c]){
                r = c - 1;
            } else if (target > nums[c]){
                l = c + 1;
            }
        }

        return -1;
    }
};
