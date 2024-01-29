/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        ListNode* curr = head;

        while(curr != NULL){
            curr = curr->next;
            length++;
        }

        int n = length / k;
        int r = length % k;
        
        ListNode* node = head;
        ListNode* prev = NULL;
        vector<ListNode*> parts(k,NULL);

        for(int i = 0; node && i < k;i++){
            parts[i] = node;

            for(int j = 0; j < n + (r > 0) ;j++){ 
                prev = node;
                node = node->next;
            }
            prev->next = nullptr;
            r--;
        }
        return parts;  
    }
};