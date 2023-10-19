/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
public:
    
    Node* mergeSort(Node* head) {
        
        if(head == NULL || head -> next == NULL)
        return head;
    
        struct Node* list1 = head;
    
        struct Node* mid = midNode(head);
        struct Node* list2 = mid -> next;
        mid -> next = NULL;
    
    
        return sort(mergeSort(list1), mergeSort(list2));
    }
    
    struct Node* midNode(struct Node* head) {
    
    struct Node* fast_pointer = head;
    struct Node* slow_pointer = head;
    
    while(fast_pointer -> next != NULL && fast_pointer -> next -> next != NULL) 
    {
        
        fast_pointer = fast_pointer -> next -> next;
        slow_pointer = slow_pointer -> next;
    }
    
    return slow_pointer;
    }
    
    struct Node* sort(struct Node* list1, struct Node* list2) {
    
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    
    struct Node* dummy = (struct Node*) malloc (sizeof(struct Node));
    dummy -> data = -1;
    dummy -> next = NULL;
    
    struct Node* backup = dummy;
    
    while(list1 != NULL && list2 != NULL)
    {
        if(list1 -> data < list2 -> data) 
        {
            dummy -> next = list1;
            list1 = list1 -> next;
            
        }
        else {
            dummy -> next = list2;
            list2 = list2 -> next;
        }
        
        dummy = dummy -> next;
    }
    
    dummy -> next = list1 != NULL ? list1 : list2;
    
    return backup -> next;
}
};