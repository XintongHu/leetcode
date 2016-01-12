class Solution {
public:
    void helper(vector<string> &ip, vector<string> &ans, string pre, string post) {
        int val = stoi(pre);
        if (val <= 255 && to_string(val) == pre) {
            ip.push_back(pre);
            if (post.length() == 0 && ip.size() == 4) {
                string p = "";
                for (int i = 0; i < 4; ++i) {p += ip[i]; if (i != 3) p += ".";}
                ans.push_back(p);
            }
            else {
                if (ip.size() == 4);
                else {
                    for (int i = 1; i <= 3 && i <= post.length(); ++i) helper(ip, ans, post.substr(0, i), post.substr(i));
                }
            }
            ip.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<string> ip;
        if (s.length() > 12 || s.length() < 4) return ans;
        for (int i = 1; i <= 3; ++i) helper(ip, ans, s.substr(0, i), s.substr(i));
        return ans;
    }
};