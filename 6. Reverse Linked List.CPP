
/* Linked List Node structure:

struct Node {
    int data;
    struct Node *next;
}

*/

// Iterative Implementation

class Solution {
public:
    struct Node* reverseList(struct Node *head) {
        
        if (head == nullptr || head -> next == nullptr)
            return head;
        
        struct Node* current_node = head;
        struct Node* forward_node = nullptr;
        struct Node* previous_node = nullptr;
        
        while (current_node != nullptr)
        {
            forward_node = current_node -> next;
            current_node -> next = previous_node;
            
            previous_node = current_node;
            current_node  = forward_node;
        }
        
        head = previous_node;
        return head;
    }
    
};
    
// Recursive Implementation

class Solution {
public:
    struct Node* reverseList(struct Node* head) {
        
        if (head == nullptr || head -> next == nullptr)
            return head;
        
        struct Node* backup = reverse(head);
        
        head -> next = nullptr;
        head = backup;
        return head;
    }
    
    struct Node* reverse(struct Node* head) {
        
        if (head -> next == nullptr)
            return head;
        
        struct Node* backup = reverse(head -> next);
        head -> next -> next = head;
        
        return backup;
    }
};
    