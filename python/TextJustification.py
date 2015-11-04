class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
            :type words: List[str]
            :type maxWidth: int
            :rtype: List[str]
            """
        def dealWithline(line, maxWidth, sumLen):
            if len(line) == 1:
                return line[0] + ' ' * (maxWidth - sumLen)
            else:
                ret = ''
                n, v = divmod(maxWidth - sumLen, len(line) - 1)
                for i in xrange(len(line) - 1):
                    ret += (line[i] + (n + 1) * ' ')
                    if i < v:
                        ret += ' '
                ret += (line[len(line) - 1])
                return ret
        line = []
        ans = []
        sumLen = 0
        i = 0
        while i < len(words):
            w = words[i]
            sumLen += len(w)
            if sumLen == maxWidth:
                line.append(w)
                ans.append(dealWithline(line, maxWidth, sumLen))
                sumLen = 0
                line = []
            elif sumLen < maxWidth:
                line.append(w)
                sumLen += 1
            else:
                i -= 1
                sumLen -= len(w)
                if len(line) >= 1:
                    sumLen -= 1
                ans.append(dealWithline(line, maxWidth, sumLen))
                sumLen = 0
                line = []
            i += 1
        if len(line) != 0:
            line = [' '.join(line)]
            ans.append(dealWithline(line, maxWidth, len(line[0])))
        return ans