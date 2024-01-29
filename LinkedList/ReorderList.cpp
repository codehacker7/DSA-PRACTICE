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

    ListNode* reverse(ListNode* &head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        int length = 0;
        ListNode* curr = head;

        while(curr != NULL){
            curr = curr->next;
            length++;
        }
        if(length <= 2) return;
        
        curr = head;

        int counter = 0;
        int numberofReverse = length - 2;

        while(counter != numberofReverse){
             ListNode* next = curr->next;
             ListNode* prev = reverse(next);
             curr->next = prev;
             curr = curr->next;
             counter++;
        }


        
    }
};