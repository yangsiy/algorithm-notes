class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[300],ans=0,now=-1;
        for (int i=0;i<300;i++) hash[i]=-1;
        for (int i=0;i<s.length();i++)
        {
            if (hash[s[i]]>now) now=hash[s[i]];
            hash[s[i]]=i;
            if (i-now>ans) ans=i-now;
        }
        return ans;
    }
};