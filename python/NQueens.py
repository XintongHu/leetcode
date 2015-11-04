class Solution(object):
    def ltostrl(self, l, n):
        strl = []
        for i in xrange(n):
            strl.append(["." for j in xrange(n)])
        for i, j in l:
            strl[i][j] = 'Q'
        for i in xrange(n):
            strl[i] = ''.join(strl[i])
        return strl
    
    
    def solveNQueens(self, n):
        """
            :type n: int
            :rtype: List[List[str]]
            """
        ans = []
        if n < 4:
            if n == 1:
                return [["Q"]]
            else:
                return ans
        for i in xrange(n):
            q = []
            q.append((0, i))
            c = [0 for x in xrange(n)]
            d1 = [0 for x in xrange(2*n - 1)]
            d2 = [0 for x in xrange(2*n - 1)]
            v = [[0 for x in xrange(n)] for y in xrange(n)]
            j = 0
            c[i], d1[i + j], d2[j - i + n - 1] = 1, 1, 1
            j += 1
            while (len(q) > 0):
                if j == n:
                    ans.append(self.ltostrl(q, n))
                    jp, kp = q.pop()
                    c[kp], d1[kp + jp], d2[jp - kp + n - 1] = 0, 0, 0
                    j -= 1
                f = False
                for k in xrange(n):
                    if v[j][k] == 1 or c[k] == 1 or d1[k + j] == 1 or d2[j - k + n - 1] == 1:
                        v[j][k] = 1
                        continue
                    else:
                        v[j][k] = 1
                        f = True
                        q.append((j,k))
                        c[k] = 1
                        d1[k + j] = 1
                        d2[j - k + n - 1] = 1
                        j += 1
                        break
                if f == False:
                    jp, kp = q.pop()
                    c[kp] = 0
                    d1[kp + jp] = 0
                    d2[jp - kp + n - 1] = 0
                    for x in xrange(n):
                        v[j][x] = 0
                    j -= 1
        return ans