class Solution {
public:
    bool helper(int i,int bucketNum,int bucketSum,int reqSum,int K,vector<int>& nums,vector<int>& alreadyPicked){

        if(bucketNum == K+1) return true;

        if(bucketSum == reqSum){
            return helper(0,bucketNum + 1,0,reqSum,K,nums,alreadyPicked);
        }

        if(bucketSum > reqSum){
            return false;
        }

        if(i >= nums.size()) return false;

        if(alreadyPicked[i] == 1){
            return helper(i+1,bucketNum,bucketSum,reqSum,K,nums,alreadyPicked);
        }else{
            bool op1 = false;
            if(bucketSum + nums[i] <= reqSum){
                bucketSum = bucketSum + nums[i];
                alreadyPicked[i] = 1;
                op1 = helper(i+1,bucketNum,bucketSum,reqSum,K,nums,alreadyPicked);
                
                if(op1 == false) {
                     bucketSum = bucketSum - nums[i];
                     alreadyPicked[i] = 0;
                }
            }

           
            bool op2 = helper(i+1,bucketNum,bucketSum,reqSum,K,nums,alreadyPicked);

            return op1 | op2;


        }


    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> alreadyPicked(n,0);

        int sum =0;

        for(int i=0;i<nums.size();i++){
            sum = sum + nums[i];
        }

        if(sum % k != 0) return false;

        int reqSum = sum/k;

       return helper(0,1,0,reqSum,k,nums,alreadyPicked);
        
    }
};