/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast= head;

        while(head->next!=NULL){
            if(fast->next==NULL || fast->next->next== NULL){
                if(fast->next!=NULL) return head->next;
                return head;
            } else {
                fast = fast->next->next;
                head = head->next;
            }
        }
        return head;
    }
};