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