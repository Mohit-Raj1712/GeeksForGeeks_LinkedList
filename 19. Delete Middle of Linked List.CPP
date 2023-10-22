

/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

Node* deleteMid(Node* head) {
    
    if (head -> next == nullptr)
        return nullptr;
    
    Node* fast_pointer = head;
    Node* slow_pointer = head;
    Node* previous_node = nullptr;
    
    while (true) {
        
        if (fast_pointer -> next == nullptr)
        {
            Node* temp = previous_node -> next;
            previous_node -> next = slow_pointer -> next;
            delete temp;
            break;
        }
        
        if (fast_pointer -> next -> next == nullptr)
        {
            Node* temp = slow_pointer -> next;
            slow_pointer -> next = slow_pointer -> next -> next;
            delete temp;
            break;
        }
        
        previous_node = slow_pointer;
        fast_pointer = fast_pointer -> next -> next;
        slow_pointer = slow_pointer -> next;
    }
    
    return head;
}