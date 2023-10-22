
/*structure of a node of the linked list is as
struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/

int isLengthEvenOrOdd(struct Node* head) {
    
    int count = 0;
    struct Node* node = head;
    
    while (node != nullptr)
    {
        node = node -> next;
        count += 1;
    }
    
    return count % 2;
}