class Solution {
public:
    bool findNum(vector <int>& nums, int i, int j, int &val)
    {
        int mid;
        while (i<=j)
        {
            mid = (i+j)/2;
            if (nums[mid] == val) return true;
            if (nums[mid] < val) i = mid + 1;
            else j = mid - 1;
        }
        return false;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int len = nums.size();
        int pos,val;
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        
        if (len < 3) return res;
        if (nums[0] > 0) return res;
        if (nums[len-1] < 0) return res;
        
        for (int i = 1; i < len; i++)
        {
            if (nums[i] >= 0)
            {
                pos = i;
                break;
            }
        }
        
        
        for (int i = 0; i <= pos; i++)
        {
            if (i>0 && nums[i] == nums[i-1]) continue;
            for (int j = len-1; j >= pos; j--)
            {
                if (i == j) break;
                if (j<len-1 && nums[j] == nums[j+1]) continue;
                val = -1*(nums[i] + nums[j]);
                if (findNum(nums, i+1, j-1, val))
                {
                    vector<int> ans = {nums[i], val, nums[j]};
                    res.push_back(ans);
                }
            }
        }
        
        return res;
        
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        int l,r;
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        
        if (len < 3) return res;
        if (nums[0] > 0) return res;
        if (nums[len-1] < 0) return res;
        
        for (int i = 0; i < len-2; i++)
        {
            if (i>0 && nums[i] == nums[i-1]) continue;
            l = i + 1;
            r = len - 1;
            while (l<r)
            {
                if (nums[i]+nums[l]+nums[r] == 0)
                {
                    vector<int> tmp = {nums[i], nums[l], nums[r]};
                    res.push_back(tmp);
                    l++;
                    r--;
                }
                else if (nums[i]+nums[l]+nums[r] < 0) l++;
                else r--;
                while (l<r && l>i+1 && nums[l]==nums[l-1]) l++;
                while (l<r && r<len-1 && nums[r] == nums[r+1]) r--;
            }
        }
        
        return res;
    }
};