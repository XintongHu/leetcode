class Solution(object):
    def countDigitOne(self, n):
        """
            :type n: int
            :rtype: int
            """
        if n <= 0:
            return 0
        if n < 10:
            return 1
        l = 10 ** (len(str(n)) - 1)
        d, m = divmod(n, l)
        if d == 1:
            return m + 1 + d * self.countDigitOne(l - 1) + self.countDigitOne(m)
        else:
        return l + d * self.countDigitOne(l - 1) + self.countDigitOne(m)