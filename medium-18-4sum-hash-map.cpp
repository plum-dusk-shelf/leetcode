/*
Runtime
O(n^3)
711ms
Beats
5.01%

Memory
O(n+m)
113.10MB
Beats
5.03%
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> u = {};
        for (auto num : nums) {
            u[num]++;
        }

        vector<vector<int>> res = {};

        for (int i = 0; i + 3 < nums.size(); i++) {
            u[nums[i]]--;
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            for (int j = i + 1; j + 2 < nums.size(); j++) {
                u[nums[j]]--;
                if (j > i + 1 && nums[j - 1] == nums[j])
                    continue;
                for (int k = j + 1; k + 1 < nums.size(); k++) {
                    u[nums[k]]--;
                    if (k > j + 1 && nums[k - 1] == nums[k])
                        continue;

                    long long fourth = static_cast<long long>(target) - nums[i] - nums[j] - nums[k];

                    if (fourth < INT_MIN || fourth > INT_MAX) continue;
                    
                    int fourth_int = static_cast<int>(fourth);
                    if (u[fourth] > 0 && fourth_int >= nums[k]) {
                        res.push_back({nums[i], nums[j], nums[k], fourth_int});
                    }
                }

                for (int k = j + 1; k + 1 < nums.size(); k++) {
                    u[nums[k]]++;
                }
            }
            for (int j = i + 1; j + 2 < nums.size(); j++) {
                u[nums[j]]++;
            }

        }
        return res;
    }
};
