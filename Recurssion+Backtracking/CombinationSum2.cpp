class Solution {
private :
    
void help(int i, vector<int> &arr, int n, vector<int> &subSet, vector<vector<int>> &powerSet, int target) {
    //1, 1, 5, 5, 6, 7, 10
    
    if(target == 0) 
    {
        powerSet.push_back(subSet) ;
        return ;
    }    
    if(i >= n) return ;

   
    if(arr[i] <= target){
        subSet.push_back(arr[i]) ;
        help(i + 1, arr, n, subSet, powerSet,target - arr[i]) ;
        subSet.pop_back();
    }
    //if we are not going to take current element and its same as previous element then no point
    while(i + 1 < arr.size() && arr[i] == arr[i + 1]) i++ ;
    
     help(i + 1, arr, n, subSet, powerSet, target) ;

}

    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
    vector<int> subSet ;
    vector<vector<int>> powerSet ;
    int sum = 0;
    int n = candidates.size() ;
    sort(candidates.begin(), candidates.end()) ;

    help(0, candidates, n, subSet, powerSet,target) ;
        
    return powerSet ;
    }
};

/* 
Time Complexity: O(2^N)
Space Complexity: O(N)
*/