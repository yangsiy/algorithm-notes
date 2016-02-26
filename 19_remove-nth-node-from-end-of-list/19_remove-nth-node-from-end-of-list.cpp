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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *tmp_list[n+1];
        int num;
        ListNode *i;
        
        num = 0;
        i = head;
        while (i!=NULL)
        {
            num++;
            tmp_list[num%(n+1)] = i;
            i = i->next;
        }
        if (num-n == 0)
        {
            head = head->next;
        }
        else
        {
            i = tmp_list[(num-n)%(n+1)];
            i->next = i->next->next;
            free(tmp_list[(num-n+1)%(n+1)]);
        }
        
        return head;
        
    }
};