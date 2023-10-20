/*
Structure of the node of the linked list is as
struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/

bool isVowel(char c);
struct Node* arrange(Node *head) {
    
    if (head == nullptr || head -> next == nullptr)
        return head;
    
    Node* vowels = new Node('#'); 
    Node* backup_vowels = vowels;
    
    Node* consonants = new Node('#');
    Node* backup_consonants = consonants;
    
    Node* node = head;
    
    while (node != nullptr)
    {
        char val = node -> data;
        
        if (isVowel(val))
        {
            vowels -> next = node;
            vowels = vowels -> next;
        }
        else {
            
            consonants -> next = node;
            consonants = consonants -> next;
        }
        
        node = node -> next;
    }
    
    vowels -> next = consonants -> next = nullptr;
    vowels -> next = backup_consonants -> next;
    head = backup_vowels -> next;
    
    return head;
}

bool isVowel(char c) {
    
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    
    return false;
}