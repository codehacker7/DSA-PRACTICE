class Solution {
public:
    void backtrack(vector<vector<int>>& permutations, vector<int>& nums, int start) {
        if (start == nums.size()) {
            permutations.push_back(nums);
            return;
        }
        unordered_set<int> s;
        for (int i = start; i < nums.size(); ++i) {
            if (s.find(nums[i]) != s.end()) continue;
            s.insert(nums[i]);
            swap(nums[start], nums[i]);
            backtrack(permutations, nums, start + 1);
            swap(nums[start], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> permutations;
        backtrack(permutations, nums, 0);
        return permutations;
    }
};
