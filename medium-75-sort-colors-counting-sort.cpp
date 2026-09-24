/*
Runtime
O(n)
0ms
Beats
100.00%

Memory
O(1)
11.69MB
Beats
49.27%
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(4);

        for (int num: nums){
            count[num]++;
        }

        for (int i = 0; i < nums.size(); i++){
            if (i < count[0]){
                nums[i] = 0;
            }
            else if (i < count[0] + count [1]){
                nums[i] = 1;
            }
            else {
                nums[i] = 2;
            }
        }
    }
};
