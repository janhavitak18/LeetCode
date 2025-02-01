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
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode res = sort(lists,0,lists.length-1);
        return res;
    }
    private ListNode sort(ListNode[] nums, int l, int r){
        if( l == r)return nums[l];
        if(l<r){
            int mid = l+(r-l)/2;
            ListNode one = sort(nums,l,mid);
            ListNode two = sort(nums,mid+1,r);
            ListNode res = merge(one,two);
            return res;
        }
        else return null;
    }
    private ListNode merge(ListNode one, ListNode two){
        if(one == null)return two;
        if(two == null)return one;
        if(one.val<two.val){
            one.next = merge(one.next,two);
            return one;
        }else{
            two.next = merge(one,two.next);
            return two;
        }
    }
}