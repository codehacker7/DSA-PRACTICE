class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int maxi = INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     int result = 1;
        //      for(int j = i;j<nums.size();j++){
                 
        //         result = result * nums[j];
        //          maxi = max(maxi,result);
        //      }

        // }
       
        // return maxi;

        int maxi = INT_MIN;

        int prefix = 1;
        int suffix = 1;
        for(int i=0;i<nums.size();i++){
            prefix = prefix * nums[i];
            maxi = max(maxi,prefix);

            if(prefix == 0) prefix = 1;
            
        }

          for(int j=nums.size()-1;j>=0;j--){
            suffix = suffix * nums[j];
            maxi = max(maxi,suffix);

            if(suffix == 0) suffix = 1;
            
        }

        return maxi;


      
    }
};