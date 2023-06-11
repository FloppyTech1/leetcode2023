// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    struct ListNode* current = &dummy;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            current->next = list1;
            list1 = list1->next;
        }
        else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    current->next = (list1 != NULL) ? list1 : list2;
    return dummy.next;
}

// Explanation
// Initialize a dummy node and a pointer pointing to the dummy node which is used to traverse the lists
// Loop while both lists are not empty
// If list1 value is less than list2 value, append the value of list1 and move to the next element of list1
// Same as list1 but for list2
// All values are being appended to the ListNode dummy, so current points at dummy and then moves forward in dummy and appends inside of dummy
// Advance pointer to the next position in the list
// Add the remaining nodes of either list 1 or 2
// Return dummy.next
