# Given the head of a singly linked list, reverse the list, and return the reversed list.

class Solution(object):
    def reverseList(self, head):
        prev_node = None
        curr_node = head
        while curr_node is not None:
            next_node = curr_node.next
            curr_node.next = prev_node
            prev_node = curr_node
            curr_node = next_node
        return prev_node

# Explanation
# Initialize a previous and current node variable
# Loop while the current node is not empty
# Assign next node variable to the node after the current node
# Set the next node to the previous node
# Set the previous node to the current node
# Set the current node to the next node
# Return the last previous node
