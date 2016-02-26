#20 - Valid Parentheses

##Solution

* 使用栈进行括号匹配

##C++

```
class Solution {
public:
    int transform(char ch)
    {
        if (ch == '(') return 1;
        if (ch == '[') return 2;
        if (ch == '{') return 3;
        if (ch == ')') return -1;
        if (ch == ']') return -2;
        if (ch == '}') return -3;
    }

    bool isValid(string s) {
        
        int len = s.length();
        int stack[len+1],pos;
        int k;
        
        pos = -1;
        for (int i = 0; i < len; i++)
        {
            k = transform(s[i]);
            if (k > 0)
            {
                pos++;
                stack[pos] = k;
                continue;
            }
            if (pos < 0) return false;
            if (stack[pos]+k != 0) return false;
            pos--;
        }
        
        if (pos >= 0) return false;
        return true;
    }
};
```