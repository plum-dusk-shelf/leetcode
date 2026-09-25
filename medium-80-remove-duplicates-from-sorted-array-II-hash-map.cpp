/*
Runtime
O(n)
11ms
Beats
32.17%

Memory
O(n)
20.91MB
Beats
5.32%
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> u = {};

        int shift = 0;
        for (int i = 0; i < nums.size(); i++){
            if (u[nums[i]]>=2){
                shift++;
            }
            nums[i-shift] = nums[i];
            u[nums[i]]++;
        }
        return nums.size()-shift;
    }
};
