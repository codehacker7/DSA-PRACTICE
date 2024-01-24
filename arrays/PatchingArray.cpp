class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
       
        int ans = 0;
        int N = nums.size();
        long long sum = 0;
        for(int i = 0; i < N; i++){

            while(sum + 1 < nums[i] && sum < n){
                sum = sum + (sum + 1); // add sum + 1 number
                ans++;
            }
            sum += nums[i];
            if(sum >= n) break;
        }

        while(sum < n){
            sum = sum + (sum + 1);
            ans++;
        }
        return ans;

        
    }
};