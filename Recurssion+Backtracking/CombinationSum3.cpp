class Solution {
public:

    void findAllCombinations(vector<vector<int>>& finalans, unordered_map<int,bool>& visited, int start, vector<int>& temp, int k, int sum) {
        if (k == 0 && sum == 0) {
            finalans.push_back(temp);
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (visited[i]) continue;
            if (i > sum) break;

            visited[i] = true;
            temp.push_back(i);
            findAllCombinations(finalans, visited, i + 1, temp, k - 1, sum - i);
            temp.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        unordered_map<int,bool> visited;

        for(int i = 1; i <= 9; i++) {
            visited[i] = false;
        }

        vector<vector<int>> finalans;
        vector<int> temp;

        findAllCombinations(finalans, visited, 1, temp, k, n);

        return finalans;
    }
};
