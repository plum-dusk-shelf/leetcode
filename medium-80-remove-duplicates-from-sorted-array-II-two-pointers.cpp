/*
Runtime
O(n)
4ms
Beats
84.01%

Memory
O(1)
19.63MB
Beats
23.89%
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0, fast = 0;
        for (fast; fast < nums.size(); fast++){
            if (slow < 2 || nums[fast] != nums[slow-2]){
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};
