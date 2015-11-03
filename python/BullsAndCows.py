class Solution(object):
    def getHint(self, secret, guess):
        """
            :type secret: str
            :type guess: str
            :rtype: str
            """
        A, B = 0, 0
        dicS = dict.fromkeys(list(secret), 0)
        dicG = dict.fromkeys(list(guess), 0)
        for i, ch in enumerate(secret):
            if ch == guess[i]:
                A += 1
            else:
                dicS[ch] += 1
                dicG[guess[i]] += 1
        for keys in dicS:
            B += min(dict.get(dicG, keys, 0), dicS[keys])
        return "%dA%dB"%(A, B)