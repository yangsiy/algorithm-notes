#19 - Remove Nth Node From End of List

##Solution

* In order to do this in one pass.
* 使用一个长度为n+1的指针数组（循环）保存访问过的最后n+1个节点指针
* 最后取出倒数第n+1个指针，指向第n-1个即可
* 记得释放掉第n个点的内存空间

##C++

```
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
```