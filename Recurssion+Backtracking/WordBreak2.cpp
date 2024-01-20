#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> solve(int idx, string s, unordered_set<string>& st, int n, string ans, vector<string>& returning) {

        if (idx == n) {
            returning.push_back(ans);
            return returning;
        }

        for (int l = 1; idx + l <= n; l++) {
            string temp = s.substr(idx, l);

            if (st.find(temp) != st.end()) {
                string newAns = ans.empty() ? temp : ans + " " + temp;
                returning = solve(idx + l, s, st, n, newAns, returning);
            }
        }

        return returning;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<string> result;

        return solve(0, s, st, n, "", result);
    }
};
