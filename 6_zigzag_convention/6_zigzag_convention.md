#6 - ZigZag Convention

##Solution

* 按行寻找并输出结果，找规律
* 首行和末行的下标每次前进nRows*2-2
* 中间行的下标一次前进(nRows-i-1)\*2，一次前进i\*2
* 注意：nRows=1时需要特殊处理（因为nRows*2-2=0）

##C++

```
class Solution {
public:
    string convert(string s, int nRows) {
        int i,k,len;
        string rtn="";
        len=s.length();
        for (i=0;i<nRows;i++)
        {
            k=i;
            if (i==0||i==nRows-1)
            {
                while (k<len)
                {
                    rtn+=s[k];
                    k+=nRows*2-2;
                    if (nRows==1) k++;
                }
            }
            else
            {
                while (k<len)
                {
                    rtn+=s[k];
                    k+=(nRows-i-1)*2;
                    if (k<len)
                    {
                        rtn+=s[k];
                        k+=i*2;
                    }
                }
            }
        }
        return rtn;
    }
};
```