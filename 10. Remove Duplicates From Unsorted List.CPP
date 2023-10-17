
/*
The structure of linked list is the following

struct Node {
    int data;
    struct Node *next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution {
public:
    Node* removeDuplicates(Node *head)  {
        
        if (head == nullptr || head -> next == nullptr)
            return head;
        
        unordered_set<int> lookup;
        Node* dummy = new Node(-1);
        Node* backup = dummy;
        
        Node* node = head;
        
        while (node != nullptr)
        {
            int val = node -> data;
            if (lookup.find(val) != lookup.end())
            {
                
            }
            else {
                
                lookup.insert(val);
                dummy -> next = node;
                dummy = dummy -> next;
            }
            
            node = node -> next;
        }
        
        dummy -> next = nullptr;
        head = backup -> next;
        
        return head;
    }
};