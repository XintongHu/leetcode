class Solution {
public:
    string simplifyPath(string path) {
        vector<string> s;
        string sub, ans = "/";
        int i, j = 0;
        for (i = 1; i < path.size(); ++i) {
            if (path[i] == '/') {
                sub = path.substr(j + 1, i - j);
                j = i;
                if (sub == "./" || sub == "/");
                else if (sub == "../") {if (!s.empty()) s.pop_back();}
                else s.push_back(sub);
            }
            else if (i == path.size() - 1) {
                sub = path.substr(j + 1, i - j) + "/";
                if (sub == "./" || sub == "/");
                else if (sub == "../") {if (!s.empty()) s.pop_back();}
                else s.push_back(sub);
            }
        }
        for (i = 0; i < s.size(); ++i) {
            ans += s[i];
        }
        if (ans.size() > 1) ans.pop_back();
        return ans;
        
    }
};