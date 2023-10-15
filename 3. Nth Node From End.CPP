/* struct Node {
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
    int getNthFromLast(Node* head, int N) {
        
        int output = -1;
        Node* forward_pointer = head;
        Node* previous_pointer = head;
        
        while (N != 0 && forward_pointer  != nullptr) {
            
            forward_pointer = forward_pointer -> next;
            N = N - 1;   
        }
        
        if (N != 0)
            return output;
        
        if (forward_pointer == nullptr)
        {
            output = head -> data;
            return output;
        }
        
        while (forward_pointer -> next != nullptr)
        {
            forward_pointer = forward_pointer -> next;
            previous_pointer = previous_pointer -> next;
        }
            
        output = previous_pointer -> next -> data;
        return output;
    }
};
