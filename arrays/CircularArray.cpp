class Solution {
public:
    int getNextIndex(const std::vector<int>& nums, float direction, int i) {
        float currentDirection = std::signbit(nums[i]) ? -1 : 1;

        if (currentDirection * direction < 0)
            return -1;

        int n = nums.size();
        int nextIndex = (i + nums[i]) % n;

        if (nextIndex < 0)
            nextIndex += n;

        return nextIndex == i ? -1 : nextIndex;
    }
    bool circularArrayLoop(std::vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); i++) {
            float direction = std::signbit(nums[i]) ? -1 : 1;
            int slow = i;
            int fast = i;

            do {
                slow = getNextIndex(nums, direction, slow);
                fast = getNextIndex(nums, direction, fast);

                if (fast != -1)
                    fast = getNextIndex(nums, direction, fast);

            } while (slow != -1 && fast != -1 && slow != fast);

            if (slow != -1 && slow == fast)
                return true;
        }
        return false;
    }

};
