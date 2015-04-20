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