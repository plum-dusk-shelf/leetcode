/*
Runtime
O(n)
1306ms
Beats
35.28%

Memory
O(n)
375.94MB
Beats
47.62%
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 11){
            return {};
        }
        unordered_set<string> seen, res;

        for (int i = 0; i < s.length() - 9; i++){
            string seq = s.substr(i, 10);
            if (seen.count(seq)){
                res.insert(seq);
            }
            seen.insert(seq);
        }
        return vector<string>(res.begin(), res.end());
    }
};
