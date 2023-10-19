//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
public:
    Node* addOne(Node *head)  {
        
        if (head == nullptr)
            return head;
        
        
        Node* node = reverse(head);
        Node* backup = node;
        
        while (node != nullptr)
        {
            if (node -> data < 9) 
            {
                node -> data += 1;
                break;
            }
            
            node -> data = 0;
            node = node -> next;
        }
        
        if (node == nullptr)    
        {
            node = new Node(1);
            node -> next = reverse(backup);
            return node;
        }
    
        return reverse(backup);
    }
    
private:
    Node* reverse(Node* node) {
        
        Node* forward_pointer = nullptr;
        Node* previous_pointer = nullptr;
        Node* current_pointer = node;
        
        while (current_pointer != nullptr)
        {
            forward_pointer = current_pointer -> next;
            current_pointer -> next = previous_pointer;
            
            previous_pointer = current_pointer;
            current_pointer = forward_pointer;
        }
        
        return node = previous_pointer;
    }
};
