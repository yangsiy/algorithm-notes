class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        length = len(nums)
        if length<4:
            return []
        nums.sort()
        rtn = []
        for i in range(0, length-3):
            if i>0 and nums[i]==nums[i-1]:
                continue
            if nums[i]*4>target:
                break
            for j in range(i+1, length-2):
                if j>i+1 and nums[j]==nums[j-1]:
                    continue
                if nums[i]+nums[j]+nums[j+1]+nums[j+2]>target:
                    break
                l = j+1
                r = length-1
                if nums[i]+nums[j]+nums[l]+nums[l+1]>target:
                    break
                while l<r:
                    val = nums[i]+nums[j]+nums[l]+nums[r]
                    if val==target:
                        rtn.append([nums[i], nums[j], nums[l], nums[r]])
                        l = l+1
                        r = r-1
                        while l>j+1 and l<length-2 and nums[l]==nums[l-1]:
                            l = l+1
                        while r<length-1 and r>=j+i+2 and nums[r]==nums[r+1]:
                            r = r-1
                    elif val<target:
                        l = l+1
                    else:
                        r = r-1
        return rtn