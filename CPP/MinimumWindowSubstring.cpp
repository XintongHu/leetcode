class Solution {
public:
    string minWindow(string s, string t) {
        int i, ch, tmp, sz = t.size(), j;
        int p = 0, cnt = 0, cnt_t;
        int ans = INT_MAX;
        string str;
        int rep[128] = {0}, rep_t[128] = {0};
        if (sz > s.size()) return "";
        for (i = 0; i < sz; ++i) {
            ch = (int)t[i];
            rep[ch]++;
        }
        for (i = 0; i < 128; ++i) {if (rep[i] != 0) cnt++;}
        cnt_t = 0;
        for (i = 0; i < s.size(); ++i) {
            ch = (int)s[i];
            if (rep[ch] != 0) {
                if (++rep_t[ch] == rep[ch]) cnt_t++;
                if (cnt_t == cnt) {
                    while (rep[s[p]] == 0 || (rep[s[p]] != 0 && --rep_t[s[p]] >= rep[s[p]])) p++;
                    cnt_t--;
                    if (i - p + 1< ans) {
                        ans = i - p + 1;
                        str = s.substr(p, ans);
                    }
                    while (rep[s[++p]] == 0);
                }
            }
        }
        return ans == INT_MAX ? "" : str;
    }
};