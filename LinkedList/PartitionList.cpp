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
    ListNode* partition(ListNode* head, int x) {

        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* originalListIterator = head;

        ListNode* smallerList = NULL;
        ListNode* largerList = NULL;

        ListNode* smallerListHead = NULL;
        ListNode* largerListHead = NULL;

        while(originalListIterator != NULL){

            if(originalListIterator->val < x){

                if(smallerList == NULL){
                    smallerList = originalListIterator;
                    smallerListHead = originalListIterator;
                }else{
                    smallerList->next = originalListIterator;
                    smallerList = smallerList->next;
                }
            }else{
                 if(largerList == NULL){
                    largerList = originalListIterator;
                    largerListHead = originalListIterator;
                }else{
                    largerList->next = originalListIterator;
                    largerList = largerList->next;
                }
                
            }
            originalListIterator = originalListIterator->next;

        }

        if(smallerList != NULL){

            smallerList->next = largerListHead;
            if(largerList != NULL)
            largerList->next = NULL;
            return smallerListHead;
        }else{
             largerList->next = NULL;
             return largerListHead;

        }


        
    }
};