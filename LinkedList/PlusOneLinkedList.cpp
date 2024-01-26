class Solution
{
    public:
    
    void reverse(Node*& head){
        
    if (head == NULL || head->next == NULL) {
        // Nothing to reverse for an empty list or a list with only one node
        return;
    }

        Node* prev = NULL;
        Node* curr = head;
        
        while(curr != NULL){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            
        }
        head = prev;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        
        int size = 0;
        
        Node* sizehead = head;
        
        while(sizehead != NULL){
            sizehead = sizehead->next;
            size++;
        }
       
        reverse(head);
        Node* reversedHead = head;
        int carry = 1;
        int sum = 0;
        int digit = 0;
        
        while(head != NULL){
            sum = head->data +carry;
            digit = sum%10;
            head->data = digit;
            carry = sum/10;
            head = head->next;
            
        }
        
    
        if(size > 1) // to prevent if the list had single element from getting reversed
            reverse(reversedHead);
            
         if(carry){
            Node* n = new Node(carry);
            n->next = reversedHead;
            reversedHead = n;
            carry = carry/10;
        }
        
        
        return reversedHead;
        
        
        
    }
};