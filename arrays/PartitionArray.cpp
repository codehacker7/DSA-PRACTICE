class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftmax(n);
        vector<int> rightmin(n);

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (nums[i] > maxi) {
                leftmax[i] = nums[i];
                maxi = nums[i];
            } else {
                leftmax[i] = maxi;
            }
        }

        mini = INT_MAX;  // Reset mini to INT_MAX before calculating rightmin

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < mini) {
                rightmin[i] = nums[i];
                mini = nums[i];
            } else {
                rightmin[i] = mini;
            }
        }

        int leftpointer = 0;
        int rightpointer = 1;
        int size = 0;
        int mini2 = INT_MAX;

        while (rightpointer < n) {
            if (leftmax[leftpointer] <= rightmin[rightpointer]) {
                size = leftpointer + 1;
                mini2 = min(size, mini2);
                break;
            }
            leftpointer++;
            rightpointer++;
        }

        return mini2;
    }
};
