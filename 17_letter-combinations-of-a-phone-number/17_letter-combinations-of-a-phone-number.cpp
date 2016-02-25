class Solution {
public:
    vector<string> letters_list = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void work(vector<string> &a, vector<string> &b, int idx)
    {
        string letters = letters_list[idx-2];
        for (int i = 0; i < letters.length(); i++)
        {
            for (int j = 0; j < b.size(); j++)
            {
                a.push_back(b[j]+letters[i]);
            }
        }
        b.clear();
    }

    vector<string> letterCombinations(string digits) {
        
        vector<string> res1, res2 = {""};
        
        if (digits.length() == 0) return res1;
        
        for (int i = 0; i < digits.length(); i++)
        {
            if (digits[i]<'2' || digits[i]>'9')
            {
                vector<string> tmp = {};
                return tmp;
            }
            
            if (i%2 == 0) work(res1, res2, digits[i]-'0');
            else work(res2, res1, digits[i]-'0');
        }
        
        if (digits.length()%2 == 0) return res2;
        else return res1;
    }
};