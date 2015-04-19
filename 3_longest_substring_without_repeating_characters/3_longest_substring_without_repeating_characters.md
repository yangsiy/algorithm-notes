#3 - Longest Substring Without Repeating Characters

##Solution

* 记录当前字串的起始点now
* hash[255]记录每个字符上一次在串中出现的位置
* 遍历整个串，每次更新now和hash，并计算当前串的长度
* 取串长度的最优值

##C++

```
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
```