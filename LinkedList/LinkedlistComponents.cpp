class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        int components = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            if (numSet.count(temp->val)) {
                components++;
                while (temp != NULL && numSet.count(temp->val)) {
                    temp = temp->next;
                }
            } else {
                temp = temp->next;
            }
        }

        return components;
    }
};
