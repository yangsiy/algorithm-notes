class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> hash;
        for (int i=0;i<numbers.size();i++)
        {
            hash[numbers[i]]=i+1;
        }
        for (int i=0;i<numbers.size();i++)
        {
            if (hash[target-numbers[i]] && i+1!=hash[target-numbers[i]])
            {
                vector<int> rtn;
                rtn.push_back(i+1);
                rtn.push_back(hash[target-numbers[i]]);
                return rtn;
            }
        }
    }
};