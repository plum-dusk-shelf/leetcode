/*
Runtime
0ms
Beats
100.00%

Memory
15.74MB
Beats
53.97%
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        std::next_permutation(nums.begin(), nums.end());
    }
};
