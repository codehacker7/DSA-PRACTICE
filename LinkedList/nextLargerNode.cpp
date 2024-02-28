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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> linkedlist;

        ListNode* curr = head;

        while(curr != NULL){
            linkedlist.push_back(curr->val);
            curr = curr->next;
        }

        stack<int> st;
        int size = linkedlist.size();
        vector<int> ans(size);

        for(int i = size - 1; i >= 0; i--){

            if(st.empty()){
                ans[i] = 0;
            }else{

                while(!st.empty() && st.top() <= linkedlist[i]){
                    st.pop();
                }
                if(!st.empty())
                     ans[i] = st.top();
                else
                    ans[i] = 0;

            }
              st.push(linkedlist[i]);
        }
        return ans;
        
    }
};