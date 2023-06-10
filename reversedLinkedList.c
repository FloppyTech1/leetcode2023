// Given the head of a singly linked list, reverse the list, and return the reversed list.
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* previous_node = NULL;
    struct ListNode* current_node = head; 
    struct ListNode* next_node = NULL;
    
    while (current_node != NULL) {
        next_node = current_node->next;
        current_node->next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    }
    
    return previous_node;
}

// Explanation
// Initialize three variables for the previous, currrent and next node
// Loop while the current node is not null
// Assign next_node to the node after the current
// Set the next node to the previous node
// Assign previous_node to the current node
// Assign current_node to the next node
// Return the previous_node
