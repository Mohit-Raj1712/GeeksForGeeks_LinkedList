/* node for linked list:

struct Node {
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
    struct Node* addTwoLists(struct Node* list1, struct Node* list2) {
        
        list1 = reverse(list1);
        list2 = reverse(list2);
        
        Node* output = new Node(-1);
        Node* backup = output;
        
        int carry = 0;
        
        while (list1 != nullptr || list2 != nullptr || carry != 0)
        {
            int num1 = list1 != nullptr ? list1 -> data : 0;
            int num2 = list2 != nullptr ? list2 -> data : 0;
            
            int num = num1 + num2 + carry;
            int sum = num % 10;
            carry = num / 10;
            
            output -> next = new Node(sum);
            output = output -> next;
            
            if (list1 != nullptr)
                list1 = list1 -> next;
            
            if (list2 != nullptr)
                list2 = list2 -> next;
        }
        
        output = reverse(backup -> next);
        return output;
    }
    
    struct Node* reverse(struct Node* head) {
        
        if (head == nullptr || head -> next == nullptr)
            return head;
        
        struct Node* forward = nullptr;
        struct Node* previous = nullptr;
        struct Node* current = head;
        
        while (current != nullptr)
        {
            forward = current -> next;
            current -> next = previous;
            
            previous = current;
            current  = forward;
        }
        
        return head = previous;
    }
};