//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
public:
    Node *reverse(Node *head, int k) {
       
        if (head == nullptr || head -> next == nullptr)
            return head;
        
        Node* node = head;
        while (k -- != 1)
            node = node -> next;
            
        Node* list1 = head;
        Node* list2 = node -> next;
        node -> next = nullptr;
        
        list1 = reverse_list(list1);
        list2 = reverse_list(list2);
        
        node = list1;
        
        while (node -> next != nullptr)
            node = node -> next;
        
        node -> next = list2;
        
        head = list1;
        return head;
    }
    
private:
    Node* reverse_list(Node* node) {
        
        if (node == nullptr || node -> next == nullptr)
            return node;
        
        Node* forward_node = nullptr;
        Node* previous_node = nullptr;
        Node* current_node = node;
        
        while (current_node != nullptr)
        {
            forward_node = current_node -> next;
            current_node -> next = previous_node;
            
            previous_node = current_node;
            current_node  = forward_node;
        }
        
        node = previous_node;
        return node;
    }
};
