//User function template for C++

/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/

class Solution {
public:
    
    bool detectLoop(Node* head) {
        
        if (head == nullptr || head -> next == nullptr)
            return false;
        
        Node* fast_pointer = head;
        Node* slow_pointer = head;
        
        while (fast_pointer -> next != nullptr && fast_pointer -> next -> next != nullptr)
        {
            fast_pointer = fast_pointer -> next -> next;
            slow_pointer = slow_pointer -> next;
            
            if (fast_pointer == slow_pointer)
                return true;
        }
        
        return false;
    }
};