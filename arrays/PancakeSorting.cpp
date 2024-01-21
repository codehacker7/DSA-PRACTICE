class Solution {
public:
    int find(vector<int>& arr,int end){

        for(int i=0;i<arr.size();i++){
            if(arr[i] == end){
                return i;
            }
        }
        return -1;
    }
    void flip(vector<int>& arr,int index){
        reverse(arr.begin(),arr.begin()+index+1);
    }

    vector<int> pancakeSort(vector<int>& arr) {

        int end = arr.size();
        vector<int> ans;

        while(end != 1){
            int index = find(arr,end);
            flip(arr,index);
            flip(arr,end-1);
            ans.push_back(index + 1);
            ans.push_back(end);
            end--;
        }
        return ans;
        
    }
};