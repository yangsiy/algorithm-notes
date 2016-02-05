class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string rtn = "";
        int i = 0;
        bool isCommon;
        
        if (strs.size()==0)
            return rtn;
        
        while (1)
        {
            isCommon = 1;
            for (int j = 0; j < strs.size(); j++)
            {
                if (i>=strs[j].length())
                {
                    isCommon = 0;
                    break;
                }
                if (j>0 && strs[j][i]!=strs[j-1][i])
                {
                    isCommon = 0;
                    break;
                }
            }
            if (!isCommon)
                break;
            rtn += strs[0][i];
            i++;
        }
        return rtn;
    }
};