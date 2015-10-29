class Solution(object):
    def bs(self, nums, p, q, target, ret):
        if q - p <= 3:
            for i in xrange(p, q + 1):
                if nums[i] == target:
                    if i < ret[0]:
                        ret[0] = i
                    if i > ret[1]:
                        ret[1] = i
            return
        else:
            mid = (p + q)/2
            if nums[mid] > target:
                return self.bs(nums, p, mid - 1, target, ret)
            elif nums[mid] < target:
                return self.bs(nums, mid + 1, q, target, ret)
            else:
                if mid < ret[0]:
                    ret[0] = mid
                if mid > ret[1]:
                    ret[1] = mid
                self.bs(nums, p, mid - 1, target, ret)
                self.bs(nums, mid + 1, q, target, ret)
                return

def searchRange(self, nums, target):
    """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
            l = len(nums)
                if l == 0:
                    return [-1, -1]
                        ret = [l, -1]
                            self.bs(nums, 0, l - 1, target, ret)
                                if ret[0] == l:
                                    return [-1, -1]
                                        return ret
