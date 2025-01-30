class Solution {
    public ListNode removeElements(ListNode head, int val) {
        if (head == null) {
            return null;
        }

        ListNode temp = new ListNode(); // Create a dummy node
        ListNode out = temp; // Save the starting point of the modified list
        
        while (head != null) {
            if (head.val == val) {
                // Skip the node if it matches the value
                head = head.next;
            } else {
                temp.next = head;  // Add the current node to the result list
                temp = temp.next;  // Move temp to the next node
                head = head.next;  // Move to the next node in the original list
            }
        }
        
        temp.next = null;  // End the list
        return out.next;   // Return the modified list starting from the second node
    }
}