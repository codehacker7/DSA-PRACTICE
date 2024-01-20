class Solution {
public:
    void combineHelper(int n, int k, int index, vector<int>& current, vector<vector<int>>& result) {
        if (k == 0) {
            result.push_back(current);
            return;
        }
          if(index > n){
            return;
        }
            
        current.push_back(index);
        combineHelper(n, k - 1, index + 1, current, result);
        current.pop_back();
        
        combineHelper(n, k, index + 1, current, result);
            
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        combineHelper(n, k, 1, current, result);
        return result;
        
    }
};