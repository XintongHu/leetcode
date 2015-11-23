class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt[128] = {0}, ans = 0, p = 0;
        for (int i = 0; i < s.length(); ++i) {
            cnt[s[i]]++;
            if (cnt[s[i]] == 2) {
                if (i - p > ans) ans = i - p;
                while (s[p] != s[i]) {
                    cnt[s[p]]--;
                    p++;
                }
                cnt[s[p]]--;
                p++;
            }
        }
        return max(ans, (int)s.length() - p);
    }
};