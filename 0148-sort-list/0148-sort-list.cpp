class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newnode = new ListNode(-1);
        ListNode* head = newnode;
        while(list1 != nullptr && list2 != nullptr) {
            if (list1->val > list2->val) {
                ListNode* temp = list2->next;
                list2->next = nullptr;
                newnode->next = list2;
                list2 = temp;
            }
            else {
                ListNode* temp = list1->next;
                list1->next = nullptr;
                newnode->next = list1;
                list1 = temp;
            }
            newnode = newnode->next;
        }
        while(list1 != nullptr) {
            ListNode* temp = list1->next;
            list1->next = nullptr;
            newnode->next = list1;
            list1 = temp;
            newnode = newnode->next;
        }
        while(list2 != nullptr) {
            ListNode* temp = list2->next;
            list2->next = nullptr;
            newnode->next = list2;
            list2 = temp;
            newnode = newnode->next;
        }
        if (head == nullptr) {
            return nullptr;
        }
        return head->next;
    }

    ListNode* findMid(ListNode* &head) {
        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* mid = findMid(head);
        ListNode* leftLL = head;
        ListNode* rightLL = mid->next;
        mid->next = nullptr;

        leftLL = sortList(leftLL);
        rightLL = sortList(rightLL);

        ListNode* merge = mergeTwoLists(leftLL, rightLL);
        return merge;
    }
};