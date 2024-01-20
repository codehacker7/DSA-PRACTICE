class Solution {
private:
    void help(int i, int k, int target, int n, vector<int> &subSet, vector<vector<int>> &ans) {
        if (k == 0) {
            if (target == 0) {
                ans.push_back(subSet);
            }
            return;
        }

        if (i == 10) {
            return;
        }

        if (i <= target) {
            subSet.push_back(i);
            help(i + 1, k - 1, target - i, n, subSet, ans);
            subSet.pop_back();  // Backtrack: remove the last element
        }

        help(i + 1, k, target, n, subSet, ans);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subSet;
        vector<vector<int>> ans;
        help(1, k, n, n, subSet, ans);
        return ans;
    }
};
