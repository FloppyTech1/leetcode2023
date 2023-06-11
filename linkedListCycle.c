// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
// Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list. Otherwise, return false.

bool hasCycle(struct ListNode *head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            return true;
        }
    }
    return false;
}

// Initialize a slow and fast pointer both pointing to the head
// Loop while fast is not null (reached the end of a list which means there's no cycle)
// Move slow by 1 and fast by 2
// If slow equals to fast return true
// Otherwise return false
// If there is a cycle, the fast pointer will eventually catchup to the slow pointer
