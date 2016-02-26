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