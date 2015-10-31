class Solution(object):
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        dic = {1: "One", 2: "Two", 3: "Three", 4: "Four", 5: "Five", 6: "Six",
                7: "Seven", 8: "Eight", 9: "Nine", 10: "Ten",
                11: "Eleven", 12: "Twelve", 13: "Thirteen", 14: "Fourteen",
                15: "Fifteen", 16: "Sixteen", 17: "Seventeen", 18: "Eighteen", 19: "Nineteen",
                20: "Twenty", 30: "Thirty", 40: "Forty", 50: "Fifty",
                60: "Sixty", 70: "Seventy", 80: "Eighty", 90: "Ninety",
                100: "Hundred", 1000: "Thousand", 1000000: "Million",
                1000000000: "Billion"}
        cnt = 1
        ret = ''
        if num == 0:
            return "Zero"
        elif num < 1000:
            l = len(str(num))
            if l == 1:
                ret = dic[num] + ' ' + ret
            elif l == 2:
                try:
                    ret = dic[num] + ' ' + ret
                except KeyError:
                    ret = dic[num / 10 * 10] + ' ' + dic[num % 10] + ' ' + ret
            elif l == 3:
                try:
                    ret = 'One ' + dic[num] + ' ' + ret
                except KeyError:
                    if num % 100 == 0:
                        ret = dic[num / 100] + ' ' + dic[100] + ret
                    else:
                        ret = dic[num / 100] + ' ' + dic[100] + ' ' + self.numberToWords(num % 100) + ret
            return ret.strip()
        else:
            while num > 0:
                remain = num % 1000
                if remain != 0 and cnt != 1:
                    ret = self.numberToWords(remain) + ' ' + dic[cnt] + ' ' + ret
                if remain != 0 and cnt == 1:
                    ret = self.numberToWords(remain) + ' ' + ret
                cnt *= 1000
                num /= 1000
        return ret.strip()

