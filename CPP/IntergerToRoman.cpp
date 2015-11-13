class Solution {
public:
    string intToRoman(int num) {
        string ans = "", tmp;
        int r, n = 0, i;
        vector<string> roman = {"I", "V", "X", "L", "C", "D", "M"};
        while (num != 0) {
            tmp = "";
            r = num%10;
            num/=10;
            if (r == 9) tmp += (roman[n] + roman[n + 2]);
            else if (r < 9 && r >= 5) {
                tmp += roman[n + 1];
                for (i = 0; i < r - 5; ++i)
                    tmp += roman[n];
            }
            else if (r == 4) tmp += (roman[n] + roman[n + 1]);
            else {
                for (i = 0; i < r; ++i)
                    tmp += roman[n];
            }
            n += 2;
            ans = tmp + ans;
        }
        return ans;
    }
};