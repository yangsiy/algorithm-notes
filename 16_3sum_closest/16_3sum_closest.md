#16 - 3Sum Closest

##Solution

* 数列排序
* 从数列开头枚举第一个数
* 第一个数右边的数列，用两个指针l和r分别指向头尾，表示后两个数
* 若三个数之和等于target，则为结果
* 若三个数之和大于target，则r--
* 若三个数之和小于target，则l++

##C++

```
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
```