/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; 

*/

class Solution {
public:
    Node* sortList(Node* head) {
        
        Node* node = head;
        
        if (node -> next == nullptr)
            return node;
        
        Node* positive_list = new Node();
        Node* backup_positive_list = positive_list;
        positive_list -> data = -1;
        positive_list -> next = nullptr;
        
        Node* negative_list = new Node();
        Node* backup_negative_list = negative_list;
        negative_list -> data = -1;
        negative_list -> next = nullptr;
        
        while (node != nullptr)
        {
            if (node -> data < 0)
            {
                negative_list -> next = node;
                negative_list = negative_list -> next;
            }
            else {
                
                positive_list -> next = node;
                positive_list = positive_list -> next;
            }
            
            node = node -> next;
        }
        
        negative_list -> next = nullptr;
        positive_list -> next = nullptr;
        
        negative_list = reverse(backup_negative_list -> next);
        
        if (negative_list == nullptr)
            return backup_positive_list -> next;
        
        node = negative_list;
        while (node -> next != nullptr)
            node = node -> next;
            
        node -> next = backup_positive_list -> next;
        head = negative_list;
        
        return head;
    }
    
    Node* reverse(Node* node) {
        
        if (node == nullptr || node -> next == nullptr)
            return node;
        
        Node* previous_node = nullptr;
        Node* current_node = node;
        Node* forward_node = nullptr;
        
        while (current_node != nullptr)
        {
            forward_node = current_node -> next;
            current_node -> next = previous_node;
            
            previous_node = current_node;
            current_node  = forward_node;
        }
        
        return node = previous_node;
    }
};