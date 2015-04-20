#2 - Add Two Numbers

##Solution

* 遍历两条链表的同时，计算并构建结果链表

###C++

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *root=NULL, *now=NULL, *p=NULL;
        int a,b,k=0;
        while (l1!=NULL||l2!=NULL)
        {
            a=0;
            b=0;
            if (l1!=NULL) a=l1->val;
            if (l2!=NULL) b=l2->val;
            p=new ListNode((a+b+k)%10);
            k=(a+b+k)/10;
            if (root==NULL)
            {
                root=p;
                now=p;
            }
            else
            {
                now->next=p;
                now=p;
            }
            if (l1!=NULL) l1=l1->next;
            if (l2!=NULL) l2=l2->next;
        }
        if (k!=0)
        {
            p=new ListNode(k);
            now->next=p;
        }
        return root;
    }
};
```