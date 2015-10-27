class Solution(object):
    def productExceptSelf(self, nums):
        """
            :type nums: List[int]
            :rtype: List[int]
            """
        product = 1
        zeroCnt = 0
        l = len(nums)
        ans = []
        if l == 1:
            return nums
        for i in xrange(l):
            ans.append(0)
            if nums[i] != 0:
                product *= nums[i]
            else:
                zeroCnt += 1
                zeroIndex = i
        if zeroCnt > 1:
            return ans
        elif zeroCnt == 1:
            ans[zeroIndex] = product
        else:
            for i in xrange(len(nums)):
                ans[i] = product/nums[i]
        return ans