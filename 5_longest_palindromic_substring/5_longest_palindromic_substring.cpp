class Solution {
public:
    string longestPalindrome(string s) {
        int f[s.length()+1][s.length()+1];
        int i,j,st,et;
        
        memset(f,0,sizeof(f));
        for (i=0;i<s.length();i++) f[i][i]=1;
        
        for (i=s.length()-1;i>=0;i--)
            for (j=i+1;j<s.length();j++)
            {
                if (s[i]==s[j]&&(f[i+1][j-1]||j-i==1))
                    f[i][j]=f[i+1][j-1]+2;
            }
        
        st=0;
        et=0;
        for (i=0;i<s.length();i++)
            for (j=i+1;j<s.length();j++)
                if (f[i][j]>f[st][et])
                {
                    st=i;
                    et=j;
                }
        string rtn="";
        for (i=st;i<=et;i++) rtn+=s[i];
        return rtn;
    }
};