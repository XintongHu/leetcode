class Solution(object):
    def maximalSquare(self, matrix):
        """
            :type matrix: List[List[str]]
            :rtype: int
            """
        n = len(matrix)
        if n == 0:
            return 0
        m = len(matrix[0])
        ret = 0
        dp = [[0 for i in xrange(m)] for j in xrange(n)]
        for i in xrange(m):
            val = int(matrix[n - 1][i])
            if val == 1:
                ret = 1
            dp[n - 1][i] = val
        for i in xrange(n):
            val = int(matrix[i][m - 1])
            if val == 1:
                ret = 1
            dp[i][m - 1] = int(matrix[i][m - 1])
        for i in xrange(n - 2, -1, -1):
            for j in xrange(m - 2, -1, -1):
                if int(matrix[i][j]) == 0:
                    dp[i][j] = 0
                else:
                    dp[i][j] = min(dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]) + 1
                    if dp[i][j] > ret:
                        ret = dp[i][j]
        return ret**2