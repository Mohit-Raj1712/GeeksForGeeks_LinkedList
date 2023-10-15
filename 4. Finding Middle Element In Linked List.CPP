/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */

class Solution{
public:
    int getMiddle(Node *head) {
        
        if (head == nullptr || head -> next == nullptr)
            return head -> data;
        
        Node* fast_pointer = head;
        Node* slow_pointer = head;
        
        while (true)
        {
            if (fast_pointer -> next == nullptr)
                return slow_pointer -> data;
            
            if (fast_pointer -> next -> next == nullptr)
                return slow_pointer -> next -> data;
            
            fast_pointer = fast_pointer -> next -> next;
            slow_pointer = slow_pointer -> next;
        }
        
        return -1;
    }
};