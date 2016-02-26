class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int len = nums.size();
        int l,r,sum;
        vector<vector<int>> res;
        
        if (len < 4) return res;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < len-3; i++)
        {
            if (i>0 && nums[i]==nums[i-1]) continue;
            if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            for (int j = i+1; j < len-2; j++)
            {
                if (j>i+1 && nums[j]==nums[j-1]) continue;
                l = j + 1;
                r = len - 1;
                if (nums[i]+nums[j]+nums[l]+nums[l+1]>target) break;
                while (l<r)
                {
                    sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target)
                    {
                        vector<int> tmp = {nums[i], nums[j], nums[l], nums[r]};
                        res.push_back(tmp);
                        l++;
                        r--;
                    }
                    else if (sum < target) l++;
                    else r--;
                    while (l>j+1 && l<len-2 && nums[l]==nums[l-1]) l++;
                    while (r<len-1 && r>=j+2 && nums[r]==nums[r+1]) r--;
                }
            }
        }
        
        return res;
        
    }
};