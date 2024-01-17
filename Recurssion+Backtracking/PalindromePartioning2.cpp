class Solution {
public:
    bool isPalindrome(int s, int e, string str) {
        while (s <= e) {
            if (str[s] != str[e]) {
                return false;
            }
            s++;
            e--;
        }
        return true;
    }

    void helper(string s, int index, vector<vector<string>>& finalans, vector<string>& ans) {
        if (index == s.length()) {
            finalans.push_back(ans);
            return;
        }

        for (int i = index; i < s.length(); i++) {
            if (isPalindrome(index, i, s)) {
                string curr = s.substr(index, i - index + 1);
                ans.push_back(curr);
                helper(s, i + 1, finalans, ans);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> finalans;
        vector<string> ans;
        helper(s, 0, finalans, ans);
        return finalans;
    }
};
