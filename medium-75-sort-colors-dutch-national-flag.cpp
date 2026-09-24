/*
Runtime
O(n)
0ms
Beats
100.00%

Memory
O(1)
11.88MB
Beats
11.31%
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, l = 0, r = nums.size() - 1;

        for (i; i <= r; i++){
            if (nums[i] == 0){
                swap(nums[i], nums[l]);
                l++;
            } else if (nums[i] == 2){
                swap(nums[i], nums[r]);
                r--;
                i--;
            }
        }
    }
};
