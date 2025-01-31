/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        
        ListNode temp = new ListNode(0);
        ListNode out = temp; 
        if(head ==null){
            return head;
        }
        while(head.next!= null){
            if(head.val==head.next.val)
                head=head.next;
            else{
                temp.next= head;
                temp = temp.next;
                head= head.next;
            }
           

        }
         temp.next= head;
        return out.next;
    }
}