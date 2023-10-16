/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.

Node *removeDuplicates(Node *head) {
    
    if (head == nullptr || head -> next == nullptr)
        return head;
    
    Node* node = head;
    
    while (node -> next != nullptr)
    {
        if (node -> next != nullptr && node -> data == node -> next -> data)
            node -> next = node -> next -> next;
        else 
            node = node -> next;
    }
    
    return head;
}