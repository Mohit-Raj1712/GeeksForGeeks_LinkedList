/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
public:
    Node* segregate(Node *head) {
        
        if (head == nullptr || head -> next == nullptr)
            return head;
        
        Node* zero_pointer = new Node(-1); Node* zero_backup = zero_pointer;
        Node* one_pointer  = new Node(-1); Node* one_backup  = one_pointer;
        Node* two_pointer  = new Node(-1); Node* two_backup  = two_pointer;
        
        
        Node* node = head;
        
        while (node != nullptr)
        {
            if (node -> data == 0)
            {
                zero_pointer -> next = node;
                zero_pointer = zero_pointer -> next;
            }
            
            else if (node -> data == 1)
            {
                one_pointer -> next = node;
                one_pointer = one_pointer -> next;
            }
            
            else {
                
                two_pointer -> next = node;
                two_pointer = two_pointer -> next;
            }
            
            node = node -> next;
        }
        
        zero_pointer -> next = one_pointer -> next = two_pointer -> next = nullptr;
        one_pointer  -> next = two_backup -> next;
        zero_pointer -> next = one_backup -> next;
        
        Node* output = zero_backup -> next;
        return output;
    }
};