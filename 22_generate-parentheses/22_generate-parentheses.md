#22 - Generate Parentheses

##Solution

* 递归找出所有可能的括号组合
* work(string s, int l, int r) 中，l为剩余的左括号数，r为剩余的右括号数
* l和r都为0时则是合法组合
* 注意，一定要当前串中左括号的数量大于右括号数量是才可放置右括号
* *vector中使用a.insert(a.end(), b.begin(), b.end()) 可以将b插入到a的后面*

##C++

```
class Solution {
public:
    vector<string> work(string s, int l, int r)
    {
        vector<string> rtn;
        if (l==0 && r==0)
        {
            rtn.push_back(s);
            return rtn;
        }
        if (l>0)
        {
            vector<string> tmp = work(s+"(", l-1, r);
            rtn.insert(rtn.end(), tmp.begin(), tmp.end());
        }
        if (r>l)
        {
            vector<string> tmp = work(s+")", l, r-1);
            rtn.insert(rtn.end(), tmp.begin(), tmp.end());
        }
        return rtn;
    }
    
    vector<string> generateParenthesis(int n) {
        return work("", n, n);
    }
};
```