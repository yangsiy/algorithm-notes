class Solution {
public:
    int myAtoi(string str) {
        int i, j, rtn, sign;
        bool startFlag=0;
        string absNum="", maxNum="214748364";
        rtn=0;
        sign=1;
        for (i=0;i<str.length();i++)
        {
            if (!startFlag&&str[i]==' ') continue;
            if (!startFlag)
            {
                startFlag=1;
                if (str[i]=='-') {sign=-1; continue;}
                if (str[i]=='+') {sign=1; continue;}
            }
            if (str[i]>='0'&&str[i]<='9')
            {
                rtn=rtn*10+(str[i]-'0');
                absNum+=str[i];
                continue;
            }
            break;
        }
        i=0;
        while (i<absNum.length()&&absNum[i]=='0') i++;
        if (absNum.length()-i<10) return sign*rtn;
        if (absNum.length()-i>10)
        {
            if (sign==1) rtn=2147483647;
            if (sign==-1) rtn=2147483648;
            return sign*rtn;
        }
        j=0;
        while (j<maxNum.length())
        {
            if (absNum[i+j]<maxNum[j]) return sign*rtn;
            if (absNum[i+j]>maxNum[j])
            {
                if (sign==1) rtn=2147483647;
                if (sign==-1) rtn=2147483648;
                return sign*rtn;
            }
            j++;
        }
        if (sign==1&&absNum[i+j]>'7') rtn=2147483647;
        if (sign==-1&&absNum[i+j]>'8') rtn=2147483648;
        return sign*rtn;
    }
};