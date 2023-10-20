class Solution{
public:
    ListNode *moveToFront(ListNode *head){
        
        if (head == nullptr || head -> next == nullptr)
            return head;
        
        ListNode* node = head;
        while (node -> next -> next != nullptr)
            node = node -> next;
        
        ListNode* backup = node;
        node = node -> next;
        node -> next = head;
        head = node;
        backup -> next = nullptr;
        
        return head;
    }
};