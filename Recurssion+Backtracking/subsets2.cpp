class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        sort(nums.begin(), nums.end());  // Sort the input to handle duplicates

        generateSubsets(nums, 0, currentSubset, result);

        return result;
    }

private:
    void generateSubsets(const vector<int>& nums, int index, vector<int>& currentSubset, vector<vector<int>>& result) {
        result.push_back(currentSubset);

        for (int i = index; i < nums.size(); i++) {
            // Skip duplicates
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            currentSubset.push_back(nums[i]);
            generateSubsets(nums, i + 1, currentSubset, result);
            currentSubset.pop_back();
        }
    }
};