#7 - Reverse Integer

##Solution

* 简单的将数字翻转输出
* 提前考虑符号
* 注意：翻转后可能溢出，溢出的情况返回0（两个int相加后若溢出，则结果一定为负数）

##C++

```
class Solution {
public:
    int reverse(int x) {
        int sign,rtn=0,i,tmp;
        if (x>=0)
            sign=1;
        else
            sign=-1;
        x=abs(x);
        while (x>0)
        {
            tmp=0;
            for (i=1;i<=10;i++)
            {
                tmp+=rtn;
                if (tmp<0) return 0;
            }
            tmp+=x%10;
            if (tmp<0) return 0;
            rtn=tmp;
            x/=10;
        }
        return rtn*sign;
    }
};
```