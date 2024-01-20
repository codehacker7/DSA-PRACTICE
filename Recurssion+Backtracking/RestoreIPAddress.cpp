#include <vector>
#include <string>

class Solution {
public:
    bool isValid(string s){
        if(s[0] == '0'){
            return false;
        }
        int value = stoi(s);

        return value <= 255;
    }

    void solve(string s, int idx, int parts, string curr, vector<string> &result, int n){
        if(idx == n && parts == 4){
            curr.pop_back();
            result.push_back(curr);
            return;
        }
        if(idx + 1 <= s.length())
            solve(s, idx+1, parts+1, curr + s.substr(idx,1) + ".", result, n);

        if(idx + 2 <= s.length() && isValid(s.substr(idx,2)))
            solve(s, idx+2, parts+1, curr + s.substr(idx,2) + ".", result, n);

        if(idx + 3 <= s.length() && isValid(s.substr(idx,3)))
            solve(s, idx+3, parts+1, curr + s.substr(idx,3) + ".", result, n);
    }

    vector<string> restoreIpAddresses(string s) {
        int n = s.length();

        if(n > 12) return {};

        vector<string> result;
        int parts = 0;
        string curr = "";
        solve(s, 0, parts, curr, result, n);
        return result;
    }
};
