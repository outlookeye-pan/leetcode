/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        int sum = 0;
        ListNode *l3_head = NULL;
        ListNode *l3_move = NULL;

        while(l1 != NULL || l2 != NULL)
        {
            sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;
            carry = (sum>=10)?1:0;
            if(l3_head == NULL)
            {
                l3_head = l3_move = new ListNode(sum%10);
            }//L3==null
            else
            {
                l3_move->next = new ListNode(sum%10);
                l3_move = l3_move->next;
            }
            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
        }//while
       
        if(carry > 0)
        {
            l3_move->next = new ListNode(carry);
            l3_move = l3_move->next;
        }
        
        return l3_head;

    }
};