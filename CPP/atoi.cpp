class Solution {
public:
    int myAtoi(string str) {
        int ans = 0, n = str.length(), pm = 1, start = 0, tmp;
        while (str[start] == ' ') start++;
        if (str[start] == '+') start++;
        else if (str[start] == '-') {pm = -1; start++;}
        while (str[start] == '0') start++;
        for (int i = start; i < n; ++i) {
            if (str[i] > '9' || str[i] < '0') break;
            else {
                tmp = ans * 10 + str[i] - '0';
                if (tmp < ans || (tmp - (str[i] - '0'))/10 != ans) return pm == 1 ? INT_MAX : INT_MIN;
                else ans = tmp;
            }
        }
        return ans * pm;
    }
};