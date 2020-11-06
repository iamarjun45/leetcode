class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(temp1 != NULL || temp2 != NULL){
            int sum = carry;
            if(temp1) {
                sum = sum + temp1->val;
                temp1 = temp1->next;
            }
            if(temp2) {
                sum = sum + temp2->val;
                temp2 = temp2->next;
            }
            carry = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);
            if(head) tail->next = newNode;
            else head = newNode;
            tail = newNode;
        }
        if(carry) tail->next = new ListNode(carry);
        return head;
    }
};
