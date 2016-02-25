class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int len = nums.size();
        int l,r;
        int best = nums[0] + nums[1] + nums[2], tmp;
        
        if (best == 0) return best;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < len-2; i++)
        {
            l = i+1;
            r = len-1;
            while (l<r)
            {
                tmp = nums[i] + nums[l] + nums[r];
                if (abs(tmp-target) < abs(best-target))
                {
                    best = tmp;
                    if (best-target == 0) break;
                }
                if (tmp < target) l++;
                else r--;
            }
        }
        
        return best;
        
    }
};