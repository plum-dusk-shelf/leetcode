/*
Runtime
O(n^2)
2ms
Beats
69.33%

Memory
O(n)
8.62MB
Beats92.69%
*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        std::function<int(int, int)> dfs = [&](int l, int r) -> int {
            int cnt[26] = {0};
            int ans = 0;

            for (int i = l; i <= r; ++i){
                ++cnt[s[i]-'a'];
            }

            char split = 0;
            for (int i = 0; i < 26; ++i){
                if (cnt[i] > 0 && cnt[i] < k){
                    split = i + 'a';
                    break;
                }
            }

            if (split == 0){
                return r - l + 1;
            }

            int i = l;
            while (i <= r){
                while (i <= r && s[i] == split){
                    ++i;
                }

                if (i > r){
                    break;
                }

                int j = i;
                while (j <= r && s[j] !=  split){
                    ++j;
                }

                ans = max(ans, dfs(i, j-1));
                i = j;
            }
            return ans;
        };

        return dfs(0, s.length()-1);
    }
};
