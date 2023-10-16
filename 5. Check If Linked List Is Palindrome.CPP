
/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution{
public:
    bool isPalindrome(Node *head) {
        
        if (head == nullptr || head -> next == nullptr)
            return true;
        
        Node* list1 = head;
        Node* mid   = middle_of_list(head);
        Node* list2 = mid -> next;
        mid -> next = nullptr;
        
        list2 = reverse(list2);
        
        while (list1 != nullptr && list2 != nullptr)
        {
        
            if (list1 -> data != list2 -> data)
                return false;
            
            list1 = list1 -> next;
            list2 = list2 -> next;
        }
        
        return true;
    }
    
private:
    Node* reverse(Node* node) {
        
        if (node == nullptr || node -> next == nullptr)
            return node;
        
        Node* forward_pointer = nullptr;
        Node* previous_pointer = nullptr;
        Node* current_pointer  = node;
        
        while (current_pointer != nullptr)
        {
            forward_pointer = current_pointer -> next;
            current_pointer -> next = previous_pointer;
            
            previous_pointer = current_pointer;
            current_pointer = forward_pointer;
        }
        
        return node = previous_pointer;
    }
    
private:
    Node* middle_of_list(Node* node) {
        
        if (node == nullptr || node -> next == nullptr)
            return node;
        
        Node* fast_pointer = node;
        Node* slow_pointer = node;
        
        while (fast_pointer -> next != nullptr && fast_pointer -> next -> next != nullptr)
        {
            fast_pointer = fast_pointer -> next -> next;
            slow_pointer = slow_pointer -> next;
        }
        
        return slow_pointer;
    }
};
