/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.

int count_nodes(Node* head);
int intersectPoint(Node* head1, Node* head2) {
    
    int N = count_nodes(head1);
    int M = count_nodes(head2);
    
    Node* node1 = head1;
    Node* node2 = head2;
    
    if (N > M)
    {
        while (N != M)
        {
            node1 = node1 -> next;
            N --;
        }
    }
    
    else {
        
        while (N != M)
        {
            node2 = node2 -> next;
            M --;
        }
    }
    
    while (N -- != 0)
    {
        if (node1 == node2)
            return node1 -> data;
        
        node1 = node1 -> next;
        node2 = node2 -> next;
    }
    
    return -1;
}

int count_nodes(Node* head) {
    
    if (head == nullptr)
        return 0;
        
    return 1 + count_nodes(head -> next);
}
