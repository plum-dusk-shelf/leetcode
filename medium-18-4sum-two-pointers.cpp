/*
   Runtime
   O(n^3)
   17ms
   Beats
   85.73%

   Memory
   O(m)
   17.51MB
   Beats
   26.55%
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res = {};

        for (int i = 0; i + 3 < nums.size(); i++) {
            if (i>0 && nums[i-1] == nums[i]) continue;
            for (int j = i+1; j + 2 < nums.size(); j++) {
                if (j>i+1 && nums[j-1] == nums[j]) continue;

                int k = j + 1, h = nums.size() - 1;

                while (k < h) {
                    long long sum = (long long) nums[i] + nums[j] + nums[k] + nums[h];
                    if (sum > target) {
                        h--;
                    } else if (sum < target) {
                        k++;
                    } else {
                        res.push_back({nums[i], nums[j], nums[k], nums[h]});
                        h--; k++;
                        while (k<h && nums[k] == nums[k-1]) k++;
                        while (k<h && nums[h] == nums[h+1]) h--;
                    }
                }
            }
        }

        return res;
    }
};
