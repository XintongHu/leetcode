class Solution {
public:
    int maxProduct(vector<string>& words) {
        int l = words.size(), i, j;
        int ans = 0,len;
        vector<int> intW(l, 0);
        if (l < 2) return 0;
        for (i = 0; i < l; ++i) {
            for (j = 0; j < words[i].length(); ++j) {
                intW[i] |= (1<<(words[i][j] - 'a'));
            }
        }
        for (i = 0; i < l - 1; ++i) {
            for (j = i + 1; j < l; ++j) {
                if((intW[i]&intW[j]) == 0) {
                    len = words[i].length() * words[j].length();
                    if (len > ans) ans = len;
                }
            }
        }
        return ans;
    }
};