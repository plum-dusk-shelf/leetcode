/*
Runtime
O(n)
0ms
Beats
100.00%

Memory
O(1)
10.93MB
Beats
40.75%
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int r = 0, l = 0, len = 0, maxFreq = 0;

        int freqs[26] = {};

        for (r; r < s.size(); r++) {
            freqs[s[r] - 'A']++;

            maxFreq = max(maxFreq, freqs[s[r] - 'A']);

            while (r - l + 1 - maxFreq > k) {
                freqs[s[l] - 'A']--;
                l++;
            }

            len = max(len, r - l + 1);
        }
        return len;
    }
};
