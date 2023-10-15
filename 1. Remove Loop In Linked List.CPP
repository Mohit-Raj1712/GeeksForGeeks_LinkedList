/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution {
public:
    void removeLoop(Node* head) {
        
        if (head == nullptr || head -> next == nullptr)
            return;
        
        Node* fast_pointer = head;
        Node* slow_pointer = head;
        
        bool is_loop_present = false;
        
        while (fast_pointer -> next != nullptr && fast_pointer -> next -> next != nullptr)
        {
            fast_pointer = fast_pointer -> next -> next;
            slow_pointer = slow_pointer -> next;
            
            if (fast_pointer == slow_pointer)
            {
                is_loop_present = true;
                break;
            }
        }
        
        if (!is_loop_present)
            return;
    
        
        Node* first_node_of_loop = head;
        
        while (first_node_of_loop != slow_pointer)
        {
            first_node_of_loop = first_node_of_loop -> next;
            slow_pointer = slow_pointer -> next;
        }
            
        Node* node = first_node_of_loop -> next;
        while (node -> next != first_node_of_loop)
            node = node -> next;
            
        node -> next = nullptr;
        
        return;
    }
};

