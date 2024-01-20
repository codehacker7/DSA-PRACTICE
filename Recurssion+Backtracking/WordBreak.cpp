#include <unordered_set>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:

    bool solve(int idx, string s, unordered_set<string>& st, int n, unordered_map<int, bool>& memo) {
        if (idx == n) return true;

        if (memo.find(idx) != memo.end()) return memo[idx];

        if (st.find(s.substr(idx)) != st.end()) {
            memo[idx] = true;
            return true;
        }

        for (int l = 1; l <= n; l++) {
            string temp = s.substr(idx, l);

            if (st.find(temp) != st.end() && solve(idx + l, s, st, n, memo)) {
                memo[idx] = true;
                return true;
            }
        }

        memo[idx] = false;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;

        int n = s.length();

        for (string word : wordDict) {
            st.insert(word);
        }

        unordered_map<int, bool> memo;

        return solve(0, s, st, n, memo);
    }
};
